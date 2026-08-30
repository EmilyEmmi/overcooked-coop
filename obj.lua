define_custom_obj_fields({
    oContents = "u32",
    oContentCount = "u32",
    oCutOrCookTimer = "u32",
    oOvercookTimer = "u32",
    oParentSyncID = "u32",
    oUsingSyncID = "u32",
    oRespawnTimer = "u32",
    oPlateAppearTimer = "u32",
    oNotifyTimer = "u32",
    oPlateCounterNum = "u32",
    oPlatesStackedExtra = "u32",
    oParentRelativeAnglePitch = "s32",
    oParentRelativeAngleYaw = "s32",
    oParentRelativeAngleRoll = "s32",
})

---@param o Object
function bhv_ingredient_init(o)
    o.oFlags = (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    ingredient_render_setup(o)

    local hitbox = get_temp_object_hitbox()
    hitbox.radius = 37
    hitbox.height = 50
    hitbox.hurtboxRadius = 0
    hitbox.hurtboxHeight = 0
    hitbox.interactType = INTERACT_GRABBABLE
    obj_set_hitbox(o, hitbox)

    o.oGravity = 2.5
    o.oFriction = 0.8
    o.oBuoyancy = 1.4
    o.oWallHitboxRadius = 50
    o.hookRender = 0xDA
    o.activeFlags = o.activeFlags | ACTIVE_FLAG_MOVE_THROUGH_GRATE
    if o.header.gfx.sharedChild then
        o.header.gfx.sharedChild.hookProcess = 0xDA
    end
    cur_obj_become_intangible()
    cur_obj_set_home_once()

    if o.oBehParams == ITEM_PAN then
        spawn_child_object(o, id_bhvPanChild, E_MODEL_NONE, 0, 0, 0)
    end

    -- Set sync fields based on what type of item this is
    local syncFields = {"oBehParams", "oContents", "oContentCount", "oCutOrCookTimer", "oOvercookTimer", "oParentSyncID", "oUsingSyncID"}
    local iData = ITEM_DATA[o.oBehParams] or ITEM_DATA[0]
    if iData.noTrash then
        table.insert(syncFields, "oRespawnTimer")
    end
    if iData.isPlate or iData.washItem then
        table.insert(syncFields, "oPlateAppearTimer")
        table.insert(syncFields, "oPlateCounterNum")
        table.insert(syncFields, "oPlatesStackedExtra")
    end
    network_init_object(o, true, syncFields)
end

---@param o Object
function bhv_ingredient_loop(o)
    if o.activeFlags == ACTIVE_FLAG_DEACTIVATED then return end

    local iData = ITEM_DATA[o.oBehParams] or ITEM_DATA[0]
    local maxCookTime = iData.cookTime or DEFAULT_COOK_TIME
    if o.oParentSyncID == 0 and (o.oUsingSyncID == 0 or not iData.isPlate) then
        o.oPlateCounterNum = 0
        o.oPlatesStackedExtra = 0
    end

    -- update parentObj and usingObj with sync IDs
    if o.oParentSyncID ~= 0 and o.oHeldState == HELD_FREE then
        local parent = sync_object_get_object(o.oParentSyncID)
        o.parentObj = parent or o.parentObj
    end
    if o.oUsingSyncID ~= 0 then
        local using = sync_object_get_object(o.oUsingSyncID)
        if using and o.usingObj ~= using then
            o.usingObj = using
            -- mutual relationship (only top item for stack of plates)
            if o.oPlateCounterNum == 0 then
                using.usingObj = o
            end
        end
    end

    local m
    if o.oHeldState == HELD_FREE then
        if obj_has_behavior_id(o.parentObj, id_bhvMario) ~= 0 then
            o.parentObj = o
        end
        m = nearest_mario_state_to_object(o)
    else
        m = gMarioStates[o.heldByPlayerIndex]
        obj_set_pos(o, m.marioBodyState.heldObjLastPosition.x, m.marioBodyState.heldObjLastPosition.y, m.marioBodyState.heldObjLastPosition.z)
        obj_set_angle(o, 0, m.faceAngle.y, 0)
    end

    if o.oPlateAppearTimer ~= 0 then
        local isWashable = (iData.washItem ~= nil)
        o.header.gfx.node.flags = o.header.gfx.node.flags | GRAPH_RENDER_INVISIBLE
        o.oHeldState = HELD_FREE
        o.parentObj, o.oParentSyncID = nil, 0
        if o.oPlateAppearTimer == 1 or not iData.washItem then
            o.oPlateAppearTimer = o.oPlateAppearTimer - 1
        end

        if o.oPlateAppearTimer == 0 then
            -- go to nearest plate counter
            local counter = obj_get_nearest_behavior_id_with_condition(o, id_bhvCounter, function(counter)
                if iData.washItem then return counter.oBehParams2ndByte == COUNTER_TYPE_SINK end
                return counter.oBehParams2ndByte == COUNTER_TYPE_PLATES
            end)
            if counter then
                audio_sample_play(SAMPLE_PLATE_SPAWN, {x = o.oPosX, y = o.oPosY, z = o.oPosZ}, 0.5)
                local sink = (iData.washItem and counter) or (obj_get_nearest_behavior_id_with_condition(o, id_bhvCounter, function(sink)
                    return sink.oBehParams2ndByte == COUNTER_TYPE_SINK
                end))
                if sink and iData.dirtyItem then
                    o.oBehParams = iData.dirtyItem
                elseif isWashable then
                    o.oBehParams = iData.washItem
                    counter.oPlatesStackedExtra = counter.oPlatesStackedExtra - 1
                end
                iData = ITEM_DATA[o.oBehParams] or ITEM_DATA[0]

                if counter.usingObj == nil then
                    counter.usingObj = o
                    o.oPlateCounterNum, o.oPlatesStackedExtra = 0, 0

                    o.usingObj = counter
                    o.oUsingSyncID = counter.oSyncID
                    ingredient_place_on_counter(o, counter)
                elseif isWashable or not sink then
                    local otherPlates = find_all_object_using(counter, id_bhvIngredient)
                    local maxCounterNum = -1
                    for i, other in ipairs(otherPlates) do
                        if maxCounterNum < other.oPlateCounterNum then
                            maxCounterNum = other.oPlateCounterNum
                        end
                        other.oPlatesStackedExtra = #otherPlates + 1
                    end
                    o.oPlateCounterNum = maxCounterNum + 1
                    o.oPlatesStackedExtra = #otherPlates + 1

                    o.usingObj = counter
                    o.oUsingSyncID = counter.oSyncID
                    ingredient_place_on_counter(o, counter)
                else
                    o.oPlateCounterNum = #find_all_object_children(counter.usingObj, id_bhvIngredient)
                    o.parentObj = counter.usingObj
                    o.oParentSyncID = counter.usingObj.oSyncID
                end
            else
                o.oRespawnTimer = 1
            end
        end
        return
    elseif o.oRespawnTimer ~= 0 then
        o.header.gfx.node.flags = o.header.gfx.node.flags | GRAPH_RENDER_INVISIBLE
        o.oRespawnTimer = o.oRespawnTimer - 1
        o.oHeldState = HELD_FREE
        if o.oRespawnTimer == 0 then
            -- Set on counter with home closest to this object's home
            local counter = obj_get_first_with_behavior_id(id_bhvCounter)
            local selectedCounter, maxDist
            while counter do
                if (counter.usingObj == o or counter.usingObj == nil) and counter.oBehParams2ndByte ~= COUNTER_TYPE_TRASH
                and counter.oBehParams2ndByte ~= COUNTER_TYPE_SERVING and attempt_item_place(o, nil, nil, counter, false) then
                    local dist = vec3f_dist({x = o.oHomeX, y = o.oHomeY, z = o.oHomeZ}, {x = counter.oHomeX, y = counter.oHomeY, z = counter.oHomeZ})
                    if maxDist == nil or dist < maxDist then
                        maxDist = dist
                        selectedCounter = counter
                        if dist == 0 then break end
                    end
                end
                counter = obj_get_next_with_same_behavior_id(counter)
            end
            
            if selectedCounter then
                counter = selectedCounter
                obj_copy_pos(o, counter)
                o.oFaceAngleYaw = counter.oFaceAngleYaw + 0x8000
                o.usingObj = counter
                o.oUsingSyncID = counter.oSyncID
                counter.usingObj = o
                spawn_mist_particles()
            else
                o.oRespawnTimer = 30 -- retry in 1s
            end
        end
        return
    end
    o.header.gfx.node.flags = o.header.gfx.node.flags & ~GRAPH_RENDER_INVISIBLE

    -- spawn steam/smoke for cooked things
    if (o.oTimer % 10 == 0) and ((iData.cookType and o.oContentCount ~= 0 and o.oCutOrCookTimer == maxCookTime)
    or iData.isCooked or o.oContents == ITEM_BURNT) then
        local model = (o.oContents == ITEM_BURNT and E_MODEL_BURN_SMOKE) or E_MODEL_SMOKE
        spawn_child_object(o, id_bhvBlackSmokeMario, model, 0, 0, 0)
    end

    -- plated
    if o.parentObj and o.parentObj ~= o and o.oHeldState == HELD_FREE then
        if obj_has_behavior_id(o.parentObj, id_bhvIngredient) ~= 0 then
            obj_copy_pos(o, o.parentObj)
            cur_obj_become_intangible()
            return
        else
            o.parentObj, o.oParentSyncID = nil, 0
        end
    end

    -- failsafe if multiple people are holding: use gIndex priority
    if o.oHeldState ~= HELD_FREE and gMarioStates[0].heldObj == o and o.heldByPlayerIndex ~= 0 then
        local m0 = gMarioStates[0]
        if m.heldObj ~= o or network_global_index_from_local(0) < network_global_index_from_local(o.heldByPlayerIndex) then
            o.heldByPlayerIndex = 0
            m.heldObj = nil
        else
            m0.heldObj = nil
            m0.prevAction = m0.action
            m0.marioBodyState.allowPartRotation = 0
            if m0.action & ACT_FLAG_CONTROL_JUMP_HEIGHT ~= 0 then
                m0.action = ACT_JUMP
            elseif m0.action & ACT_FLAG_AIR ~= 0 then
                m0.action = ACT_FREEFALL
            elseif m0.action & ACT_FLAG_MOVING ~= 0 then
                m0.action = ACT_WALKING
            else
                m0.action = ACT_IDLE
            end
        end
    end

    if (o.oHeldState == HELD_FREE) then
        if o.usingObj == nil or o.usingObj == o then
            if iData.noHitbox then
                cur_obj_become_intangible()
            else
                cur_obj_become_tangible()
            end
            obj_resolve_object_collisions()
            local stepResult = object_step_without_floor_orient()

            local trash = false
            local height, floor = find_floor(o.oPosX, o.oPosY, o.oPosZ)
            if floor then
                if (o.oPosY == height and (floor.type == SURFACE_BURNING or surface_is_quicksand(floor)))
                or (o.oPosY < height + 2048 and (floor.type == SURFACE_DEATH_PLANE or floor.type == SURFACE_VERTICAL_WIND)) then
                    trash = true
                else
                    o.platform = floor.object
                    apply_platform_displacement(o, o.platform)
                end
            end
            if stepResult & OBJ_COL_FLAG_UNDERWATER ~= 0 then
                trash = true
            end

            if trash then
                if iData.noTrash then
                    o.oRespawnTimer = 5 * 30
                    if iData.isPlate then
                        local children = find_all_object_children(o, id_bhvIngredient)
                        for i,c in ipairs(children) do
                            obj_mark_for_deletion(c)
                        end
                    elseif iData.washItem then
                        o.oBehParams = iData.washItem
                        o.oPlateAppearTimer = o.oRespawnTimer
                        o.oRespawnTimer = 0
                        local children = find_all_object_children(o, id_bhvIngredient)
                        for i,c in ipairs(children) do
                            c.oBehParams = o.oBehParams
                            c.oPlateAppearTimer = o.oPlateAppearTimer
                            c.parentObj, c.oParentSyncID = c, 0
                        end
                    elseif o.oContentCount ~= 0 then
                        o.oContents = 0
                        o.oContentCount = 0
                        o.oCutOrCookTimer = 0
                    end

                    if m and m.playerIndex == 0 then
                        network_send_object(o, true)
                    end
                else
                    obj_mark_for_deletion(o)
                end
            else
                attempt_item_place(o, m)
            end
        else
            local counter = o.usingObj
            if counter.usingObj ~= o and o.oPlateCounterNum == 0 then
                o.usingObj = nil
                o.oUsingSyncID = 0
            else
                cur_obj_become_intangible()
                ingredient_place_on_counter(o, counter)

                if counter.oBehParams2ndByte == COUNTER_TYPE_HEAT or counter.oBehParams2ndByte == COUNTER_TYPE_OVEN or counter.oBehParams2ndByte == COUNTER_TYPE_MIXER then
                    if (o.oContentCount ~= 0 or iData.selfCookItem) and o.oContents ~= ITEM_BURNT and iData.cookType then
                        if (not iData.isCooked) and o.oCutOrCookTimer < maxCookTime then
                            o.oCutOrCookTimer = o.oCutOrCookTimer + 1
                            o.oOvercookTimer = 0

                            if o.oCutOrCookTimer == maxCookTime then
                                --djui_chat_message_create("done!")
                                o.oNotifyTimer = 30
                                cur_obj_play_sound_2(SOUND_MENU_REVERSE_PAUSE | 128)

                                if iData.selfCookItem then
                                    o.oBehParams = iData.selfCookItem
                                end
                            end
                        else -- overcook after 10 seconds
                            o.oOvercookTimer = o.oOvercookTimer + 1
                            if o.oOvercookTimer >= 5 * 30 then
                                local freq = 30
                                if o.oOvercookTimer >= 9 * 30 then
                                    freq = 5
                                elseif o.oOvercookTimer >= 7.5 * 30 then
                                    freq = 10
                                end
                                if o.oOvercookTimer % freq == 0 then
                                    o.oNotifyTimer = freq
                                    play_sound_with_freq_scale(SOUND_MOVING_ALMOST_DROWNING, o.header.gfx.cameraToObject, -2)
                                end
                            end
                            if o.oOvercookTimer >= 10 * 30 then
                                -- djui_chat_message_create("burnt")
                                o.oCutOrCookTimer = 0
                                o.oOvercookTimer = 0
                                o.oNotifyTimer = 0
                                o.oContents = ITEM_BURNT
                            end
                        end
                    end
                end

                if o.oPlatesStackedExtra ~= 0 then
                    -- update plate stack
                    local otherPlates = find_all_object_using(counter, id_bhvIngredient)
                    if o.oPlatesStackedExtra ~= #otherPlates - 1 then
                        local minCounterNum = 100
                        for i, other in ipairs(otherPlates) do
                            if minCounterNum > other.oPlateCounterNum then
                                minCounterNum = other.oPlateCounterNum
                            end
                            other.oPlatesStackedExtra = #otherPlates - 1
                        end
                        for i, other in ipairs(otherPlates) do
                            other.oPlateCounterNum = other.oPlateCounterNum - minCounterNum
                            if other.oPlateCounterNum == 0 then
                                counter.usingObj = o
                            end
                        end
                    end
                end
            end
        end
    elseif (o.oHeldState == HELD_HELD) then
        cur_obj_become_intangible()
        if o.usingObj then
            o.usingObj.usingObj = nil
            o.usingObj = nil
            o.oUsingSyncID = 0
        end

        cur_obj_disable_rendering()
    elseif (o.oHeldState == HELD_THROWN) or (o.oHeldState == HELD_DROPPED) then
        --cur_obj_enable_rendering()
        local m2 = gMarioStates[o.heldByPlayerIndex]
        o.oForwardVel = (o.oHeldState == HELD_THROWN and 60) or 0
        o.oVelY = (o.oHeldState == HELD_THROWN and 10) or 0
        o.oTimer = 0

        o.oFaceAngleYaw = o.oMoveAngleYaw
        -- consistent throwing height (based on Mario's)
        if o.oHeldState == HELD_THROWN and m2 then
            o.oPosY = m2.pos.y + 110
        end

        o.oHeldState = HELD_FREE
        if m2 and m2.playerIndex == 0 then
            network_send_object(o, true)
        end
    end

    o.oInteractStatus = 0
end

id_bhvIngredient = hook_behavior(nil, OBJ_LIST_PUSHABLE, false, bhv_ingredient_init, bhv_ingredient_loop, "bhvIngredient")

local heldObjMtx = {}
---@param o Object
function ingredient_render_setup(o)
    local iData = ITEM_DATA[o.oBehParams] or ITEM_DATA[0]
    local plated = (o.parentObj and o.parentObj ~= o and o.oHeldState == HELD_FREE)

    local oGFX = o.header.gfx
    oGFX.scale.y = iData.scale or 1
    oGFX.scale.x, oGFX.scale.z = oGFX.scale.y, oGFX.scale.y
    o.oAnimState = iData.animState or 0
    o.oGraphYOffset = iData.yOffset or 0

    -- animation
    if iData.idleAnim then
        local anim = iData.idleAnim
        local animFrame = -2
        if plated then
            anim = iData.plateAnim or anim
        elseif o.oHeldState ~= HELD_FREE then
            anim = iData.pickupAnim or anim
            animFrame = -1 -- animate normally
        elseif o.oCutOrCookTimer ~= 0 then
            anim = iData.cutAnim or anim
            local currAnimFrame = o.header.gfx.animInfo.animFrame
            local maxAnimFrame = (o.oCutOrCookTimer // 6) * 6 - 1
            animFrame = math.clamp(currAnimFrame + 1, 0, maxAnimFrame)
            if animFrame < 0 then animFrame = 0 end -- Clamp won't work fsr
        end
        smlua_anim_util_set_animation_if_new(o, anim)
        if animFrame == -2 then
            o.header.gfx.animInfo.animFrame = o.header.gfx.animInfo.curAnim.loopEnd - 1
        elseif animFrame ~= -1 then
            o.header.gfx.animInfo.animFrame = animFrame
        end
    end

    if not plated then
        oGFX.shadowInvisible = (iData.isPlate or (iData.washItem ~= nil) or false) -- temporary solution
        if iData.billboard then
            obj_set_billboard(o)
        else
            oGFX.node.flags = oGFX.node.flags & ~GRAPH_RENDER_BILLBOARD
        end
        --[[if o.oHeldState ~= HELD_FREE then
            local m = gMarioStates[o.heldByPlayerIndex]
            obj_set_pos(o, m.marioBodyState.heldObjLastPosition.x, m.marioBodyState.heldObjLastPosition.y, m.marioBodyState.heldObjLastPosition.z)
            obj_set_angle(o, 0, m.faceAngle.y, 0)
        end]]

        obj_set_model_extended(o, iData.model or E_MODEL_ERROR_MODEL)
    else -- plated
        if iData.invisOnPlate then
            obj_set_model_extended(o, E_MODEL_NONE)
            return
        elseif iData.modelOnPlate then
            obj_set_model_extended(o, iData.modelOnPlate)
        else
            obj_set_model_extended(o, iData.model or E_MODEL_ERROR_MODEL)
        end

        oGFX.node.flags = oGFX.node.flags & ~GRAPH_RENDER_BILLBOARD
        oGFX.shadowInvisible = true
        vec3f_copy(oGFX.pos, o.parentObj.header.gfx.pos)
        vec3s_copy(oGFX.angle, o.parentObj.header.gfx.angle)
        if o.parentObj.oHeldState ~= HELD_FREE and heldObjMtx then
            local mat4 = heldObjMtx[o.parentObj.heldByPlayerIndex]
            if mat4 then
                oGFX.pos.x, oGFX.pos.y, oGFX.pos.z = mat4.m30, mat4.m31, mat4.m32

                oGFX.angle.x = radians_to_sm64(math.atan(mat4.m01, mat4.m11))
                oGFX.angle.y = radians_to_sm64(math.atan(mat4.m20, mat4.m22))
                oGFX.angle.z = -radians_to_sm64(math.asin(-mat4.m21))
            end
        end

        local plateHeight = 2
        if o.oBehParams == ITEM_DIRTY_PLATE then
            plateHeight = 5 * (o.oPlateCounterNum + 1)
        elseif o.parentObj.oBehParams == ITEM_PAN then
            plateHeight = 5
        end
        oGFX.angle.y = oGFX.angle.y + o.oFaceAngleYaw
        oGFX.pos.y = oGFX.pos.y + plateHeight - o.parentObj.oGraphYOffset + (iData.plateOffset or 0)
        if iData.billboard then
            oGFX.angle.x = oGFX.angle.x - 0x4000
            -- center on plate
            oGFX.pos.x = oGFX.pos.x - (o.oGraphYOffset - 30) * sins(oGFX.angle.y)
            oGFX.pos.z = oGFX.pos.z - (o.oGraphYOffset - 30) * coss(oGFX.angle.y)
        else
            oGFX.pos.y = oGFX.pos.y + o.oGraphYOffset
        end
    end

    if iData.renderFunc then
        iData.renderFunc(o)
    end
end

-- Checks if "placedObj" can be placed on "placeOnObj" (or on closest counter), considering containers like plates
-- Returns TRUE if the object should still be held
---@param placedObj Object
---@param m MarioState?
---@param placeOnObj Object?
---@param placeOnCounter Object?
---@param isHeld boolean?
---@return boolean placeValid
---@return boolean stillHolding
function attempt_item_place(placedObj, m, placeOnObj, placeOnCounter, isHeld)
    local o = placedObj
    local o2 = placeOnObj
    if obj_has_behavior_id(o, id_bhvIngredient) == 0 then return false, false end

    local iData = ITEM_DATA[o.oBehParams] or ITEM_DATA[0]
    local counter = nil
    if o2 then
        counter = o2.usingObj
        if counter == o2 then counter = nil end
    elseif placeOnCounter then
        counter = placeOnCounter
    else
        counter = obj_get_nearest_object_with_behavior_id(o, id_bhvCounter)
        local dist = (counter and dist_between_objects(o, counter)) or 10000
        if dist > 150 or ((isHeld or o.oForwardVel < 5) and dist > 100) then return false, false end
        o2 = counter.usingObj
        -- dirty plates ignore items in sink
        if counter.oBehParams2ndByte == COUNTER_TYPE_SINK and iData.washItem then o2 = nil end

        -- empty, default counters have a smaller auto-snap range
        if (not o2) and (counter.oBehParams2ndByte == COUNTER_TYPE_DEFAULT or counter.oBehParams2ndByte == COUNTER_TYPE_INGREDIENT) and dist > 100 then return false, false end
        -- cutting boards only have large range for cuttable objects
        if counter.oBehParams2ndByte == COUNTER_TYPE_CUT and (not iData.cut) and dist > 100 then return false, false end

        -- Non-throwables will only snap to empty counters
        if (iData.noThrow or o.oContentCount ~= 0) and o2 then return false, false end
    end
    -- dirty plates ignore items in sink
    if counter and counter.oBehParams2ndByte == COUNTER_TYPE_SINK and iData.washItem then o2 = nil end

    if o2 then
        local forceCounterPlace = false
        local containerData = 0
        local containerCount = 0
        local iData2 = ITEM_DATA[o2.oBehParams] or ITEM_DATA[0]
        local valid, placeOnPlate, cookedData = check_ingredient_valid_for_place(o, o2)
        if not valid then -- Place into container on counter
            valid, placeOnPlate, cookedData = check_ingredient_valid_for_place(o2, o)
            if valid then -- Place item on counter into container
                -- swap for upcoming code
                o, o2 = o2, o
                iData, iData2 = iData2, iData
            else
                return false, true
            end
        end

        if iData.washItem and iData.washItem == iData2.washItem then
            if (not counter) and o == placedObj then
                -- swap so that the dirty plates get placed in our hand
                o, o2 = o2, o
                iData, iData2 = iData2, iData
            end

            -- Stack dirty plates
            o.oPlateCounterNum = #find_all_object_children(o2, id_bhvIngredient)
            o.parentObj = o2
            o.oParentSyncID = o2.oSyncID
            if m and m.playerIndex == 0 then network_send_object(o, true) end

            local children = find_all_object_children(o, id_bhvIngredient)
            for i, c in ipairs(children) do
                c.oPlateCounterNum = o.oPlateCounterNum + i
                c.parentObj = o2
                c.oParentSyncID = o2.oSyncID
                if m and m.playerIndex == 0 then network_send_object(c, true) end
            end
            if not counter then return true, true end
        elseif not placeOnPlate then
            -- This should only run with a container on a plate.
            -- Put stuff in the actual container instead.
            local wasPlate = iData2.isPlate
            if wasPlate then
                local children = find_all_object_children(o2, id_bhvIngredient)
                o2 = children[1]
                if o2 == nil then return false, true end
                iData2 = ITEM_DATA[o2.oBehParams] or ITEM_DATA[0]
            end
            
            local children = {o}
            if iData.pourable then
                -- treat as cooking result
                if cookedData then
                    o.oContents = cookedData.result
                    o.oContentCount = 1
                end

                containerData = o.oContents
                containerCount = o.oContentCount
                o.oContents = 0
                o.oContentCount = 0
            else
                if iData.isPlate then
                    -- Put all items on plate into container
                    children = find_all_object_children(o, id_bhvIngredient)
                    if #children == 0 then return false, true end
                end

                for i,c in ipairs(children) do
                    containerData = containerData | (c.oBehParams << (8 * containerCount))
                    containerCount = containerCount + 1
                end
            end
            
            local wasEmpty = (o2.oContentCount == 0)
            o2.oContents = o2.oContents | (containerData << (8 * o2.oContentCount))
            o2.oContentCount = o2.oContentCount + containerCount

            -- average cooking time
            if iData.pourable then
                if wasEmpty then
                    o2.oCutOrCookTimer = o.oCutOrCookTimer * 2 -- inherit cooking time
                else
                    o2.oCutOrCookTimer = o2.oCutOrCookTimer + o.oCutOrCookTimer
                end
                o.oCutOrCookTimer = 0
            end
            o2.oCutOrCookTimer = o2.oCutOrCookTimer // 2

            if m and m.playerIndex == 0 then
                network_send_object(o2, true)
                if iData.pourable then
                    return true, true
                else
                    for i,c in ipairs(children) do
                        obj_mark_for_deletion(c)
                    end
                end
            elseif iData.pourable then
                return true, true
            end
            
            if iData.isPlate then
                if wasPlate or not iData2.plateable then
                    return true, true
                else
                    o2.parentObj = o
                    o2.oParentSyncID = o.oSyncID
                    if m and m.playerIndex == 0 then
                        network_send_object(o2, true)
                    end
                    forceCounterPlace = true
                    if o2 == placedObj then return true, false end
                end
            end
        else
            local children = {o}
            if cookedData then
                -- Create new item from cookedOutput
                if m and m.playerIndex == 0 then
                    spawn_sync_object(id_bhvIngredient, E_MODEL_NONE, o.oPosX, o.oPosY, o.oPosZ, function(c)
                        c.oBehParams = cookedData.result
                        c.parentObj = o2
                        c.oParentSyncID = o2.oSyncID
                        if cookedData.inheritContents then
                            c.oContents = o.oContents
                            c.oContentCount = o.oContentCount
                        end
                    end)

                    o.oContents = 0
                    o.oContentCount = 0
                    o.oCutOrCookTimer = 0
                    network_send_object(o, true)
                else
                    o.oContents = 0
                    o.oContentCount = 0
                    o.oCutOrCookTimer = 0
                end

                return true, true
            elseif iData.isPlate then
                children = find_all_object_children(o, id_bhvIngredient)
            end
            
            for i,c in ipairs(children) do
                c.parentObj = o2
                c.oParentSyncID = o2.oSyncID
                c.usingObj, c.oUsingSyncID = nil, 0
                if m and m.playerIndex == 0 then
                    network_send_object(c, true)
                end
            end

            if iData.isPlate or o == placedObj then
                return true, (iData.isPlate)
            elseif iData2.isPlate and o2 == placedObj and m and isHeld
            and (not gPlayerSyncTable[m.playerIndex].oldPlatePlace) then
                return true, true -- Keep holding plate
            end
        end
        if o == placedObj and not forceCounterPlace then return true, false end
    end

    if counter then
        o = placedObj
        iData = ITEM_DATA[o.oBehParams] or ITEM_DATA[0]
        local allowPlace = check_counter_valid_interact(counter, o)
        if not allowPlace then
            if counter.oBehParams2ndByte == COUNTER_TYPE_SERVING
            and m and m.playerIndex == 0 and isHeld then
                djui_chat_message_create(trans("Needs plate!"))
                return true, true
            end
            return (o2 ~= nil), true
        end
    
        if counter.oBehParams2ndByte == COUNTER_TYPE_TRASH then
            if iData.noTrash then
                if o.oHeldState ~= HELD_FREE then
                    if iData.isPlate then
                        local children = find_all_object_children(o, id_bhvIngredient)
                        for i,c in ipairs(children) do
                            obj_mark_for_deletion(c)
                        end
                    elseif o.oContentCount ~= 0 then
                        o.oContents = 0
                        o.oContentCount = 0
                        o.oCutOrCookTimer = 0
                    end
                    if m and m.playerIndex == 0 then
                        network_send_object(o, true)
                    end
                end
                return true, true
            else
                if m and m.playerIndex == 0 then
                    obj_mark_for_deletion(o)
                end
                return true, false
            end
        elseif counter.oBehParams2ndByte == COUNTER_TYPE_SERVING then
            o.oPlateAppearTimer = 5 * 30
            o.usingObj, o.oUsingSyncID = nil, 0
            if m and m.playerIndex == 0 then
                local items = {}
                local children = find_all_object_children(o, id_bhvIngredient)
                for i,c in ipairs(children) do
                    table.insert(items, {type = c.oBehParams, contents = c.oContents, contentCount = c.oContentCount})
                    obj_mark_for_deletion(c)
                end

                attempt_serve_order(items)
                network_send_object(o, true)
            end
            return true, false
        elseif counter.oBehParams2ndByte == COUNTER_TYPE_SINK then
            local plates = 1
            local children = find_all_object_children(o, id_bhvIngredient)
            for i,c in ipairs(children) do
                c.parentObj = c
                c.oParentSyncID = 0
                c.oPlateAppearTimer = 5 * 30
                plates = plates + 1
                if m and m.playerIndex == 0 then network_send_object(c, true) end
            end

            o.oPlateAppearTimer = 5 * 30
            counter.oPlatesStackedExtra = counter.oPlatesStackedExtra + plates
            if m and m.playerIndex == 0 then
                network_send_object(o, true)
                network_send_object(counter, true)
            end
            return true, false
        end

        counter.usingObj = o
        o.usingObj = counter
        o.oUsingSyncID = counter.oSyncID
        ingredient_place_on_counter(o, counter)
        if m and m.playerIndex == 0 then
            network_send_object(o, true)
        end
        return true, false
    end

    return true, true
end

-- check if o can be placed on/in o2
function check_ingredient_valid_for_place(o, o2, onPlate)
    local iData = ITEM_DATA[o.oBehParams] or ITEM_DATA[0]
    local iData2 = ITEM_DATA[o2.oBehParams] or ITEM_DATA[0]
    if iData.washItem or iData2.washItem then
        -- allow stacking dirty plates
        if not (iData.washItem and iData2.washItem) then return end

        return (iData.washItem == iData2.washItem), false
    elseif iData.isPlate or iData2.isPlate then
        if onPlate then return false, false end

        local children2 = {o2}
        if iData2.isPlate then
            children2 = find_all_object_children(o2, id_bhvIngredient)
            if #children2 == 0 and (iData.isPlate or iData.plateable) then
                return true, true -- Plating is always legal if there are no children
            end

            -- If any child is a container, check that instead
            for i,c2 in ipairs(children2) do
                local iDataC2 = ITEM_DATA[c2.oBehParams] or ITEM_DATA[0]
                if iDataC2.contentSlots and iDataC2.contentSlots ~= 0 then
                    return check_ingredient_valid_for_place(o, c2, false)
                end
            end
        end

        -- put cooked result on plate if it exists
        if not (iData.isPlate or iData.plateable) then
            if #children2 ~= 0 then return false, false end
            local cookedData = get_cooked_data(o)
            return (cookedData ~= nil), (cookedData ~= nil), cookedData
        end

        local children = {o}
        if iData.isPlate then
            children = find_all_object_children(o, id_bhvIngredient)
            if #children == 0 then return false, false end -- Empty plate has nothing to transfer
        end
        
        if iData.contentSlots then
            if o.oContents == ITEM_BURNT or (#children2 + o.oContentCount) > iData.contentSlots then return false, false end
        elseif iData2.contentSlots then
            if o2.oContents == ITEM_BURNT or (#children + o2.oContentCount) > iData2.contentSlots then return false, false end
        end

        local forcePlate = nil
        local typeCount = {}
        for i,c in ipairs(children) do
            -- count this unit as one towards the plate count
            if iData2.isPlate then
                local iDataC = ITEM_DATA[c.oBehParams] or ITEM_DATA[0]
                if iDataC.plateCombine == nil then return false, false end
                local countForType = iDataC.plateCombine[c.oBehParams] or 0
                if countForType == 0 then
                    return false, false
                elseif not typeCount[c.oBehParams] then
                    typeCount[c.oBehParams] = 0
                end
                typeCount[c.oBehParams] = typeCount[c.oBehParams] + 1
            end

            for i,c2 in ipairs(children2) do
                local iDataC2 = ITEM_DATA[c2.oBehParams] or ITEM_DATA[0]
                if (forcePlate ~= false) and iData2.isPlate and iDataC2.plateCombine and iDataC2.plateCombine[c2.oBehParams] then -- for salads
                    local countForType2 = iDataC2.plateCombine[c2.oBehParams] or 0
                    if countForType2 == 0 then
                        return false, false
                    elseif not typeCount[c2.oBehParams] then
                        typeCount[c2.oBehParams] = 0
                    end

                    typeCount[c2.oBehParams] = typeCount[c2.oBehParams] + 1
                    if typeCount[c2.oBehParams] > countForType2 then
                        return false, false
                    end
                    forcePlate = true
                elseif (forcePlate ~= true) and not check_ingredient_valid_for_place(c, c2, true) then
                    return false, false
                else
                    forcePlate = false
                end
            end
        end
        return true, (forcePlate or false)
    elseif iData.pourable and o.oContentCount ~= 0 then
        if iData2.accepts == nil or o2.oContents == ITEM_BURNT then return false, false end

        -- set up contents in a table
        local ingredients = {}
        local cookedData = get_cooked_data(o)
        local contentCount = o.oContentCount
        if cookedData and cookedData.result then
            contentCount = 1
            table.insert(ingredients, cookedData.result)
        else
            if o.oContents == ITEM_BURNT then return false, false end
            for i=0,o.oContentCount-1 do
                local ingredient = (o.oContents >> (8 * i)) & 0xFF
                table.insert(ingredients, ingredient)
            end
        end
        if (o2.oContentCount + contentCount) > iData2.contentSlots then return false, false end

        -- Test each ingredient
        local testedCount = {}
        for i, ingredient in ipairs(ingredients) do
            local maxCount = iData2.accepts[ingredient]
            if not maxCount then return false, false end

            -- Count how many of an ingredient we already have
            if maxCount ~= 0 then
                local count = testedCount[ingredient]
                if not count then
                    count = 0
                    for j=0,o2.oContentCount-1 do
                        local ingredient2 = (o2.oContents >> (8 * j)) & 0xFF
                        if ingredient2 == ingredient then
                            count = count + 1
                        end
                        if count >= maxCount then return false, false end
                    end
                end
                count = count + 1
                if count > maxCount then return false, false end
                testedCount[ingredient] = count
            end
        end
        return true, false, cookedData
    end

    if (iData2.accepts and iData2.accepts[o.oBehParams] and iData2.contentSlots and o2.oContentCount < iData2.contentSlots and o2.oContents ~= ITEM_BURNT) then
        local maxCount = iData2.accepts[o.oBehParams]
        if maxCount == 0 then return true, false end

        -- Count how many of an ingredient we already have
        local count = 0
        for i=0,o2.oContentCount-1 do
            local ingredient = (o2.oContents >> (8 * i)) & 0xFF
            if ingredient == o.oBehParams then
                count = count + 1
            end
            if count >= maxCount then return false, false end
        end
        return true, false
    end
    return false, false
end

-- check if o can be placed on the counter
function check_counter_valid_interact(counter, o)
    if o == nil then return true end -- interact with any counter while not holding something

    local iData = ITEM_DATA[o.oBehParams]
    if counter.oBehParams2ndByte == COUNTER_TYPE_HEAT then
        return (iData.cookType == COOK_TYPE_HEAT)
    elseif counter.oBehParams2ndByte == COUNTER_TYPE_SERVING then
        return iData.isPlate or false
    elseif counter.oBehParams2ndByte == COUNTER_TYPE_PLATES then
        return false
    elseif counter.oBehParams2ndByte == COUNTER_TYPE_SINK then
        return (iData.washItem ~= nil)
    elseif counter.oBehParams2ndByte == COUNTER_TYPE_OVEN then
        return (iData.cookType == COOK_TYPE_OVEN)
    end

    return true
end

---@param o Object
function get_cooked_data(o)
    local iData = ITEM_DATA[o.oBehParams] or ITEM_DATA[0]
    local maxCookTime = iData.cookTime or DEFAULT_COOK_TIME
    if COOKED_DATA[o.oBehParams] and o.oContentCount ~= 0 and o.oCutOrCookTimer >= maxCookTime then
        -- Change o.oContents to a table format, and compare it to the cooking possibilities.
        -- If the tables contain the same contents, return the entire data table to be used in attempt_item_place
        local contentTable = {}
        for i=0,o.oContentCount-1 do
            local ingredient = (o.oContents >> (8 * i)) & 0xFF
            table.insert(contentTable, ingredient)
        end

        for i,cookedData in ipairs(COOKED_DATA[o.oBehParams]) do
            if cookedData.items == nil or tables_contain_same_elements(contentTable, cookedData.items) then
                return cookedData
            end
        end
    end
end

function attempt_serve_order(items)
    local testingServe = (gGlobalSyncTable.gameState == GAME_STATE_LEVEL_SELECT or gPlayerSyncTable[0].inPractice)

    audio_sample_play(SAMPLE_SERVE, gLakituState.pos, 0.5)
    if #items == 0 then
        djui_chat_message_create("Plate is empty")
        return false
    elseif #pending_orders == 0 and not testingServe then
        djui_chat_message_create("No orders available")
        return false
    end

    local item_lookup = {}
    for a, item in ipairs(items) do
        if item_lookup[item.type] == nil then
            item_lookup[item.type] = {}
        end

        -- Table format for contents
        local contentTable = {}
        for i=0,item.contentCount-1 do
            local ingredient = (item.contents >> (8 * i)) & 0xFF
            table.insert(contentTable, ingredient)
        end

        table.insert(item_lookup[item.type], contentTable)
    end
    
    local pending_orders = pending_orders_all[gPlayerSyncTable[0].kitchen] or {}
    if testingServe then
        pending_orders = {}
        for i, orderID in ipairs(ALL_ORDERS) do
            table.insert(pending_orders, {id = orderID})
        end
    end
    for a,pending_data in ipairs(pending_orders) do
        local orderID = pending_data.id or ORDER_PLAIN_SALAD
        local order = ORDER_DATA[orderID]
        if order and #order.items == #items and pending_data.vanishTimer == nil then
            local valid = true
            for a, item in ipairs(order.items) do
                valid = false
                if item_lookup[item.type] == nil then break end

                for i, contentTable in ipairs(item_lookup[item.type]) do
                    local hasValidContents = true
                    if #contentTable ~= 0 then
                        hasValidContents = (item.contents and tables_contain_same_elements(contentTable, item.contents))
                    elseif item.contents and #item.contents ~= 0 then
                        hasValidContents = false
                    end

                    if hasValidContents then
                        valid = true
                        break
                    end
                end
            end

            if valid then
                if testingServe then
                    djui_chat_message_create(trans("served", order.name))
                else
                    network_send_include_self(true, {id = PACKET_SERVED_ORDER, orderID = orderID, from = network_global_index_from_local(0)})
                end
                return true
            end
        end
    end

    if testingServe then
        djui_chat_message_create(trans("dish_not_valid"))
    else
        djui_chat_message_create(trans("order_not_availble"))
        for a,pending_data in ipairs(pending_orders) do
            pending_data.redTimer = 30
        end
    end

    return false
end

function ingredient_place_on_counter(o, counter)
    o.oForwardVel = 0
    o.oVelY = 0
    obj_copy_pos(o, counter)
    if counter.oBehParams2ndByte == COUNTER_TYPE_SINK then
        o.oPosX = o.oPosX + coss(counter.oFaceAngleYaw) * 52
        o.oPosZ = o.oPosZ - sins(counter.oFaceAngleYaw) * 52
    end

    local height = (COUNTER_HEIGHT[counter.oBehParams2ndByte] or 34) * counter.header.gfx.scale.y
    if o.oPlatesStackedExtra ~= 0 then
        height = height + (o.oPlatesStackedExtra - o.oPlateCounterNum) * 5
    end
    o.oPosY = o.oPosY + height
    o.oFaceAngleYaw = o.oFaceAngleYaw + counter.oAngleVelYaw
end

---@param o Object
function bhv_counter_init(o)
    o.oFlags = o.oFlags | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_scale_xyz(o, 1.5, 1.6, 1.5)

    o.oCollisionDistance = 10000
    o.collisionData = smlua_collision_util_get("main_counter_center_collision")
    cur_obj_set_home_once()

    if o.oBehParams2ndByte == COUNTER_TYPE_CUT then
        spawn_child_object(o, id_bhvCuttingBoard, E_MODEL_CHOPPING_BOARD, 0, 0, 0, nil)
    elseif o.oBehParams2ndByte == COUNTER_TYPE_MIXER then
        spawn_child_object(o, id_bhvCuttingBoard, E_MODEL_MIXER, 0, 0, 0, nil)
    elseif o.oBehParams2ndByte == COUNTER_TYPE_SERVING or o.oBehParams2ndByte == COUNTER_TYPE_SINK then
        o.collisionData = smlua_collision_util_get("sink_collision")
    elseif o.oBehParams2ndByte == COUNTER_TYPE_OVEN then
        o.collisionData = smlua_collision_util_get("oven_collision")
    end

    local syncFields = {}
    if o.oBehParams2ndByte == COUNTER_TYPE_INGREDIENT then
        table.insert(syncFields, "oOvercookTimer")
    elseif o.oBehParams2ndByte == COUNTER_TYPE_SINK then
        table.insert(syncFields, "oPlatesStackedExtra")
        table.insert(syncFields, "oPlateAppearTimer")
    end
    network_init_object(o, false, syncFields)
end

---@param o Object
function bhv_counter_loop(o)
    obj_pair_with_parent(o)
    load_object_collision_model()

    -- validate object on counter
    if o.usingObj and o.usingObj ~= o and (o.usingObj.usingObj ~= o or o.oSyncID ~= 0 and o.usingObj.oUsingSyncID ~= o.oSyncID) then
        o.usingObj = nil
    end

    if o.oBehParams2ndByte == COUNTER_TYPE_HEAT then
        local heatOn = false
        local cookSound = SOUND_MOVING_LAVA_BURN
        local cookSoundChance = 1
        if o.usingObj and o.usingObj ~= o then
            local iData = ITEM_DATA[o.usingObj.oBehParams] or ITEM_DATA[0]
            if iData.cookType == COOK_TYPE_HEAT and (o.usingObj.oContentCount ~= 0 or iData.selfCookItem) then
                heatOn = true
                cookSound = iData.cookSound or cookSound
                cookSoundChance = iData.cookSoundChance or cookSoundChance
            end
        end
        if heatOn then
            smlua_anim_util_set_animation_if_new(o, "heat_on")
            if cur_obj_check_if_at_animation_end() ~= 0 then
                o.header.gfx.animInfo.animFrame = 0
            end
            if cookSoundChance == 1 or random_float() < cookSoundChance then
                cur_obj_play_sound_2(cookSound)
            end
        else
            smlua_anim_util_set_animation_if_new(o, "heat_off")
        end
    elseif o.oBehParams2ndByte == COUNTER_TYPE_INGREDIENT then
        if o.oOvercookTimer ~= 0 then
            o.oOvercookTimer = 0
            smlua_anim_util_set_animation_if_new(o, "box_open")
        elseif cur_obj_check_if_at_animation_end() ~= 0 then
            smlua_anim_util_set_animation_if_new(o, "box_closed")
            if is_nearest_mario_state_to_object(gMarioStates[0], o) then
                network_send_object(o, false)
            end
        end
    elseif o.oBehParams2ndByte == COUNTER_TYPE_SINK then
        if o.oPlatesStackedExtra == 0 then o.oPlateAppearTimer = 0 end
        smlua_anim_util_set_animation(o, "sink_plate_"..math.min(o.oPlatesStackedExtra, 3))
    elseif o.oBehParams2ndByte == COUNTER_TYPE_OVEN then
        local heatOn = false
        local cookSound = SOUND_ENV_WATERFALL1 -- ???
        local cookSoundChance = 1
        if o.usingObj and o.usingObj ~= o then
            local iData = ITEM_DATA[o.usingObj.oBehParams] or ITEM_DATA[0]
            if iData.cookType == COOK_TYPE_OVEN and (o.usingObj.oContentCount ~= 0 or iData.selfCookItem) then
                heatOn = true
                cookSound = iData.cookSound or cookSound
                cookSoundChance = iData.cookSoundChance or cookSoundChance
            end
        end

        local set = false
        if heatOn then
            set = smlua_anim_util_set_animation_if_new(o, "oven_close")
            if cookSoundChance == 1 or random_float() < cookSoundChance then
                cur_obj_play_sound_2(cookSound)
            end
        else
            set = smlua_anim_util_set_animation_if_new(o, "oven_open")
        end
        if set and o.oTimer > 1 then
            local sample = (heatOn and SAMPLE_OVEN_CLOSE) or SAMPLE_OVEN_OPEN
            audio_sample_play(sample, {x = o.oPosX, y = o.oPosY, z = o.oPosZ}, 0.5)
        end
    end
end

id_bhvCounter = hook_behavior(nil, OBJ_LIST_SURFACE, false, bhv_counter_init, bhv_counter_loop, "bhvCounter")

function bhv_cutting_board_init(o)
    o.oFlags = o.oFlags | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_scale_xyz(o, 1.5, 1.6, 1.5)
end

function bhv_cutting_board_loop(o)
    if o.parentObj == o or o.parentObj == nil or obj_has_behavior_id(o.parentObj, id_bhvCounter) == 0 then
        obj_mark_for_deletion(o)
        return
    end

    obj_copy_pos_and_angle(o, o.parentObj)
end

id_bhvCuttingBoard = hook_behavior(nil, OBJ_LIST_GENACTOR, false, bhv_cutting_board_init, bhv_cutting_board_loop, "bhvCuttingBoard")

function bhv_knife_init(o)
    --o.oFlags = o.oFlags | (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    o.hookRender = 0xDA

    cur_obj_scale(1.5)
    cur_obj_disable_rendering()
end

function bhv_knife_loop(o)
    local np = network_player_from_global_index(o.globalPlayerIndex)
    if not (np and np.connected) then
        cur_obj_disable_rendering()
        return
    end
    
    local m = gMarioStates[np.localIndex]
    local sMario = gPlayerSyncTable[np.localIndex]

    if is_player_active(m) ~= 0 and (sMario.cutTimer ~= 0) then
        cur_obj_enable_rendering()
    else
        cur_obj_disable_rendering()
    end
end

id_bhvKnife = hook_behavior(nil, OBJ_LIST_GENACTOR, false, bhv_knife_init, bhv_knife_loop, "bhvKnife")

function bhv_pan_child_init(o)
    o.hookRender = 0xDA
end

function bhv_pan_child_loop(o)
    if o.parentObj == o or o.parentObj == nil or obj_has_behavior_id(o.parentObj, id_bhvIngredient) == 0 then
        obj_mark_for_deletion(o)
        return
    end

    if o.parentObj.oContentCount == 0 then
        cur_obj_disable_rendering()
    else
        -- render as first item or cooking result
        local cookedData = get_cooked_data(o.parentObj)
        o.oBehParams = (cookedData and cookedData.result) or (o.parentObj.oContents & 0xFF)
        if obj_is_rendering_enabled() == 0 then
            cur_obj_enable_rendering()
            ingredient_render_setup(o)
        end
    end

    obj_copy_pos(o, o.parentObj)
end

id_bhvPanChild = hook_behavior(nil, OBJ_LIST_GENACTOR, false, bhv_pan_child_init, bhv_pan_child_loop, "bhvPanChild")

function bhv_player_barrier_init(o)
    o.oFlags = o.oFlags | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_scale_xyz(o, o.oBehParams2ndByte * 1.04, 1, 1)

    o.collisionData = smlua_collision_util_get("barrier_collision")
    o.oCollisionDistance = 10000 -- don't disable collision
    o.header.gfx.skipInViewCheck = true
end

function bhv_player_barrier_loop(o)
    obj_pair_with_parent(o)

    local width = o.oBehParams2ndByte
    if not is_active_player_in_area(2) then
        width = (o.oBehParams & 0xFF) -- use byte 4 instead of byte 2 if there's only one player here
    end

    if width ~= 0 then
        obj_scale_xyz(o, width * 1.04, 1, 1)
        load_object_collision_model()
        cur_obj_enable_rendering()
    else
        cur_obj_disable_rendering()
    end
end

id_bhvPlayerBarrier = hook_behavior(nil, OBJ_LIST_SURFACE, false, bhv_player_barrier_init, bhv_player_barrier_loop, "bhvPlayerBarrier")

-- Uses to handle player spawns- other than attaching to platforms, it doesn't do anything else
---@param o Object
function oc_spawn_init(o)
    -- I was originally using param 4 instead of param 2.
    -- This function moves param 4 to param 2 so I don't need to worry about it.
    if o.oBehParams & 0xFF ~= 0 and o.oBehParams2ndByte == 0 then
        o.oBehParams2ndByte = o.oBehParams & 0xFF
        o.oBehParams = o.oBehParams2ndByte << 16
    end
end

---@param o Object
function oc_spawn_loop(o)
    obj_pair_with_parent(o)
    --spawn_non_sync_object(id_bhvSparkleSpawn, E_MODEL_NONE, o.oPosX, o.oPosY, o.oPosZ, nil)
end

id_bhvOcSpawn = hook_behavior(nil, OBJ_LIST_DEFAULT, false, oc_spawn_init, oc_spawn_loop, "bhvOcSpawn")

-- controls the movement of the counters/barriers in the ship level
---@param o Object
function ship_movement_controller_init(o)
    o.oForwardVel = 0
    cur_obj_set_home_once()
end

---@param o Object
function ship_movement_controller_loop(o)
    local correctPos = {x = o.oHomeX, y = o.oHomeY, z = o.oHomeZ}
    if o.oAction ~= 0 then
        correctPos.x = correctPos.x + sins(o.oFaceAngleYaw) * o.oBehParams2ndByte * 104
        correctPos.z = correctPos.z + coss(o.oFaceAngleYaw) * o.oBehParams2ndByte * 104
    end

    -- move back and forth
    local dist = dist_between_object_and_point(o, correctPos.x, correctPos.y, correctPos.z)
    if dist > 1 then
        if dist <= 55 and o.oForwardVel > 0 then
            o.oForwardVel = o.oForwardVel - 1
        elseif o.oForwardVel < 10 then
            o.oForwardVel = o.oForwardVel + 1
        end
        o.oMoveAngleYaw = o.oFaceAngleYaw
        if o.oAction == 0 then o.oMoveAngleYaw = o.oMoveAngleYaw + 0x8000 end
        cur_obj_move_xz_using_fvel_and_yaw()
        cur_obj_play_sound_2(SOUND_ENV_BOAT_ROCKING1)
    else
        o.oForwardVel, o.oVelX, o.oVelY, o.oVelZ = 0, 0, 0, 0
        obj_set_pos(o, correctPos.x, correctPos.y, correctPos.z)
    end

    -- shift if not currently moving every 30s 
    if o.oForwardVel == 0 and gGlobalSyncTable.gameState == GAME_STATE_PLAYING then
        local maxTime = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel].totalTime or 240
        local newAction = ((maxTime - gGlobalSyncTable.timeLeft) // 30) % 2
        if o.oAction ~= newAction then
            cur_obj_change_action(newAction)
        end
    end
end
id_bhvShipMovementController = hook_behavior(nil, OBJ_LIST_DEFAULT, false, ship_movement_controller_init, ship_movement_controller_loop, "bhvShipMovementController")

-- water in the ship level
function rocking_water_init(o)
    o.oFlags = o.oFlags | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.header.gfx.skipInViewCheck = true
end

function rocking_water_loop(o)
    if disableWaterEffect then
        o.oFaceAnglePitch, o.oAngleVelPitch = 0, 0
        return
    end

    if o.parentObj == nil or o.parentObj == o then
        o.parentObj = obj_get_first_with_behavior_id(id_bhvShipMovementController)
    end
    if o.parentObj == nil or o.parentObj == o then return end

    local doRock = (o.parentObj.oForwardVel ~= 0)
    local newAction = o.parentObj.oAction
    if gGlobalSyncTable.gameState == GAME_STATE_PLAYING then
        local maxTime = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel].totalTime or 240
        newAction = ((maxTime - gGlobalSyncTable.timeLeft - 3) // 30) % 2
        doRock = doRock or (newAction ~= o.parentObj.oAction)
    end
    if doRock then
        o.oAction = 2
    elseif o.oAction == 2 then
        o.oAction = 1 - o.parentObj.oAction
    end

    local distFromTarget = 0
    local target = 0
    local change = 1
    if o.oAction ~= 2 then
        target = (o.oAction == 0 and -1) or 1
        target = target * 0x500
        distFromTarget = abs_angle_diff(o.oFaceAnglePitch, target)
        --djui_chat_message_create(tostring(distFromTarget))
        if distFromTarget < 0x20 then
            o.oAction = 1 - o.oAction
        end
    else
        target = (newAction ~= 0 and -1) or 1
        target = target * 0x900
        change = 2
        distFromTarget = abs_angle_diff(o.oFaceAnglePitch, target)
    end

    change = change * math.sign(target - o.oFaceAnglePitch)
    o.oAngleVelPitch = math.clamp(o.oAngleVelPitch + change, -0x20, 0x20)

    o.oFaceAnglePitch = o.oFaceAnglePitch + o.oAngleVelPitch
end
id_bhvRockingWater = hook_behavior(nil, OBJ_LIST_DEFAULT, false, rocking_water_init, rocking_water_loop, "bhvRockingWater")

-- Moving carpets in the sky level
local CARPET_POSITIONS = {
    {
        {-768, 0, 612, 0},
        {-500, 250, 468, -0x4000},
        {0, 750, 1404, 0x4000},
    },
    {
        {768, 0, 612, 0},
        {500, 0, 468, 0x4000},
        {0, 500, 468, 0x4000},
    },
    {
        {-768, 0, -612, 0},
        {-500, 250, -468, 0x4000},
        {0, 250, -468, -0x4000},
    },
    {
        {768, 0, -612, 0},
        {500, 0, -468, -0x4000},
        {0, 0, -1404, -0x4000},
    },
}

---@param o Object
function oc_carpet_init(o)
    o.oFlags = o.oFlags | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("rr_seg7_collision_07029038")
    obj_set_model_extended(o, E_MODEL_RR_FLYING_CARPET)
    obj_scale_xyz(o, 1.54, 0.5, 1.54)

    cur_obj_set_home_once()
    --o.oPosY = o.oPosY - 26 * o.header.gfx.scale.y
    o.oParentRelativeAngleYaw = o.oFaceAngleYaw -- starting angle
    o.oPlatformOnTrackOffsetY = 0
    o.header.gfx.skipInViewCheck = true
end

---@param o Object
function oc_carpet_loop(o)
    local carpetID = (o.oBehParams >> 8) & 0xFF
    local posList = CARPET_POSITIONS[carpetID] or CARPET_POSITIONS[1]
    local posInSequence = 0
    if gGlobalSyncTable.gameState == GAME_STATE_PLAYING then
        local maxTime = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel].totalTime or 240
        posInSequence = ((maxTime - gGlobalSyncTable.timeLeft) // 30) % (#posList + 1)
    end

    local curCarpetPos
    if posInSequence ~= 0 and o.oTimer > 1 then
        curCarpetPos = posList[posInSequence]
    else
        curCarpetPos = {o.oHomeX, o.oHomeY, o.oHomeZ, o.oParentRelativeAngleYaw}
    end

    -- move to correct position
    local correctPos = {x = curCarpetPos[1], y = curCarpetPos[2], z = curCarpetPos[3]}
    --correctPos.y = correctPos.y - 26 * o.header.gfx.scale.y
    local correctAngle = curCarpetPos[4]
    local dist = dist_between_object_and_point(o, correctPos.x, correctPos.y, correctPos.z)
    if dist > 1 then
        local latDist = dist_between_object_and_point(o, correctPos.x, o.oPosY, correctPos.z)
        o.oMoveAngleYaw = obj_angle_to_point(o, correctPos.x, correctPos.z)
        o.oForwardVel = math.min(latDist, 5)
        o.oVelY = math.clamp(correctPos.y - o.oPosY, -5, 5)
        cur_obj_move_xz_using_fvel_and_yaw()
        o.oPosY = o.oPosY + o.oVelY
    else
        o.oForwardVel, o.oVelX, o.oVelY, o.oVelZ = 0, 0, 0, 0
        obj_set_pos(o, correctPos.x, correctPos.y, correctPos.z)
    end

    local yawSpeed = abs_angle_diff(correctAngle, o.oFaceAngleYaw) / 40
    if yawSpeed ~= 0 then
        local initialAngle = o.oFaceAngleYaw
        yawSpeed = math.clamp(yawSpeed, 50, 250)
        obj_face_yaw_approach(correctAngle, yawSpeed)
        o.oAngleVelYaw = limit_angle(o.oFaceAngleYaw - initialAngle)
    else
        o.oAngleVelYaw = 0
    end

    load_object_collision_model()
end
id_bhvOcCarpet = hook_behavior(nil, OBJ_LIST_SURFACE, false, oc_carpet_init, oc_carpet_loop, "bhvOcCarpet")

-- version of BitFS Sinking Cage Platform without the pole
---@param o Object
function falling_rising_platform_init(o)
    o.oFlags = o.oFlags | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = gGlobalObjectCollisionData.bitfs_seg7_collision_sinking_cage_platform
    cur_obj_set_home_once()
end

---@param o Object
function falling_rising_platform_loop(o)
    bhv_bitfs_sinking_cage_platform_loop()
    load_object_collision_model()
end
id_bhvFallingRisingPlatform = hook_behavior(nil, OBJ_LIST_SURFACE, false, falling_rising_platform_init, falling_rising_platform_loop, "bhvFallingRisingPlatform")

-- fix rotation based on network_area_timer to reduce desyncs between players
---@param o Object
function custom_rotating_platform_loop(o)
    local angleYaw = (o.oBehParams >> 24) << 4;
    local expectedYaw = limit_angle(get_network_area_timer() * angleYaw)
    if abs_angle_diff(o.oFaceAngleYaw, expectedYaw) >= angleYaw * 10 then -- off by 10 frames or more
        o.oFaceAngleYaw = expectedYaw
        --o.oAngleVelYaw = expectedYaw - o.oFaceAngleYaw -- Also moves items- commented out to be less disruptive
    end
end
hook_behavior(id_bhvRotatingPlatform, OBJ_LIST_SURFACE, false, nil, custom_rotating_platform_loop)

-- same as above
---@param o Object
function custom_merry_go_round_loop(o)
    if o.oTimer <= 1 then
        o.oMoveAngleYaw = 0
        o.oFaceAngleYaw = 0
        o.oAngleVelYaw = 0
    end

    local angleYaw = o.oAngleVelYaw;
    local expectedYaw = limit_angle(get_network_area_timer() * angleYaw)
    if abs_angle_diff(o.oFaceAngleYaw, expectedYaw) >= angleYaw * 10 then -- off by 10 frames or more
        o.oFaceAngleYaw = expectedYaw
        --o.oAngleVelYaw = expectedYaw - o.oFaceAngleYaw -- Also moves items- commented out to be less disruptive
    end
end
hook_behavior(id_bhvMerryGoRound, OBJ_LIST_SURFACE, false, nil, custom_merry_go_round_loop)

-- make puzzle pieces move more slowly
---@param o Object
function custom_puzzle_piece_init(o)
    o.oFlags = o.oFlags | (OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    o.collisionData = gGlobalObjectCollisionData.lll_seg7_collision_puzzle_piece
    cur_obj_set_home_once()
    o.oCollisionDistance = 3000
end

---@param o Object
function custom_puzzle_piece_loop(o)
    -- skip spawning coins
    if o.parentObj and o.parentObj ~= o and o.parentObj.oAction == BOWSER_PUZZLE_ACT_WAIT_FOR_COMPLETE then
        o.parentObj.oAction = BOWSER_PUZZLE_ACT_DONE
    end

    if o.oBowserPuzzlePieceContinuePerformingAction == 0 then
        bhv_lll_bowser_puzzle_piece_loop()
        if o.oBowserPuzzlePieceContinuePerformingAction == 0 then return end
    end

    -- normally 20 frames, now uses 60 (2 seconds)
    if (o.oTimer < 60) then
        -- more obvious movement tell
        if o.oAction ~= 2 then
            o.oBowserPuzzlePieceOffsetY = sins(o.oTimer * 0x1000) * 10
        end

        o.oPosX = o.oBowserPuzzlePieceOffsetX + o.oHomeX
        o.oPosY = o.oBowserPuzzlePieceOffsetY + o.oHomeY
        o.oPosZ = o.oBowserPuzzlePieceOffsetZ + o.oHomeZ
    else
        o.oBowserPuzzlePieceOffsetY = 0.0
        o.oTimer = o.oTimer - 40
        bhv_lll_bowser_puzzle_piece_loop()
        o.oTimer = o.oTimer + 40
    end
end
hook_behavior(id_bhvLllBowserPuzzlePiece, OBJ_LIST_SURFACE, true, custom_puzzle_piece_init, custom_puzzle_piece_loop)

-- Pair with object that has param 3 set to the same value as this object's param 1
-- (param 3 is used because the rotating platforms in WF use param 1 for the speed)
---@param o Object
function obj_pair_with_parent(o)
    if (o.oBehParams >> 24) ~= 0 then
        if o.parentObj == o or o.parentObj == nil then
            -- Find the first surface object (or type defined by the object's param 3)
            local list = OBJ_LIST_SURFACE
            if (o.oBehParams >> 8) & 0xFF ~= 0 then
                list = (o.oBehParams >> 8) & 0xFF
            end

            local connectID = (o.oBehParams >> 24)
            local parent = obj_get_first(list)
            while parent do
                if (parent.oBehParams >> 8) & 0xFF == connectID then
                    o.parentObj = parent
                    parent.oCollisionDistance = 10000 -- don't disable collision
                    local relTranslation = {x = o.oPosX - parent.oPosX, y = o.oPosY - parent.oPosY, z = o.oPosZ - parent.oPosZ}
                    local toRotate = {x = -parent.oFaceAnglePitch, y = -parent.oFaceAngleYaw, z = -parent.oFaceAngleRoll}
                    vec3f_rotate_zxy(relTranslation, toRotate)
                    obj_set_parent_relative_pos(o, relTranslation.x, relTranslation.y, relTranslation.z)
                    o.oParentRelativeAnglePitch, o.oParentRelativeAngleYaw, o.oParentRelativeAngleRoll = o.oFaceAnglePitch - parent.oFaceAnglePitch, o.oFaceAngleYaw - parent.oFaceAngleYaw, o.oFaceAngleRoll - parent.oFaceAngleRoll
                    break
                end
                parent = obj_get_next(parent)
            end
        else
            obj_position_relative_to_parent(o)
        end
    end
end

---@param o Object
function on_object_render(o)
    if obj_has_behavior_id(o, id_bhvIngredient) ~= 0 or obj_has_behavior_id(o, id_bhvPanChild) ~= 0 then
        ingredient_render_setup(o)
    elseif obj_has_behavior_id(o, id_bhvKnife) ~= 0 then
        local m = gMarioStates[network_local_index_from_global(o.globalPlayerIndex)]
        local pos = {x = 0, y = 0, z = 0}
        local rot = {x = 0, y = 0, z = 0}
        local rotArm = {x = 0, y = 0, z = 0}
        get_mario_anim_part_rot(m, MARIO_ANIM_PART_RIGHT_ARM, rotArm)
        get_mario_anim_part_pos(m, MARIO_ANIM_PART_RIGHT_HAND, pos)
        --get_mario_anim_part_rot(m, MARIO_ANIM_PART_RIGHT_HAND, rot)
        
        rot.x = -rotArm.x + 0x2000
        rot.y = m.faceAngle.y + 0x8000
        rot.z = 0x4000
        pos.x = pos.x + sins(m.faceAngle.y) * 10
        pos.z = pos.z + coss(m.faceAngle.y) * 10
        obj_set_pos(o, pos.x, pos.y, pos.z)
        obj_set_angle(o, rot.x, rot.y, rot.z)
        obj_update_gfx_pos_and_angle(o)
    end
end
hook_event(HOOK_ON_OBJECT_RENDER, on_object_render)

function before_geo_process(graphNode, matStackIndex)
    local heldNode = geo_get_current_held_object()
    local o = geo_get_current_object()
    if o and (obj_has_behavior_id(o, id_bhvIngredient) ~= 0 or obj_has_behavior_id(o, id_bhvPanChild) ~= 0) then
        ingredient_render_setup(o)
        if heldNode and heldNode.objNode == o then
            o.header.gfx.shadowInvisible = true

            -- Billboard held objects
            if o.header.gfx.node.flags & GRAPH_RENDER_BILLBOARD ~= 0 then
                mtxf_billboard(gMatStack[matStackIndex], gMatStack[matStackIndex], {x = 0, y = 0, z = 0}, 0)
                mtxf_billboard(gMatStackPrev[matStackIndex], gMatStackPrev[matStackIndex], {x = 0, y = 0, z = 0}, 0)
            end

            -- Store held pos (used to fix objects to plates)
            local camera = gMarioStates[0].area.camera.mtx
            local mat4 = gMat4Zero()
            local camInv = gMat4Zero()
            mtxf_inverse(camInv, camera)
            mtxf_mul(mat4, gMatStack[matStackIndex], camInv)
            heldObjMtx[o.heldByPlayerIndex] = mat4
        end
    end
end
hook_event(HOOK_BEFORE_GEO_PROCESS, before_geo_process)