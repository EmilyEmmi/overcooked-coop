-- name: Overcooked! (WIP)
-- description: Collab with WBMarioo and denpakei32 for Blocky's gamemode competition.
-- pausable: false
-- category: gamemode
-- incompatible: gamemode

selectedItem = nil
selectedCounter = nil

pending_orders = {}

GAME_STATE_LEVEL_SELECT = 0
GAME_STATE_LOADING = 1
GAME_STATE_PLAYING = 2
GAME_STATE_END = 3

BASE_TEMPO = 0
BASE_MULTI = 1

gGlobalSyncTable.gameState = GAME_STATE_LEVEL_SELECT
gGlobalSyncTable.ocLevel = 0
gGlobalSyncTable.score = 0
gGlobalSyncTable.timeLeft = 0
gGlobalSyncTable.tipMulti = 1
gGlobalSyncTable.servedOrders = 0
local subTimer = 0

gOvercookedExtraStates = {}
for i=0,MAX_PLAYERS-1 do
    gOvercookedExtraStates[i] = {}
    local c = gOvercookedExtraStates[i]
    local sMario = gPlayerSyncTable[i]
    sMario.cutTimer = 0
    sMario.kitchen = 0
    c.cutAnimTimer = 0
end

GRAB_SOUND = SOUND_GENERAL_ELEVATOR_MOVE_2

