-- name: Overcooked 64!
-- description: Work with your fellow chefs to serve various dishes in wacky scenarios!\n\nA collaboration made for Blocky's "Cooperation" competition, based on the "Overcooked!" series by Ghost Town Games\n\nMain development: EmilyEmmi\nSprite work: EmilyEmmi, denpakei32, LoganLuigi21\nObject Models: WBMarioo, denpakei32\nLevel Design/Porting: EmilyEmmi, WBMarioo, Blocky\nUV Scroll Library: djoslin0\nAdditional support: Cooliokid 956
-- pausable: false
-- category: gamemode
-- incompatible: gamemode, romhack

local subTimer = 0
selectedItem = nil
selectedCounter = nil
waitOpenDJUI = false
gotNewRecord = false
stayInSpectate = true
wasInGameList = {}

pending_orders_all = {}
pending_orders = {}

GAME_STATE_LEVEL_SELECT = 0
GAME_STATE_SETUP = 1
GAME_STATE_PLAYING = 2
GAME_STATE_END = 3
GAME_STATE_PREPARE = 4

ACTION_BUTTONS = {X_BUTTON, Y_BUTTON, L_TRIG, B_BUTTON}

BASE_TEMPO = 0
BASE_MULTI = 1

gGlobalSyncTable.gameState = GAME_STATE_LEVEL_SELECT
gGlobalSyncTable.ocLevel = 0
gGlobalSyncTable.score = 0
gGlobalSyncTable.timeLeft = 0
gGlobalSyncTable.maxKitchens = 1
gGlobalSyncTable.peakPlayers = 1
gGlobalSyncTable.autoStart = (gServerSettings.headlessServer ~= 0)
gGlobalSyncTable.allowMidGameJoin = false
-- one kitchen for every 4 players
MAX_KITCHENS = math.ceil(MAX_PLAYERS / 4)
for i=1,MAX_KITCHENS do
    gGlobalSyncTable["tipMulti"..i] = 1
    gGlobalSyncTable["servedOrders"..i] = 0
    table.insert(pending_orders_all, {})
end

gOvercookedExtraStates = {}
for i=0,MAX_PLAYERS-1 do
    gOvercookedExtraStates[i] = {}
    local c = gOvercookedExtraStates[i]
    local sMario = gPlayerSyncTable[i]
    sMario.cutTimer = 0
    sMario.washTimer = 0
    sMario.kitchen = 1
    sMario.spawnID = 0
    sMario.selObjSyncID = 0
    sMario.selCounterSyncID = 0
    sMario.readyToStart = false
    sMario.spectator = true
    sMario.waitingForSlot = false
    sMario.throwButtonIndex = throwButtonIndex
    sMario.inPractice = false
    sMario.canRejoin = false
    sMario.coopnetID = "-1"
    c.actionAnimTimer = 0
end

SAMPLE_GRAB = audio_sample_load("obj_grab.ogg")
SAMPLE_CUT = audio_sample_load("ingredient_cut.ogg")
SAMPLE_PLATE_SPAWN = audio_sample_load("plate_place.ogg")
SAMPLE_FAIL = audio_sample_load("order_timeout.ogg")
SAMPLE_SERVE = audio_sample_load("service_bell.ogg")
SAMPLE_OVEN_OPEN = audio_sample_load("oven_door_open.ogg")
SAMPLE_OVEN_CLOSE = audio_sample_load("oven_door_close.ogg")
MAX_INGREDIENT_COUNT = 50

gLevelValues.disableActs = 1
gServerSettings.skipIntro = 1
gServerSettings.playerInteractions = PLAYER_INTERACTIONS_SOLID
gServerSettings.playerKnockbackStrength = 20

local lastSeq = -1
function update()
    if waitOpenDJUI then
        djui_open_pause_menu()
        waitOpenDJUI = false
    end

    local sMario0 = gPlayerSyncTable[0]
    pending_orders = pending_orders_all[sMario0.kitchen] or {}

    -- update music
    local currSeq = get_current_background_music()
    if (not gPlayerSyncTable[0].inPractice) and gGlobalSyncTable.gameState == GAME_STATE_SETUP then
        if currSeq ~= SEQ_MENU_FILE_SELECT then
            currSeq = SEQ_MENU_FILE_SELECT
            play_music(SEQ_PLAYER_LEVEL, currSeq, 0)
        elseif gGlobalSyncTable.timeLeft <= 3 then
            fadeout_level_music(600)
        end
    else
        stop_background_music(SEQ_MENU_FILE_SELECT)
    end

    if (not gPlayerSyncTable[0].inPractice) and gGlobalSyncTable.gameState == GAME_STATE_PLAYING and gGlobalSyncTable.timeLeft <= 30 then
        BASE_MULTI = 1.5
        sequence_player_set_transposition(SEQ_PLAYER_LEVEL, 3)
    else
        BASE_MULTI = 1
        sequence_player_set_transposition(SEQ_PLAYER_LEVEL, 2)
    end
    if currSeq ~= lastSeq then
        BASE_TEMPO = sequence_player_get_tempo(SEQ_PLAYER_LEVEL)
        lastSeq = currSeq
    else
        sequence_player_set_tempo(SEQ_PLAYER_LEVEL, BASE_TEMPO * BASE_MULTI)
    end

    -- update player count this round
    if network_is_server() and gGlobalSyncTable.gameState ~= GAME_STATE_END then
        local totalPlayers = get_active_player_count()
        if gGlobalSyncTable.gameState == GAME_STATE_LEVEL_SELECT then
            gGlobalSyncTable.peakPlayers = totalPlayers
        else
            gGlobalSyncTable.peakPlayers = math.clamp(totalPlayers, gGlobalSyncTable.peakPlayers, gGlobalSyncTable.maxKitchens * 4)
        end
    end

    -- prevent us from getting stuck in a level without sync valid
    if (not gNetworkPlayers[0].currAreaSyncValid) and gMarioStates[0].area.localAreaTimer > 150 then
        warp_to_level(gNetworkPlayers[0].currLevelNum, gNetworkPlayers[0].currAreaIndex, gNetworkPlayers[0].currActNum)
    end

    -- limit the number of ingredients in the level
    -- we prioritize deleting raw, uncut ingredients
    local ingredientCount = obj_count_objects_with_behavior_id(id_bhvIngredient)
    if ingredientCount > MAX_INGREDIENT_COUNT then
        local o = obj_get_first_with_behavior_id(id_bhvIngredient)
        local lastResortDelete = {}
        while o and ingredientCount > MAX_INGREDIENT_COUNT do
            local iData = ITEM_DATA[o.oBehParams] or ITEM_DATA[0]
            if o.oHeldState == HELD_FREE and not iData.noTrash then
                if o.oContentCount == 0 and (not iData.subIcon)
                and o.usingObj == nil or o.usingObj == o then
                    obj_mark_for_deletion(o)
                    ingredientCount = ingredientCount - 1
                else
                    table.insert(lastResortDelete, o)
                end
            end
            o = obj_get_next_with_same_behavior_id(o)
        end

        -- delete last resort items
        while #lastResortDelete ~= 0 and ingredientCount > MAX_INGREDIENT_COUNT do
            o = table.remove(lastResortDelete, 1)
            obj_mark_for_deletion(o)
            ingredientCount = ingredientCount - 1
        end
    end

    if gGlobalSyncTable.gameState == GAME_STATE_LEVEL_SELECT then
        local np = gNetworkPlayers[0]
        if np.currLevelNum ~= LEVEL_CASTLE_GROUNDS and np.currAreaSyncValid then
            warp_to_level(LEVEL_CASTLE_GROUNDS, 1, 0)
        end

        -- EXTREMELY BASIC headless support
        if network_is_server() then
            if gServerSettings.headlessServer ~= 0 then
                stayInSpectate = true
                gPlayerSyncTable[0].spectator = true
                gPlayerSyncTable[0].inPractice = true
            end

            if gGlobalSyncTable.autoStart and gGlobalSyncTable.peakPlayers ~= 0 then
                subTimer = subTimer + 1
                if subTimer >= 30 then
                    subTimer = 0
                    gGlobalSyncTable.timeLeft = gGlobalSyncTable.timeLeft - 1
                    if gGlobalSyncTable.timeLeft <= 0 then
                        local newLevel = gGlobalSyncTable.ocLevel
                        if get_star_record(newLevel) >= 1 then
                            newLevel = (newLevel % #OC_LEVEL_DATA + 1)
                        end
                        start_level_command(tostring(newLevel))
                    end
                end
            else
                subTimer = 0
                gGlobalSyncTable.timeLeft = 15
            end
        end
    elseif gGlobalSyncTable.gameState == GAME_STATE_SETUP or gGlobalSyncTable.gameState == GAME_STATE_PLAYING then
        local lData = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel]
        local np0 = gNetworkPlayers[0]
        local act = sMario0.kitchen
        if sMario0.inPractice then
            if np0.currLevelNum ~= LEVEL_CASTLE_GROUNDS and np0.currAreaSyncValid then
                warp_to_level(LEVEL_CASTLE_GROUNDS, 1, 0)
            end
        elseif (np0.currLevelNum ~= lData.level or np0.currActNum ~= act) and np0.currAreaSyncValid then
            warp_to_level(lData.level, 1, act)
        end
        restartTransition = false

        if np0.currLevelNum == lData.level and lData.updateFunc then
            lData.updateFunc()
        end

        if gGlobalSyncTable.gameState == GAME_STATE_PLAYING then
            sMario0.readyToStart = false

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

            for kitchen, pending_orders in ipairs(pending_orders_all) do
                for i, pending_data in ipairs(pending_orders) do
                    if not pending_data.vanishTimer then
                        pending_data.prevTime = pending_data.time
                        pending_data.time = pending_data.time - 1
                        if pending_data.time <= 0 then
                            pending_data.time = pending_data.maxTime
                            pending_data.redTimer = 30
                            if (not sMario0.inPractice) and kitchen == gPlayerSyncTable[0].kitchen then
                                audio_sample_play(SAMPLE_FAIL, gLakituState.pos, 1)
                            end
                            if network_is_server() then
                                gGlobalSyncTable["tipMulti"..kitchen] = 1
                                gGlobalSyncTable.score = gGlobalSyncTable.score - 30
                            end
                        end
                    else
                        pending_data.vanishTimer = pending_data.vanishTimer - 1
                        if pending_data.vanishTimer <= 0 then
                            table.remove(pending_orders, i)
                        end
                    end
                end
            end

            -- automatically add orders
            if network_is_server() then
                for kitchen = 1, gGlobalSyncTable.maxKitchens do
                    local pending_orders = pending_orders_all[kitchen]
                    local servedOrders = gGlobalSyncTable["servedOrders"..kitchen]
                    local expected_orders = math.clamp(2 + (lData.totalTime - gGlobalSyncTable.timeLeft) // 10 - servedOrders, 2, 5)

                    while #pending_orders < expected_orders do
                        local orderID = lData.orders[math.random(1, #lData.orders)]
                        network_send_include_self(true, {id = PACKET_ORDER, orderID = orderID, kitchen = kitchen})
                    end
                end
            end
        else
            local m0 = gMarioStates[0]
            if (not sMario0.inPractice) and m0.action ~= ACT_SELECT_START then
                drop_and_set_mario_action(m0, ACT_SELECT_START, 0)
            end

            clear_pending_orders_table()
            if network_is_server() then
                wasInGameList = {}
            end
    
            subTimer = subTimer + 1
            if subTimer >= 30 then
                subTimer = 0
                if gGlobalSyncTable.timeLeft ~= 0 then
                    if network_is_server() then
                        gGlobalSyncTable.timeLeft = gGlobalSyncTable.timeLeft - 1

                        -- adjust time based on how many people are ready
                        local totalPlayers = 0
                        local nonReadyPlayers = 0
                        for i=0,MAX_PLAYERS-1 do
                            local np, sMario = gNetworkPlayers[i], gPlayerSyncTable[i]
                            if np.connected and not sMario.spectator then
                                totalPlayers = totalPlayers + 1
                                if not sMario.readyToStart then
                                    nonReadyPlayers = nonReadyPlayers + 1
                                end
                            end
                        end
                        if totalPlayers < 1 then totalPlayers = 1 end

                        gGlobalSyncTable.timeLeft = math.min(gGlobalSyncTable.timeLeft, nonReadyPlayers * 20 // totalPlayers + 3)
                        if gGlobalSyncTable.timeLeft == 0 then
                            gGlobalSyncTable.timeLeft = lData.totalTime or 240
                            gGlobalSyncTable.gameState = GAME_STATE_PLAYING
                        elseif gGlobalSyncTable.timeLeft == 2 then
                            -- See which spots are filled
                            local maxKitchens = gGlobalSyncTable.maxKitchens
                            local maxSpawnID = math.ceil(gGlobalSyncTable.peakPlayers / maxKitchens)
                            local isFilled = {}
                            local playerNeedsSpot = {}
                            for i=0,MAX_PLAYERS-1 do
                                local np, sMario = gNetworkPlayers[i], gPlayerSyncTable[i]
                                if np.connected and not sMario.spectator then
                                    local spotID = ((sMario.kitchen-1) << 2) + sMario.spawnID
                                    if (not isFilled[spotID]) and sMario.readyToStart
                                    and sMario.kitchen <= maxKitchens and sMario.spawnID < maxSpawnID then
                                        isFilled[spotID] = 1
                                    else
                                        table.insert(playerNeedsSpot, i)
                                    end
                                end
                            end

                            -- Reassign players to force an even split
                            for kitchen=1,maxKitchens do
                                for spawnID=0,maxSpawnID-1 do
                                    if #playerNeedsSpot == 0 then break end
                                    local spotID = ((kitchen-1) << 2) + spawnID
                                    if (not isFilled[spotID]) and kitchen <= maxKitchens and spawnID <= maxSpawnID then
                                        local index = table.remove(playerNeedsSpot)
                                        local sMario = gPlayerSyncTable[index]
                                        sMario.kitchen, sMario.spawnID = kitchen, spawnID
                                        isFilled[spotID] = 1
                                    end
                                end
                            end
                        end
                    else
                        set_without_sync(gGlobalSyncTable, "timeLeft", gGlobalSyncTable.timeLeft - 1)
                    end
                end
            end
        end
    elseif gGlobalSyncTable.gameState == GAME_STATE_END then
        clear_pending_orders_table()
        subTimer = subTimer + 1
        if subTimer >= 30 then
            subTimer = 0
            if network_is_server() then
                gGlobalSyncTable.timeLeft = gGlobalSyncTable.timeLeft - 1
                if gGlobalSyncTable.timeLeft == 0 then
                    gGlobalSyncTable.gameState = GAME_STATE_LEVEL_SELECT
                    gGlobalSyncTable.timeLeft = 15
                end
            else
                set_without_sync(gGlobalSyncTable, "timeLeft", gGlobalSyncTable.timeLeft - 1)
            end
        end
    elseif gGlobalSyncTable.gameState == GAME_STATE_PREPARE then
        clear_pending_orders_table()
        local lData = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel]
        local announceProblem = false
        subTimer = subTimer + 1
        if subTimer >= 30 and gGlobalSyncTable.timeLeft ~= 0 then
            subTimer = 0
            if network_is_server() then
                gGlobalSyncTable.timeLeft = gGlobalSyncTable.timeLeft - 1
                announceProblem = (gGlobalSyncTable.timeLeft == 0)
            else
                set_without_sync(gGlobalSyncTable, "timeLeft", gGlobalSyncTable.timeLeft - 1)
            end
        end

        if restartTransition and not sMario0.inPractice then
            play_transition(WARP_TRANSITION_FADE_INTO_STAR, 1, 255, 255, 255)
        end

        if subTimer == 1 and gGlobalSyncTable.timeLeft == 10 then
            if not sMario0.inPractice then
                play_sound(SOUND_MENU_STAR_SOUND_OKEY_DOKEY, gGlobalSoundSource)
                play_transition(WARP_TRANSITION_FADE_INTO_STAR, 15, 255, 255, 255)
            end
        elseif restartTransition or not is_transition_playing() then
            if network_is_server() then
                local allOut = true
                local waitingToGetOut = {}
                for i=0,MAX_PLAYERS-1 do
                    local np = gNetworkPlayers[i]
                    if np.connected and (np.currLevelNum == lData.level or not np.currAreaSyncValid) then
                        allOut = false
                        if i == 0 and np.currAreaSyncValid then
                            warp_to_level(LEVEL_CASTLE_GROUNDS, 1, 0)
                            restartTransition = true
                        end
                        if not announceProblem then
                            break
                        else
                            table.insert(waitingToGetOut, i)
                        end
                    end
                end

                if allOut then
                    gGlobalSyncTable.gameState = GAME_STATE_SETUP
                    gGlobalSyncTable.score = 0
                    gGlobalSyncTable.timeLeft = 23
                    gGlobalSyncTable.peakPlayers = get_active_player_count()
                    gGlobalSyncTable.maxKitchens = math.clamp(math.ceil(gGlobalSyncTable.peakPlayers / 4), 1, MAX_KITCHENS)
                    for i=1,MAX_KITCHENS do
                        gGlobalSyncTable["tipMulti"..i] = 1
                        gGlobalSyncTable["servedOrders"..i] = 0
                    end
                elseif announceProblem then
                    attempt_desync_fix()
                    djui_chat_message_create(trans("connection_issues"))
                    for i, index in ipairs(waitingToGetOut) do
                        local np = gNetworkPlayers[index]
                        djui_chat_message_create(network_get_player_text_color_string(index)..np.name)
                    end
                end
            else
                local np = gNetworkPlayers[0]
                if np.currLevelNum == lData.level then
                    warp_to_level(LEVEL_CASTLE_GROUNDS, 1, 0)
                    restartTransition = true
                end
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
    if gGlobalSyncTable.gameState == GAME_STATE_PLAYING then
        drop_and_set_mario_action(gMarioStates[0], ACT_SELECT_START, 0)
    end

    complete_save_file()
    local sMario0 = gPlayerSyncTable[0]

    if didInitialJoin then return end
    didInitialJoin = true

    -- warning for old versions of CS
    if charSelect then
        local csVersion = charSelect.version_get_full()
        if csVersion.major < 16 or (csVersion.major == 16 and csVersion.minor < 3) then
            djui_chat_message_create(trans("old_char_select_warning"))
        end
    end
    
    if network_is_server() then
        sMario0.spectator = false
        sMario0.flags = gMarioStates[0].flags & ~MARIO_VANISH_CAP
    else
        clear_pending_orders_table()
        sMario0.waitingForSlot = false
        sMario0.canRejoin = (gGlobalSyncTable.gameState ~= GAME_STATE_PLAYING)
        sMario0.coopnetID = get_coopnet_id(0)

        network_send_to(1, true, {
            id = PACKET_REQUEST_ORDERS,
            from = network_global_index_from_local(0),
        })
        if gGlobalSyncTable.gameState == GAME_STATE_PLAYING or gGlobalSyncTable.gameState == GAME_STATE_SETUP then
            local kitchen, spawnID = join_smallest_kitchen(0)
            sMario0.kitchen = kitchen
            sMario0.spawnID = 0
            sMario0.spectator = true
            stayInSpectate = true
        else
            sMario0.spectator = false
            stayInSpectate = false
            sMario0.kitchen = 1
            sMario0.spawnID = 0
            gMarioStates[0].flags = gMarioStates[0].flags & ~MARIO_VANISH_CAP
        end

        open_menu()
        enter_menu(5, 1, true)
    end
end
hook_event(HOOK_ON_SYNC_VALID, on_sync_valid)

---@param m MarioState
function mario_update(m)
    m.health = 0x880 -- no health in this mod
    m.numLives = 100 -- or lives
    m.peakHeight = m.pos.y -- or fall damage
    m.specialTripleJump = 0 -- no special triple jump either
    if m.marioBodyState.allowPartRotation == 15 and m.action ~= ACT_HOLD_WALKING then
        m.marioBodyState.allowPartRotation = 0
    end

    -- if someone is waiting for a slot, let them in if we're the host
    local sMario = gPlayerSyncTable[m.playerIndex]
    local np = gNetworkPlayers[m.playerIndex]
    if network_is_server() and np.connected and sMario.spectator
    and sMario.waitingForSlot and np.currAreaSyncValid then
        if gGlobalSyncTable.gameState ~= GAME_STATE_PLAYING then
            sMario.spectator = false
            sMario.canRejoin = true
        elseif (gGlobalSyncTable.allowMidGameJoin or sMario.canRejoin)
        and get_active_player_count() < gGlobalSyncTable.maxKitchens * 4 then
            local kitchen, spawnID = join_smallest_kitchen(m.playerIndex)
            if spawnID ~= -1 then
                sMario.kitchen = kitchen
                sMario.spawnID = spawnID
                sMario.spectator = false
            end
        end
    end

    if sMario.inPractice then
        network_player_set_description(np, trans("menu_practice"), 100, 100, 100, 255)
    elseif sMario.spectator then
        network_player_set_description(np, trans("menu_spectate"), 100, 100, 100, 255)
    else
        network_player_set_description(np, "", 255, 255, 255, 255)
    end

    if m.playerIndex ~= 0 and is_player_active(m) == 0 then return end

    local c = gOvercookedExtraStates[m.playerIndex]
    if sMario.cutTimer ~= 0 then
        -- Handle cutting
        if m.action & (ACT_FLAG_THROWING | ACT_FLAG_STATIONARY) ~= 0
        and m.action ~= ACT_IDLE and m.heldObj == nil then
            if m.action & ACT_FLAG_AIR ~= 0 then
                set_mario_action(m, ACT_FREEFALL, 0)
            else
                set_mario_action(m, ACT_IDLE, 0)
            end
        end

        set_mario_animation(m, CHAR_ANIM_FIRST_PUNCH)
        set_anim_to_frame(m, c.actionAnimTimer)
        c.actionAnimTimer = (c.actionAnimTimer + 1) % 6
        if c.actionAnimTimer == 1 then
            audio_sample_play(SAMPLE_CUT, gLakituState.pos, 1)
            
            local o, counter = selectedItem, selectedCounter
            if m.playerIndex ~= 0 then
                o, counter = sync_object_get_object(sMario.selObjSyncID), sync_object_get_object(sMario.selCounterSyncID)
            end

            if o and ITEM_DATA[o.oBehParams] and ITEM_DATA[o.oBehParams].cut
            and counter and counter.oBehParams2ndByte == COUNTER_TYPE_CUT then
                o.oCutOrCookTimer = o.oCutOrCookTimer + 6
                if o.oCutOrCookTimer >= 30 then
                    o.oBehParams = ITEM_DATA[o.oBehParams].cut
                    o.oCutOrCookTimer = 0
                    if m.playerIndex == 0 then
                        network_send_object(o, true)
                    end
                end
            end
        end
        set_without_sync(sMario, "cutTimer", sMario.cutTimer - 1)
        if sMario.cutTimer == 0 and m.playerIndex == 0 then
            sync_value(sMario, "cutTimer")
        end
    elseif sMario.washTimer ~= 0 then
        -- Handle washing
        set_mario_animation(m, CHAR_ANIM_SECOND_PUNCH_FAST)
        set_anim_to_frame(m, c.actionAnimTimer // 2)
        c.actionAnimTimer = (c.actionAnimTimer + 1) % 12
        play_sound(SOUND_ENV_WATER, m.marioObj.header.gfx.cameraToObject)
        local counter = selectedCounter
        if m.playerIndex ~= 0 then
            counter = sync_object_get_object(sMario.selCounterSyncID)
        end

        if counter and counter.oBehParams2ndByte == COUNTER_TYPE_SINK and counter.oPlatesStackedExtra ~= 0 then
            counter.oPlateAppearTimer = counter.oPlateAppearTimer + 1
            if counter.oPlateAppearTimer >= 3 * 30 then
                counter.oPlateAppearTimer = 0
                local o = obj_get_nearest_behavior_id_with_condition(counter, id_bhvIngredient, function(o)
                    local iData = ITEM_DATA[o.oBehParams]
                    return iData and iData.washItem and o.oPlateAppearTimer > 1
                end)

                if o then
                    o.oPlateAppearTimer = 1
                    if m.playerIndex == 0 then
                        network_send_object(o, true)
                    end
                else
                    counter.oPlatesStackedExtra = 0
                end
            end
            
            if m.playerIndex == 0 and counter.oPlateAppearTimer % 30 == 0 then
                network_send_object(counter, true)
            end
        end
        set_without_sync(sMario, "washTimer", sMario.washTimer - 1)
        if sMario.cutTimer == 0 and m.playerIndex == 0 then
            sync_value(sMario, "washTimer")
        end
    else
        c.actionAnimTimer = 0
    end
    
    -- move romhack cam up
    --[[if m.playerIndex == 0 and m.area.camera and m.area.camera.mode == CAMERA_MODE_ROM_HACK
    and set_cam_angle(0) ~= CAM_ANGLE_MARIO then
        m.statusForCamera.pos.y = m.statusForCamera.pos.y + 250
    end]]
end
hook_event(HOOK_MARIO_UPDATE, mario_update)

local INVALID_GRAB_ACTION = {
    [ACT_DIVE_SLIDE] = 1,
}

function before_mario_update(m)
    if m.playerIndex ~= 0 then return end

    local GRAB_BUTTON = ACTION_BUTTONS[grabButtonIndex+1]
    local ACTION_BUTTON = ACTION_BUTTONS[actionButtonIndex+1]
    local THROW_BUTTON = ACTION_BUTTONS[throwButtonIndex+1]

    local sMario = gPlayerSyncTable[0]
    if (not inMenu) and pressed_pause()
    and not (cheatsApi and m.controller.buttonDown & L_TRIG ~= 0) then
        play_sound(SOUND_MENU_PAUSE, gGlobalSoundSource)
        open_menu()
        m.controller.buttonPressed = m.controller.buttonPressed & ~START_BUTTON
    end
    if inMenu then
        menu_controls(m)
    end

    -- get selected item and counter
    if sMario.inPractice or not sMario.spectator then
        local grabPos = {x = m.pos.x, y = m.pos.y, z = m.pos.z}
        grabPos.x = grabPos.x + sins(m.faceAngle.y) * 52
        grabPos.z = grabPos.z + coss(m.faceAngle.y) * 52
        --spawn_non_sync_object(id_bhvSparkleSpawn, E_MODEL_NONE, grabPos.x, grabPos.y, grabPos.z, nil)
        
        -- select ingredient from ground
        local dist = 0
        selectedItem, dist = nearest_behavior_id_from_pos_with_condition(grabPos, id_bhvIngredient, function(o)
            local counter = o.usingObj
            return o.oHeldState == HELD_FREE and o.oPlateAppearTimer == 0 and o.oRespawnTimer == 0
            and (o.parentObj == nil or o.parentObj == o) and (counter == nil)
        end)
        if dist > 115 then
            selectedItem = nil
        end

        -- select counter (when not holding an item, ground ingredients take priority, otherwise counters do)
        selectedCounter = nil
        if selectedItem == nil or m.heldObj then
            selectedCounter, dist = nearest_behavior_id_from_pos_with_condition(grabPos, id_bhvCounter, function(counter)
                return true -- No condition yet
            end)
            if selectedCounter == nil or dist > 100 then
                selectedCounter = nil
            else
                selectedItem = selectedCounter.usingObj
            end
        end
    else
        m.flags = m.flags | MARIO_VANISH_CAP
        selectedItem, selectedCounter = nil, nil
    end
    sMario.selObjSyncID = (selectedItem and selectedItem.oSyncID) or 0
    sMario.selCounterSyncID = (selectedCounter and selectedCounter.oSyncID) or 0
    sMario.throwButtonIndex = throwButtonIndex
    sMario.waitingForSlot = (sMario.spectator and not (sMario.inPractice or stayInSpectate))

    -- Sparkles at selected (might be changed)
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

    if m.controller.buttonDown & ACTION_BUTTON ~= 0 and (not m.heldObj)
    and selectedCounter and (selectedCounter.oBehParams2ndByte == COUNTER_TYPE_CUT or selectedCounter.oBehParams2ndByte == COUNTER_TYPE_SINK) then
        local counter = selectedCounter
        local o = counter.usingObj
        local iData = (o and ITEM_DATA[o.oBehParams]) or ITEM_DATA[0]

        if selectedCounter.oBehParams2ndByte == COUNTER_TYPE_CUT
        and o and o ~= counter and iData and iData.cut then
            sMario.cutTimer = 6
            m.controller.buttonPressed = m.controller.buttonPressed &~ ACTION_BUTTON
        elseif selectedCounter.oBehParams2ndByte == COUNTER_TYPE_SINK and counter.oPlatesStackedExtra ~= 0 then
            sMario.washTimer = 6
            m.controller.buttonPressed = m.controller.buttonPressed &~ ACTION_BUTTON
        end
    end
    
    if m.controller.buttonPressed & GRAB_BUTTON ~= 0 and not INVALID_GRAB_ACTION[m.action] then
        if m.heldObj then
            local o = m.heldObj
            local placed, stillHolding = attempt_item_place(o, m, selectedItem, selectedCounter, true)
            if (placed or GRAB_BUTTON ~= THROW_BUTTON) and obj_has_behavior_id(m.heldObj, id_bhvBowser) == 0 then
                if placed or not stillHolding then
                    audio_sample_play(SAMPLE_GRAB, gLakituState.pos, 0.5)
                    if not stillHolding then
                        mario_drop_held_object(m)
                    end
                end
                m.controller.buttonPressed = m.controller.buttonPressed &~ GRAB_BUTTON

                if not m.heldObj then
                    m.marioBodyState.allowPartRotation = 0
                    m.prevAction = m.action
                    if m.action & ACT_FLAG_SWIMMING ~= 0 then
                        m.action = ACT_WATER_ACTION_END
                    elseif m.action & ACT_FLAG_CONTROL_JUMP_HEIGHT ~= 0 then
                        m.action = ACT_JUMP
                    elseif m.action & ACT_FLAG_AIR ~= 0 then
                        m.action = ACT_FREEFALL
                    elseif m.action & ACT_FLAG_MOVING ~= 0 then
                        set_mario_action(m, ACT_WALKING, 0)
                    else
                        m.action = ACT_IDLE
                    end
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

            -- Disallows diving if we are close enough to a counter- okay I guess
            if o or counter then
                m.controller.buttonPressed = m.controller.buttonPressed &~ GRAB_BUTTON
            end

            if o and valid then
                audio_sample_play(SAMPLE_GRAB, gLakituState.pos, 0.5)
                m.usedObj = o
                m.marioBodyState.grabPos = GRAB_POS_LIGHT_OBJ
                o.oInteractType = INTERACT_GRABBABLE
                o.oFlags = o.oFlags | OBJ_FLAG_HOLDABLE
                mario_grab_used_object(m)
                if m.action ~= ACT_DIVE then
                    m.prevAction = m.action
                    if m.action & ACT_FLAG_SWIMMING ~= 0 then
                        m.action = ACT_HOLD_WATER_ACTION_END
                    elseif m.action & ACT_FLAG_CONTROL_JUMP_HEIGHT ~= 0 then
                        m.action = ACT_HOLD_JUMP
                    elseif m.action & ACT_FLAG_AIR ~= 0 then
                        m.action = ACT_HOLD_FREEFALL
                        if m.action & ACT_FLAG_FLYING ~= 0 then
                            set_camera_mode(m.area.camera, m.area.camera.defMode, 0)
                        end
                    elseif m.action & ACT_FLAG_MOVING ~= 0 then
                        set_mario_action(m, ACT_HOLD_WALKING, 0)
                    else
                        m.action = ACT_HOLD_IDLE
                    end
                end
            end
        end
    end
    
    if m.controller.buttonPressed & THROW_BUTTON ~= 0 and m.heldObj and (m.action & ACT_FLAG_THROWING == 0) and obj_has_behavior_id(m.heldObj, id_bhvBowser) == 0 then
        local iData = ITEM_DATA[m.heldObj.oBehParams] or ITEM_DATA[0]
        if obj_has_behavior_id(m.heldObj, id_bhvIngredient) == 0 or not (iData.noThrow or m.heldObj.oContentCount ~= 0) then
            m.marioBodyState.allowPartRotation = 0
            m.prevAction = m.action
            m.controller.buttonPressed = m.controller.buttonPressed &~ THROW_BUTTON
            if m.action & ACT_FLAG_SWIMMING ~= 0 then
                set_mario_action(m, ACT_WATER_THROW, 0)
            elseif m.action & ACT_FLAG_AIR ~= 0 then
                m.action = ACT_PREPARE_THROW_AIR
            else
                m.action = ACT_PREPARE_THROW
            end
        end
    end
end
hook_event(HOOK_BEFORE_MARIO_UPDATE, before_mario_update)

function allow_interact(m, o, type)
    if type == INTERACT_GRABBABLE and obj_has_behavior_id(o, id_bhvIngredient) ~= 0 then
        -- don't interact with ingredients; have THEM be pushed around instead
        if m.flags & MARIO_VANISH_CAP == 0 then
            obj_resolve_object_collisions_custom(m.marioObj, o) -- runs from Mario object
        end
        return false
    elseif type == INTERACT_WARP or type == INTERACT_WARP_DOOR then
        return false
    end
end
hook_event(HOOK_ALLOW_INTERACT, allow_interact)

function on_player_disconnected(m)
    local sMario = gPlayerSyncTable[m.playerIndex]
    set_without_sync(sMario, "spectator", true)
    set_without_sync(sMario, "waitingForSlot", false)
    set_without_sync(sMario, "inPractice", false)
    set_without_sync(sMario, "canRejoin", false)

    if network_is_server() and sMario.coopnetID ~= "-1" then
        -- see if someone else has that ID (in case they joined before their clone disconnected)
        local foundClone = false
        for i=1,MAX_PLAYERS-1 do
            if i ~= m.playerIndex and gPlayerSyncTable[i].coopnetID == sMario.coopnetID then
                gPlayerSyncTable[i].canRejoin = true
                foundClone = true
                break
            end
        end

        if not foundClone then
            --log_to_console("Added to rejoin list: "..sMario.coopnetID)
            table.insert(wasInGameList, sMario.coopnetID)
        end
    end
    set_without_sync(sMario, "coopnetID", "-1")
end
hook_event(HOOK_ON_PLAYER_DISCONNECTED, on_player_disconnected)

function allow_pvp_attack(attacker, victim, interaction)
    return false -- NOOOOOO PVP
end
hook_event(HOOK_ALLOW_PVP_ATTACK, allow_pvp_attack)

local lastDirX = 0
local lastDirY = 0
confirmTime = 0
---@param m MarioState
function act_select_start(m)
    local sMario = gPlayerSyncTable[m.playerIndex]
    local maxKitchens = gGlobalSyncTable.maxKitchens
    local maxSpawnID = math.ceil(gGlobalSyncTable.peakPlayers / maxKitchens)
    set_character_animation(m, CHAR_ANIM_FIRST_PERSON)

    if sMario.kitchen > maxKitchens then
        sMario.kitchen = 1
    end
    if sMario.spawnID >= maxSpawnID then
        sMario.maxSpawnID = 0
    end

    local spawnObj = obj_get_first_with_behavior_id_and_field_s32(id_bhvOcSpawn, 0x2F, sMario.spawnID) -- oBehParams2ndByte
    if spawnObj then
        m.pos.x, m.pos.y, m.pos.z = spawnObj.oPosX, spawnObj.oPosY, spawnObj.oPosZ
        m.faceAngle.y = spawnObj.oFaceAngleYaw
    else
        vec3f_copy(m.pos, m.spawnInfo.startPos)
        vec3s_copy(m.faceAngle, m.spawnInfo.startAngle)
    end

    if sMario.spectator and m.playerIndex ~= 0 then
        m.marioObj.header.gfx.node.flags = m.marioObj.header.gfx.node.flags | GRAPH_RENDER_INVISIBLE
    end
    vec3f_copy(m.marioObj.header.gfx.pos, m.pos);
    vec3s_set(m.marioObj.header.gfx.angle, 0, m.faceAngle.y, 0)
    if gGlobalSyncTable.gameState ~= GAME_STATE_SETUP then
        return force_idle_state(m)
    end

    if m.playerIndex ~= 0 or m.actionState ~= 0 or gGlobalSyncTable.timeLeft <= 3 then return 0 end

    local spotTaken = false
    if m.actionState == 0 and not sMario.spectator then
        for i=1,MAX_PLAYERS-1 do
            local np2, sMario2 = gNetworkPlayers[i], gPlayerSyncTable[i]
            if np2.connected and sMario2.readyToStart and not sMario2.spectator
            and sMario.kitchen == sMario2.kitchen and sMario.spawnID == sMario2.spawnID then
                spotTaken = true
                break
            end
        end
    end

    sMario.readyToStart = false
    if spotTaken then
        confirmTime = -1
    elseif m.controller.buttonDown & A_BUTTON ~= 0 then
        confirmTime = confirmTime + 1
        if confirmTime >= 30 then
            confirmTime = 0
            m.actionState = 1
            sMario.readyToStart = true
        end
    else
        confirmTime = math.max(confirmTime - 1, 0)
    end

    local change = 0
    m.actionTimer = m.actionTimer + 1
    if (m.controller.buttonDown & D_JPAD ~= 0 or m.controller.rawStickY > 64 or m.controller.buttonDown & U_JPAD ~= 0 or m.controller.rawStickY < -64) then
        local dir = ((m.controller.buttonDown & D_JPAD ~= 0 or m.controller.rawStickY > 64) and -1) or 1
        if dir ~= lastDirY or m.actionTimer >= 10 then
            m.actionArg = (m.actionArg + 1) % 2
            m.actionTimer = 0
            lastDirY = dir
        end
    else
        lastDirY = 0
    end
    if (m.controller.buttonDown & R_JPAD ~= 0  or m.controller.rawStickX > 64 or m.controller.buttonDown & L_JPAD ~= 0 or m.controller.rawStickX < -64) then
        local dir = ((m.controller.buttonDown & R_JPAD ~= 0 or m.controller.rawStickX > 64) and 1) or -1
        if dir ~= lastDirX or m.actionTimer >= 10 then
            change = dir
            m.actionTimer = 0
            lastDirX = dir
        end
    else
        lastDirX = 0
    end

    if change ~= 0 then
        if m.actionArg == 0 then
            sMario.kitchen = (sMario.kitchen + change - 1) % maxKitchens + 1
        else
            sMario.spawnID = (sMario.spawnID + change) % maxSpawnID
        end
    end
end
ACT_SELECT_START = allocate_mario_action(ACT_GROUP_CUTSCENE | ACT_FLAG_INTANGIBLE | ACT_FLAG_PAUSE_EXIT)
hook_mario_action(ACT_SELECT_START, act_select_start)

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
        m.forwardVel = math.max(m.forwardVel - 8, 0)
        return set_mario_action(m, ACT_HOLD_DECELERATING, 0)
    end

    if (m.input & INPUT_Z_PRESSED) ~= 0 then
        return drop_and_set_mario_action(m, ACT_CROUCH_SLIDE, 0)
    end

    update_walking_speed(m) -- normal walking speed
    -- turn more sharply
    m.faceAngle.y = m.intendedYaw - approach_s32(limit_angle(m.intendedYaw - m.faceAngle.y), 0, 0x800, 0x800)

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

    m.marioBodyState.grabPos = GRAB_POS_LIGHT_OBJ
    m.marioBodyState.allowPartRotation = 15
    m.marioBodyState.torsoAngle.z = approach_s32(m.marioBodyState.torsoAngle.z, val02, 0x400, 0x400)
    m.marioBodyState.torsoAngle.x = approach_s32(m.marioBodyState.torsoAngle.x, val00, 0x400, 0x400)

    if (0.4 * m.intendedMag - m.forwardVel > 10) then
        set_mario_particle_flags(m, PARTICLE_DUST, 0)
    end

    return 0
end
hook_mario_action(ACT_HOLD_WALKING, act_custom_hold_walking)

--- @param m MarioState
function act_custom_throwing(m)
    if not m then return 0 end
    if (m.heldObj and (m.heldObj.oInteractionSubtype & INT_SUBTYPE_HOLDABLE_NPC ~= 0)) then
        return set_mario_action(m, ACT_PLACING_DOWN, 0)
    end

    if (m.input & INPUT_UNKNOWN_10 ~= 0) then
        return drop_and_set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    end

    if (m.input & INPUT_OFF_FLOOR ~= 0) then
        return drop_and_set_mario_action(m, ACT_FREEFALL, 0);
    end

    if (m.input & INPUT_A_PRESSED) ~= 0 then
        m.marioObj.header.gfx.animInfo.animID = -1
        set_mario_y_vel_based_on_fspeed(m, 42, 0.25)
        m.forwardVel = m.forwardVel * 0.8
        m.action = ACT_AIR_THROW
        return 1
    end

    m.actionTimer = m.actionTimer + 1
    if (m.actionTimer == 4) then
        mario_throw_held_object(m);
        play_character_sound_if_no_flag(m, CHAR_SOUND_WAH2, MARIO_MARIO_SOUND_PLAYED);
        play_sound_if_no_flag(m, SOUND_ACTION_THROW, MARIO_ACTION_SOUND_PLAYED);
        queue_rumble_data_mario(m, 3, 50);
    end

    -- act as walking
    update_walking_speed(m)
    set_character_animation(m, CHAR_ANIM_GROUND_THROW)
    if is_anim_at_end(m) ~= 0 then
        return set_mario_action(m, ACT_IDLE, 0)
    end

    local result = perform_ground_step(m)
    if result == GROUND_STEP_LEFT_GROUND then
        set_mario_action(m, ACT_HOLD_FREEFALL, 0)
    elseif result == GROUND_STEP_HIT_WALL then
        if (m.forwardVel > 16) then
            mario_set_forward_vel(m, 16)
        end
    end

    if (0.4 * m.intendedMag - m.forwardVel > 10) then
        set_mario_particle_flags(m, PARTICLE_DUST, 0)
    end

    set_anim_to_frame(m, m.marioObj.header.gfx.animInfo.animFrame + 2)
    return 0;
end
hook_mario_action(ACT_THROWING, act_custom_throwing)

--- @param m MarioState
function act_prepare_throw(m)
    if not m then return 0 end
    if (m.heldObj and (m.heldObj.oInteractionSubtype & INT_SUBTYPE_HOLDABLE_NPC ~= 0)) then
        return set_mario_action(m, ACT_PLACING_DOWN, 0)
    end

    if (m.input & INPUT_UNKNOWN_10 ~= 0) then
        return drop_and_set_mario_action(m, ACT_SHOCKWAVE_BOUNCE, 0);
    elseif (m.input & INPUT_OFF_FLOOR ~= 0) then
        m.action = ACT_PREPARE_THROW_AIR
        m.actionTimer = math.min(m.actionTimer, 3)
        return 1
    elseif (m.input & INPUT_ABOVE_SLIDE ~= 0) then
        return set_mario_action(m, ACT_HOLD_BEGIN_SLIDING, 0);
    end

    m.actionTimer = m.actionTimer + 1
    animated_stationary_ground_step(m, CHAR_ANIM_IDLE_WITH_LIGHT_OBJ, ACT_IDLE)

    local THROW_BUTTON = ACTION_BUTTONS[gPlayerSyncTable[m.playerIndex].throwButtonIndex+1]
    if m.controller.buttonDown & THROW_BUTTON == 0 then
        m.flags = m.flags & ~MARIO_MARIO_SOUND_PLAYED
        m.action = ACT_THROWING
        m.actionTimer = math.min(m.actionTimer, 3)
        return 1
    end
    m.faceAngle.y = m.intendedYaw

    set_anim_to_frame(m, 0)
    return 0;
end
ACT_PREPARE_THROW = allocate_mario_action(ACT_GROUP_STATIONARY | ACT_FLAG_MOVING)
hook_mario_action(ACT_PREPARE_THROW, act_prepare_throw)

--- @param m MarioState
function act_prepare_throw_air(m)
    if not m then return 0 end

    set_character_animation(m, CHAR_ANIM_JUMP_WITH_LIGHT_OBJ);
    update_air_without_turn(m)

    local THROW_BUTTON = ACTION_BUTTONS[gPlayerSyncTable[m.playerIndex].throwButtonIndex+1]
    if m.controller.buttonDown & THROW_BUTTON == 0 then
        m.flags = m.flags & ~MARIO_MARIO_SOUND_PLAYED
        m.action = ACT_AIR_THROW
        m.actionTimer = math.min(m.actionTimer, 3)
        return 1
    end

    m.actionTimer = m.actionTimer + 1
    if m.actionTimer > 5 then
        m.faceAngle.y = m.intendedYaw
        mario_set_forward_vel(m, 0)
    end

    local result = perform_air_step(m, 0)
    if result == AIR_STEP_LANDED then
        if (check_fall_damage_or_get_stuck(m, ACT_HARD_BACKWARD_GROUND_KB) == 0) then
            m.action = ACT_PREPARE_THROW;
        end
    elseif result == AIR_STEP_HIT_WALL then
        mario_set_forward_vel(m, 0.0)
    elseif result == AIR_STEP_HIT_LAVA_WALL then
        lava_boost_on_wall(m);
    end

    return 0;
end
ACT_PREPARE_THROW_AIR = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION | ACT_FLAG_CONTROL_JUMP_HEIGHT)
hook_mario_action(ACT_PREPARE_THROW_AIR, act_prepare_throw_air)

function on_death(m)
    if m.area.camera and m.area.camera.cutscene ~= 0 then
        m.area.camera.cutscene = 0
        play_cutscene(m.area.camera)
    end

    mario_drop_held_object(m)
    local sMario = gPlayerSyncTable[m.playerIndex]
    local spawnObj = obj_get_first_with_behavior_id_and_field_s32(id_bhvOcSpawn, 0x2F, sMario.spawnID) -- oBehParams2ndByte
    if spawnObj then
        m.pos.x, m.pos.y, m.pos.z = spawnObj.oPosX, spawnObj.oPosY, spawnObj.oPosZ
        m.faceAngle.y = spawnObj.oFaceAngleYaw
    else
        vec3f_copy(m.pos, m.spawnInfo.startPos)
        vec3s_copy(m.faceAngle, m.spawnInfo.startAngle)
    end

    set_mario_action(m, ACT_HARD_FORWARD_GROUND_KB, 0)
    mario_set_forward_vel(m, 0)

    return false
end
hook_event(HOOK_ON_DEATH, on_death)

function on_state_change(tag, oldVal, newVal)
    if oldVal == newVal or oldVal == nil or newVal == nil then return end

    if newVal == GAME_STATE_END and ((not gPlayerSyncTable[0].spectator) or (network_is_server() and gServerSettings.headlessServer ~= 0)) then
        gotNewRecord = save_new_score()
    end
end
hook_on_sync_table_change(gGlobalSyncTable, "gameState", "gameState", on_state_change)

-- keep timed things in sync
function on_time_left_change(tag, oldVal, newVal)
    if oldVal == newVal or oldVal == nil or newVal == nil then return end
    subTimer = 0

    if network_is_server() then return end
    local difference = newVal - oldVal
    for i, pending_data in ipairs(pending_orders) do
        if pending_data.time and pending_data.maxTime then
            pending_data.time = math.clamp(pending_data.time + difference * 30, 1, pending_data.maxTime)
        end
    end
end
hook_on_sync_table_change(gGlobalSyncTable, "timeLeft", "timeLeft", on_time_left_change)

-- add score changes to HUD
function on_score_change(tag, oldVal, newVal)
    if oldVal == newVal or oldVal == nil or newVal == nil then return end
    if gGlobalSyncTable.gameState ~= GAME_STATE_PLAYING then return end

    local difference = newVal - oldVal
    table.insert(scoreModifiers, {value = difference})
end
hook_on_sync_table_change(gGlobalSyncTable, "score", "score", on_score_change)

-- handle spectator being disabled
function on_spectator_change(tag, oldVal, newVal)
    if oldVal == newVal or oldVal == nil or newVal == nil then return end
    if newVal then return end

    local m = gMarioStates[0]
    m.flags = m.flags &~ MARIO_VANISH_CAP
    stayInSpectate = false

    if gGlobalSyncTable.gameState ~= GAME_STATE_PLAYING and gGlobalSyncTable.gameState ~= GAME_STATE_SETUP then return end

    if m.action & ACT_GROUP_MASK == ACT_GROUP_CUTSCENE then
        on_death(m)
    else
        drop_and_set_mario_action(m, ACT_SELECT_START, 0)
    end
    djui_chat_message_create(trans("playing_now"))
    gPlayerSyncTable[0].inPractice = false

    if get_current_menu() == 5 then
        inMenu = false
    end
end
hook_on_sync_table_change(gPlayerSyncTable[0], "spectator", "spectator", on_spectator_change)

function on_coopnet_id_change(tag, oldVal, newVal)
    if oldVal == newVal or oldVal == nil or newVal == nil then return end
    if newVal == "-1" then return end

    for i, id in ipairs(wasInGameList) do
        --log_to_console(id.." = "..newVal.." ?")
        if id == newVal then
            table.remove(wasInGameList, i)
            gPlayerSyncTable[tonumber(tag)].canRejoin = true
            break
        end
    end
end
if network_is_server() then
    for i=1,MAX_PLAYERS-1 do
        hook_on_sync_table_change(gPlayerSyncTable[i], "coopnetID", tostring(i), on_coopnet_id_change)
    end
end

function complete_save_file()
    -- 100% save
    if not save_file_get_using_backup_slot() then
        save_file_set_using_backup_slot(true)
        local file = get_current_save_file_num() - 1
        for course = 0, COURSE_MAX - 1 do
            save_file_set_star_flags(file, course, 0xFF)
        end
        save_file_set_flags(0xFFFFFFFF & ~SAVE_FLAG_MOAT_DRAINED)
        gMarioStates[0].numStars = COURSE_MAX * 7 + 7
    end
end
hook_event(HOOK_ON_MODS_LOADED, complete_save_file)

function ingredient_command(msg)
    local m = gMarioStates[0]
    local itemID = tonumber(msg) or ITEM_LETTUCE

    spawn_sync_object(id_bhvIngredient, E_MODEL_NONE, m.pos.x, m.pos.y + 50, m.pos.z, function(o)
        o.oBehParams = itemID
    end)

    return true
end

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
    if counterType == COUNTER_TYPE_SERVING or counterType == COUNTER_TYPE_SINK then
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

function start_level_command(msg)
    if gGlobalSyncTable.gameState == GAME_STATE_SETUP or gGlobalSyncTable.gameState == GAME_STATE_PLAYING then
        gGlobalSyncTable.timeLeft = 1
        return true
    end

    local oc_level = tonumber(msg) or OC_LEVEL_TEST
    if not OC_LEVEL_DATA[oc_level] then
        djui_chat_message_create("That level is not available")
        return true
    end
    gGlobalSyncTable.ocLevel = oc_level
    gGlobalSyncTable.gameState = GAME_STATE_PREPARE
    gGlobalSyncTable.timeLeft = 10
    return true
end

if _G.cheatsApi then
    if network_is_server() then
        hook_chat_command("start-level", "[ID?] - Start this level - leave blank to start the test level", start_level_command)
    end
    hook_chat_command("ingredient", "[ITEM] - Create an ingredient", ingredient_command)
    hook_chat_command("counter", "[TYPE,ITEM] - Create a counter", counter_command)
    hook_chat_command("add-order", "[ID?] - Add an order to the pending orders list - leave blank for random", add_order_command)
end

-- attempt desync fix if "desync" is said in chat
function on_chat_message(m, msg)
    if m.playerIndex ~= 0 then return end

    msg = msg:lower()
    if msg:find("desync") then
        djui_chat_message_create(trans("fix_desync"))
        attempt_desync_fix(network_global_index_from_local(0))
    end
end
hook_event(HOOK_ON_CHAT_MESSAGE, on_chat_message)