function update()
    if gGlobalSyncTable.gameState == GAME_STATE_LEVEL_SELECT then
        local np = gNetworkPlayers[0]
        if np.currLevelNum ~= LEVEL_CASTLE_GROUNDS and np.currAreaSyncValid then
            warp_to_level(LEVEL_CASTLE_GROUNDS, 1, 0)
        end
    elseif gGlobalSyncTable.gameState == GAME_STATE_PLAYING then
        local lData = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel]
        local np = gNetworkPlayers[0]
        if np.currLevelNum ~= lData.level and np.currAreaSyncValid then
            warp_to_level(lData.level, 1, 0)
        end
        
        local newTempo = sequence_player_get_tempo(SEQ_PLAYER_LEVEL)
        if newTempo ~= BASE_TEMPO * BASE_MULTI then
            BASE_TEMPO = newTempo
        end
        if gGlobalSyncTable.timeLeft <= 30 then
            BASE_MULTI = 1.5
            sequence_player_set_transposition(SEQ_PLAYER_LEVEL, 3)
        else
            BASE_MULTI = 1
            sequence_player_set_transposition(SEQ_PLAYER_LEVEL, 2)
        end
        sequence_player_set_tempo(SEQ_PLAYER_LEVEL, BASE_TEMPO * BASE_MULTI)

        subTimer = subTimer + 1
        if subTimer >= 30 then
            subTimer = 0
            if gGlobalSyncTable.timeLeft ~= 0 then
                if network_is_server() then
                    gGlobalSyncTable.timeLeft = gGlobalSyncTable.timeLeft - 1
                    if gGlobalSyncTable.timeLeft == 0 then
                        gGlobalSyncTable.timeLeft = 10
                        gGlobalSyncTable.gameState = GAME_STATE_END
                    end
                else
                    set_without_sync(gGlobalSyncTable, "timeLeft", gGlobalSyncTable.timeLeft - 1)
                end
            end
        end

        for i, pending_data in ipairs(pending_orders) do
            pending_data.prevTime = pending_data.time
            pending_data.time = pending_data.time - 1
            if pending_data.time <= 0 then
                pending_data.time = pending_data.maxTime
                play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource)
                if network_is_server() then
                    gGlobalSyncTable.tipMulti = 1
                    gGlobalSyncTable.score = gGlobalSyncTable.score - 30
                end
            end
        end

        -- automatically add orders
        if network_is_server() then
            expected_orders = math.max(2 + (lData.totalTime - gGlobalSyncTable.timeLeft) // 10, 2)
            while #pending_orders < 5 and #pending_orders + gGlobalSyncTable.servedOrders < expected_orders do
                local orderID = lData.orders[math.random(1, #lData.orders)]
                network_send_include_self(true, {id = PACKET_ORDER, orderID = orderID})
            end
        end
    elseif gGlobalSyncTable.gameState == GAME_STATE_END then
        pending_orders = {}
        subTimer = subTimer + 1
        if subTimer >= 30 then
            subTimer = 0
            if network_is_server() then
                gGlobalSyncTable.timeLeft = gGlobalSyncTable.timeLeft - 1
                if gGlobalSyncTable.timeLeft == 0 then
                    gGlobalSyncTable.gameState = GAME_STATE_LEVEL_SELECT
                end
            else
                set_without_sync(gGlobalSyncTable, "timeLeft", gGlobalSyncTable.timeLeft - 1)
            end
        end
    end
end
hook_event(HOOK_UPDATE, update)

local didInitialJoin = false
function on_sync_valid()
    for i=0,MAX_PLAYERS-1 do
        spawn_non_sync_object(id_bhvKnife, E_MODEL_KNIFE, 0, 0, 0, function(o)
            o.globalPlayerIndex = i
        end)
    end

    if not (network_is_server() or didInitialJoin) then
        didInitialJoin = true
        pending_orders = {}
        network_send_to(1, true, {
            id = PACKET_REQUEST_ORDERS,
            from = network_global_index_from_local(0),
        })
    end
end
hook_event(HOOK_ON_SYNC_VALID, on_sync_valid)

---@param m MarioState
function mario_update(m)
    if m.prevAction == ACT_HOLD_WALKING and m.action ~= ACT_HOLD_WALKING then
        m.marioBodyState.allowPartRotation = 0
    end

    local c = gOvercookedExtraStates[m.playerIndex]
    local sMario = gPlayerSyncTable[m.playerIndex]
    if sMario.cutTimer ~= 0 then
        set_mario_animation(m, CHAR_ANIM_FIRST_PUNCH)
        set_anim_to_frame(m, c.cutAnimTimer)
        c.cutAnimTimer = (c.cutAnimTimer + 1) % 6
        if c.cutAnimTimer == 1 then
            play_sound(SOUND_ACTION_UNK55, m.marioObj.header.gfx.cameraToObject)
        end
        set_without_sync(sMario, "cutTimer", sMario.cutTimer - 1)
        if sMario.cutTimer == 0 and m.playerIndex == 0 then
            sync_value(sMario, "cutTimer")
        end
    else
        c.cutAnimTimer = 0
    end
    
    -- move romhack cam up
    if m.playerIndex == 0 and m.area.camera and m.area.camera.mode == CAMERA_MODE_ROM_HACK
    and set_cam_angle(0) ~= CAM_ANGLE_MARIO then
        m.statusForCamera.pos.y = m.statusForCamera.pos.y + 250
    end
end
hook_event(HOOK_MARIO_UPDATE, mario_update)

local INVALID_GRAB_ACTION = {
    [ACT_DIVE_SLIDE] = 1,
}

function before_mario_update(m)
    if m.playerIndex ~= 0 then return end

    local sMario = gPlayerSyncTable[0]

    -- get selected item and counter
    local grabPos = {x = m.pos.x, y = m.pos.y, z = m.pos.z}
    grabPos.x = grabPos.x + sins(m.faceAngle.y) * 35
    grabPos.z = grabPos.z + coss(m.faceAngle.y) * 35
    --spawn_non_sync_object(id_bhvSparkleSpawn, E_MODEL_NONE, grabPos.x, grabPos.y, grabPos.z, nil)
    local dist = 0
    selectedItem, dist = nearest_behavior_id_from_pos_with_condition(grabPos, id_bhvIngredient, function(o)
        local counter = o.usingObj
        return o.oHeldState == HELD_FREE and o.oPlateAppearTimer == 0 and o.oRespawnTimer == 0
        and (o.parentObj == nil or o.parentObj == o) and (counter == nil)
    end)
    selectedCounter = nil
    if selectedItem == nil or dist > 100 then
        selectedItem = nil
        selectedCounter, dist = nearest_behavior_id_from_pos_with_condition(grabPos, id_bhvCounter, function(counter)
            return true -- No condition yet
        end)
        if selectedCounter == nil or dist > 100 then
            selectedCounter = nil
        else
            selectedItem = selectedCounter.usingObj
        end
    end

    -- might be changed
    if selectedCounter or selectedItem then
        local o = selectedCounter or selectedItem
        local pos = {x = o.oPosX, y = o.oPosY, z = o.oPosZ}
        local size = 45
        if o == selectedCounter then
            pos.y = pos.y + (COUNTER_HEIGHT[o.oBehParams2ndByte] or 34) * o.header.gfx.scale.y
            size = 30
        end
        spawn_non_sync_object(id_bhvSparkle, E_MODEL_SPARKLES, pos.x, pos.y, pos.z, function(sparkle)
            obj_translate_xyz_random(sparkle, size);
            obj_scale_random(sparkle, 1.0, 0.0);
        end)
    end

    if m.controller.buttonPressed & B_BUTTON ~= 0 and not INVALID_GRAB_ACTION[m.action] then
        if m.heldObj then
            local o = m.heldObj
            
            local placed, stillHolding = attempt_item_place(o, m, selectedItem, selectedCounter, true)
            if not stillHolding then
                mario_drop_held_object(m)
            end
            if placed or not stillHolding then
                play_sound(GRAB_SOUND, gGlobalSoundSource) -- TODO: pick better sfx
            end
            
            m.controller.buttonPressed = m.controller.buttonPressed &~ B_BUTTON

            if not m.heldObj then
                m.marioBodyState.allowPartRotation = 0
                m.prevAction = m.action
                if m.action & ACT_FLAG_CONTROL_JUMP_HEIGHT ~= 0 then
                    m.action = ACT_JUMP
                elseif m.action & ACT_FLAG_AIR ~= 0 then
                    m.action = ACT_FREEFALL
                elseif m.action & ACT_FLAG_MOVING ~= 0 then
                    m.action = ACT_WALKING
                else
                    m.action = ACT_IDLE
                end
            end
        else
            local counter = selectedCounter
            local o = selectedItem
            local valid = true
            if counter then
                if counter.oBehParams2ndByte == COUNTER_TYPE_CUT then
                    if o and o.oCutOrCookTimer ~= 0 and ITEM_DATA[o.oBehParams].cut then
                        valid = false
                    end
                elseif counter.oBehParams2ndByte == COUNTER_TYPE_INGREDIENT then
                    if valid and not o then
                        -- opening animation
                        counter.oOvercookTimer = 1
                        if counter.oSyncID ~= 0 then
                            network_send_object(counter, true)
                        end

                        -- Create new ingredient and grab
                        o = spawn_sync_object(id_bhvIngredient, E_MODEL_NONE, m.pos.x, m.pos.y, m.pos.z, function(o)
                            o.oBehParams = counter.oBehParams & 0xFF
                        end)
                    end
                end
            end

            if o and valid then
                play_sound(GRAB_SOUND, gGlobalSoundSource)
                m.usedObj = o
                m.marioBodyState.grabPos = GRAB_POS_LIGHT_OBJ
                o.oInteractType = INTERACT_GRABBABLE
                o.oFlags = o.oFlags | OBJ_FLAG_HOLDABLE
                mario_grab_used_object(m)
                if m.action ~= ACT_DIVE then
                    m.prevAction = m.action
                    if m.action & ACT_FLAG_CONTROL_JUMP_HEIGHT ~= 0 then
                        m.action = ACT_HOLD_JUMP
                    elseif m.action & ACT_FLAG_AIR ~= 0 then
                        m.action = ACT_HOLD_FREEFALL
                    else
                        m.action = ACT_HOLD_IDLE
                    end
                end

                m.controller.buttonPressed = m.controller.buttonPressed &~ B_BUTTON
            end
        end
    elseif m.controller.buttonPressed & X_BUTTON ~= 0 and m.heldObj and (m.action & ACT_FLAG_THROWING == 0) then
        local iData = ITEM_DATA[m.heldObj.oBehParams] or ITEM_DATA[0]
        if obj_has_behavior_id(m.heldObj, id_bhvIngredient) == 0 or not (iData.noThrow or m.heldObj.oContentCount ~= 0) then
            m.marioBodyState.allowPartRotation = 0
            m.prevAction = m.action
            if m.action & ACT_FLAG_AIR ~= 0 then
                m.action = ACT_AIR_THROW
            else
                m.action = ACT_THROWING
            end
        end
    elseif m.controller.buttonDown & X_BUTTON ~= 0 and (not m.heldObj)
    and selectedCounter and selectedCounter.oBehParams2ndByte == COUNTER_TYPE_CUT then
        local counter = selectedCounter
        local o = counter.usingObj
        local iData = (o and ITEM_DATA[o.oBehParams]) or ITEM_DATA[0]

        if o and o ~= counter and iData and iData.cut then
            o.oCutOrCookTimer = o.oCutOrCookTimer + 1
            sMario.cutTimer = 5
            if o.oCutOrCookTimer >= 30 then
                o.oBehParams = ITEM_DATA[o.oBehParams].cut
                network_send_object(o, true)
                o.oCutOrCookTimer = 0
            end
        end
    end
end
hook_event(HOOK_BEFORE_MARIO_UPDATE, before_mario_update)

-- Code I wrote from Extra Characters (birdo)
--- @param m MarioState
function act_custom_hold_walking(m)
    local startYaw = m.faceAngle.y

    if m.heldObj and m.heldObj.behavior == get_behavior_from_id(id_bhvJumpingBox) then
        return set_mario_action(m, ACT_CRAZY_BOX_BOUNCE, 0)
    end

    if (m.marioObj.oInteractStatus & INT_STATUS_MARIO_DROP_OBJECT) ~= 0 then
        return drop_and_set_mario_action(m, ACT_WALKING, 0)
    end

    if (should_begin_sliding(m)) ~= 0 then
        return set_mario_action(m, ACT_HOLD_BEGIN_SLIDING, 0)
    end

    if (m.input & INPUT_B_PRESSED) ~= 0 then
        return set_mario_action(m, ACT_THROWING, 0)
    end

    if (m.input & INPUT_A_PRESSED) ~= 0 then
        return set_jumping_action(m, ACT_HOLD_JUMP, 0)
    end

    if (m.input & INPUT_ZERO_MOVEMENT) ~= 0 then
        return set_mario_action(m, ACT_HOLD_DECELERATING, 0)
    end

    if (m.input & INPUT_Z_PRESSED) ~= 0 then
        return drop_and_set_mario_action(m, ACT_CROUCH_SLIDE, 0)
    end

    update_walking_speed(m) -- normal walking speed

    local result = perform_ground_step(m)
    if result == GROUND_STEP_LEFT_GROUND then
        set_mario_action(m, ACT_HOLD_FREEFALL, 0)
    elseif result == GROUND_STEP_HIT_WALL then
        if (m.forwardVel > 16) then
            mario_set_forward_vel(m, 16)
        end
    end

    -- for the animation, temporarily read mario's speed as lower so it looks less goofy
    local prevForwardVel = m.forwardVel
    local prevMag = m.intendedMag
    m.forwardVel = m.forwardVel * 0.6
    m.intendedMag = m.intendedMag * 0.6
    anim_and_audio_for_hold_walk(m)
    m.forwardVel = prevForwardVel
    m.intendedMag = prevMag

    -- tilt body
    local dYaw = m.faceAngle.y - startYaw
    local val02 = -(dYaw * m.forwardVel / 12)
    local val00 = (m.forwardVel * 170)

    val02 = math.clamp(val02, -0x1555, 0x1555)
    val00 = math.clamp(val00, 0x0, 0x1555)

    m.marioBodyState.allowPartRotation = 1
    m.marioBodyState.torsoAngle.z = approach_s32(m.marioBodyState.torsoAngle.z, val02, 0x400, 0x400)
    m.marioBodyState.torsoAngle.x = approach_s32(m.marioBodyState.torsoAngle.x, val00, 0x400, 0x400)

    if (0.4 * m.intendedMag - m.forwardVel > 10) then
        set_mario_particle_flags(m, PARTICLE_DUST, 0)
    end

    return 0
end

hook_mario_action(ACT_HOLD_WALKING, act_custom_hold_walking)

-- keep timed things in sync
function on_time_left_change(tag, oldVal, newVal)
    if oldVal == newVal or oldVal == nil or newVal == nil then return end
    if network_is_server() then return end

    local difference = newVal - oldVal
    for i, pending_data in ipairs(pending_orders) do
        pending_data.time = math.clamp(pending_data.time + difference * 30, 1, pending_data.maxTime)
    end
end
hook_on_sync_table_change(gGlobalSyncTable, "timeLeft", "timeLeft", on_time_left_change)

function ingredient_command(msg)
    local m = gMarioStates[0]
    local itemID = tonumber(msg) or ITEM_LETTUCE

    spawn_sync_object(id_bhvIngredient, E_MODEL_NONE, m.pos.x, m.pos.y + 50, m.pos.z, function(o)
        o.oBehParams = itemID
    end)

    return true
end
hook_chat_command("ingredient", "[ITEM] - Create an ingredient", ingredient_command)

function counter_command(msg)
    local args = {}
    if msg and #msg ~= 0 then
        args = split(msg, " ", 2)
    end

    local m = gMarioStates[0]
    local counterType = tonumber(args[1]) or COUNTER_TYPE_DEFAULT
    local itemID = tonumber(args[2]) or ITEM_LETTUCE

    local counterSize = 104
    local x, y, z = m.pos.x, m.pos.y, m.pos.z
    local dir = (m.faceAngle.y + 0x2000) // 0x4000 * 0x4000
    dir = dir + 0x4000
    x = (x + counterSize // 2) // counterSize * counterSize
    z = (z + counterSize // 2) // counterSize * counterSize
    if counterType == COUNTER_TYPE_SERVING then
        x = x + sins(dir) * counterSize // 2
        z = z + coss(dir) * counterSize // 2
    end

    local model = SPECIAL_COUNTER_MODELS[counterType] or E_MODEL_COUNTER_CENTER
    spawn_sync_object(id_bhvCounter, model, x, y, z, function(o)
        o.oFaceAngleYaw = dir - 0x4000
        o.oFaceAnglePitch = 0
        o.oFaceAngleRoll = 0
        o.oBehParams2ndByte = counterType
        o.oBehParams = (o.oBehParams2ndByte << 16)
        if counterType == COUNTER_TYPE_INGREDIENT then
            o.oBehParams = o.oBehParams | (itemID)
        end
    end)

    m.pos.x = x + sins(dir) * counterSize
    m.pos.z = z + coss(dir) * counterSize
    return true
end
hook_chat_command("counter", "[TYPE,ITEM] - Create a counter", counter_command)

function add_order_command(msg)
    local orderID = tonumber(msg)
    if not orderID then
        local lData = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel]
        orderID = lData.orders[math.random(1, #lData.orders)]
    end

    local order = ORDER_DATA[orderID]
    if not order then
        djui_chat_message_create("Couldn't find that type")
        return true
    end

    network_send_include_self(true, {id = PACKET_ORDER, orderID = orderID})
    djui_chat_message_create("Added order: "..order.name)
    return true
end
hook_chat_command("add-order", "[ID?] - Add an order to the pending orders list - leave blank for random", add_order_command)

function start_level_command(msg)
    if gGlobalSyncTable.gameState == GAME_STATE_PLAYING then
        gGlobalSyncTable.gameState = GAME_STATE_END
        gGlobalSyncTable.timeLeft = 1
        return true
    end

    local oc_level = tonumber(msg) or OC_LEVEL_TEST
    local lData = OC_LEVEL_DATA[oc_level]

    gGlobalSyncTable.gameState = GAME_STATE_PLAYING
    gGlobalSyncTable.score = 0
    gGlobalSyncTable.tipMulti = 1
    gGlobalSyncTable.ocLevel = oc_level
    gGlobalSyncTable.timeLeft = lData.totalTime or 240
    gGlobalSyncTable.servedOrders = 0
    return true
end
hook_chat_command("start-level", "[ID?] - Start this level - leave blank to start the test level", start_level_command)