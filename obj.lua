define_custom_obj_fields({
    oContents = "u32",
    oContentCount = "u32",
    oCutOrCookTimer = "u32",
    oOvercookTimer = "u32",
    oParentSyncID = "u32",
    oUsingSyncID = "u32",
    oRespawnTimer = "u32",
    oPlateAppearTimer = "u32",
})

---@param o Object
function bhv_ingredient_init(o)
    o.oFlags = (OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    ingredient_render_setup(o)
    
    o.oInteractType = INTERACT_GRABBABLE
    o.oGravity = 2.5
    o.oFriction = 0.8
    o.oBuoyancy = 1.4
    o.oWallHitboxRadius = 50
    o.oCutOrCookTimer = 0
    o.oOvercookTimer = 0
    o.hookRender = 0xDA
    if o.header.gfx.sharedChild then
        o.header.gfx.sharedChild.hookProcess = 0xDA
    end
    cur_obj_become_intangible()
    cur_obj_set_home_once()

    if o.oBehParams == ITEM_PAN then
        spawn_child_object(o, id_bhvPanChild, E_MODEL_NONE, 0, 0, 0)
    end

    network_init_object(o, true, {"oBehParams", "oContents", "oContentCount", "oCutOrCookTimer", "oOvercookTimer", "oRespawnTimer", "oPlateAppearTimer", "oParentSyncID", "oUsingSyncID"})
end

---@param o Object
function bhv_ingredient_loop(o)
    if o.activeFlags == ACTIVE_FLAG_DEACTIVATED then return end
    cur_obj_become_intangible()

    local iData = ITEM_DATA[o.oBehParams] or ITEM_DATA[0]
    local maxCookTime = iData.cookTime or DEFAULT_COOK_TIME

    -- update parentObj and usingObj with sync IDs
    if o.oParentSyncID ~= 0 and o.oHeldState == HELD_FREE then
        local parent = sync_object_get_object(o.oParentSyncID)
        o.parentObj = parent or o.parentObj
    end
    if o.oUsingSyncID ~= 0 then
        local using = sync_object_get_object(o.oUsingSyncID)
        if using and o.usingObj ~= using then
            -- Mutual
            o.usingObj = using
            using.usingObj = o
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
        o.header.gfx.node.flags = o.header.gfx.node.flags | GRAPH_RENDER_INVISIBLE
        o.oPlateAppearTimer = o.oPlateAppearTimer - 1
        if o.oPlateAppearTimer == 0 then
            -- go to nearest plate counter
            local counter = obj_get_nearest_behavior_id_with_condition(o, id_bhvCounter, function(counter)
                return counter.oBehParams2ndByte == COUNTER_TYPE_PLATES
            end)
            if counter then
                obj_copy_pos(o, counter)
                o.oPosY = o.oPosY + (COUNTER_HEIGHT[counter.oBehParams2ndByte] or 34) * counter.header.gfx.scale.y
            else
                obj_set_pos(o, o.oHomeX, o.oHomeY, o.oHomeZ)
                spawn_mist_particles()
            end
        end
        return
    elseif o.oRespawnTimer ~= 0 then
        o.header.gfx.node.flags = o.header.gfx.node.flags | GRAPH_RENDER_INVISIBLE
        o.oRespawnTimer = o.oRespawnTimer - 1
        if o.oRespawnTimer == 0 then
            obj_set_pos(o, o.oHomeX, o.oHomeY, o.oHomeZ)
            spawn_mist_particles()
        end
        return
    end
    o.header.gfx.node.flags = o.header.gfx.node.flags & ~GRAPH_RENDER_INVISIBLE

    -- spawn steam/smoke for cooked things
    if (o.oTimer % 10 == 0) and ((iData.cookable and o.oContentCount ~= 0 and o.oCutOrCookTimer == maxCookTime)
    or iData.isCooked or o.oContents == ITEM_BURNT) then
        local model = (o.oContents == ITEM_BURNT and E_MODEL_BURN_SMOKE) or E_MODEL_SMOKE
        spawn_child_object(o, id_bhvBlackSmokeMario, model, 0, 0, 0)
    end

    -- plated
    if o.parentObj and o.parentObj ~= o and o.oHeldState == HELD_FREE then
        obj_copy_pos(o, o.parentObj)
        return
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
            object_step_without_floor_orient()
            attempt_item_place(o, m)
        else
            local counter = o.usingObj
            if counter.usingObj ~= o then
                o.usingObj = nil
                o.oUsingSyncID = 0
            else
                obj_copy_pos(o, counter)
                o.oPosY = o.oPosY + (COUNTER_HEIGHT[counter.oBehParams2ndByte] or 34) * counter.header.gfx.scale.y

                if counter.oBehParams2ndByte == COUNTER_TYPE_HEAT and o.oContentCount ~= 0 and o.oContents ~= ITEM_BURNT then
                    if iData.cookable then
                        if o.oCutOrCookTimer < maxCookTime then
                            o.oCutOrCookTimer = o.oCutOrCookTimer + 1
                            o.oOvercookTimer = 0

                            -- TEMP
                            if o.oCutOrCookTimer == maxCookTime then
                                djui_chat_message_create("done!")
                            end
                        else -- overcook after 10 seconds
                            o.oOvercookTimer = o.oOvercookTimer + 1
                            if o.oOvercookTimer >= 10 * 30 then
                                djui_chat_message_create("burnt") -- TEMP
                                o.oCutOrCookTimer = 0
                                o.oOvercookTimer = 0
                                o.oContents = ITEM_BURNT
                            end
                        end
                    end
                end
            end
        end
    elseif (o.oHeldState == HELD_HELD) then
        if o.usingObj then
            o.usingObj.usingObj = nil
            o.usingObj = nil
            o.oUsingSyncID = 0
        end

        cur_obj_disable_rendering()
    elseif (o.oHeldState == HELD_THROWN) or (o.oHeldState == HELD_DROPPED) then
        cur_obj_enable_rendering()
        o.oForwardVel = (o.oHeldState == HELD_THROWN and 60) or 0
        o.oVelY = (o.oHeldState == HELD_THROWN and 10) or 0

        o.oFaceAngleYaw = o.oMoveAngleYaw
        -- consistent throwing height (based on Mario's)
        if o.oHeldState == HELD_THROWN then
            local m2 = gMarioStates[o.heldByPlayerIndex]
            if m2 then
                o.oPosY = m2.pos.y + 110
            end
        end

        o.oHeldState = HELD_FREE
    end

    o.oInteractStatus = 0
end

id_bhvIngredient = hook_behavior(nil, OBJ_LIST_GENACTOR, false, bhv_ingredient_init, bhv_ingredient_loop, "bhvIngredient")

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
        smlua_anim_util_set_animation(o, anim)
        if animFrame == -2 then
            o.header.gfx.animInfo.animAccel = 0
            o.header.gfx.animInfo.animFrame = o.header.gfx.animInfo.curAnim.loopEnd - 1
        elseif animFrame ~= -1 then
            o.header.gfx.animInfo.animAccel = 0
            o.header.gfx.animInfo.animFrame = animFrame
        else -- Animate normally
            o.header.gfx.animInfo.animAccel = 0x10000
            o.header.gfx.animInfo.animFrame = 0
        end
    end

    if not plated then
        oGFX.shadowInvisible = (iData.isPlate or false) -- temporary solution
        if iData.billboard then
            obj_set_billboard(o)
        else
            oGFX.node.flags = oGFX.node.flags & ~GRAPH_RENDER_BILLBOARD
        end

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
        if o.parentObj.oBehParams == ITEM_PAN then
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
---@param m MarioState
---@param placeOnObj Object?
---@param isHeld boolean?
---@return boolean placeValid
---@return boolean stillHolding
function attempt_item_place(placedObj, m, placeOnObj, isHeld)
    local o = placedObj
    local o2 = placeOnObj
    if obj_has_behavior_id(o, id_bhvIngredient) == 0 then return false, false end

    local iData = ITEM_DATA[o.oBehParams] or ITEM_DATA[0]
    local counter = nil
    if o2 then
        counter = o2.usingObj
        if counter == o2 then counter = nil end
    else
        counter = obj_get_nearest_object_with_behavior_id(o, id_bhvCounter)
        local dist = (counter and dist_between_objects(o, counter)) or 10000
        if dist > 150 or ((isHeld or o.oForwardVel < 5) and dist > 100) then return false, false end
        o2 = counter.usingObj
        -- empty, default counters have a smaller auto-snap range
        if (not o2) and counter.oBehParams2ndByte == COUNTER_TYPE_DEFAULT and dist > 100 then return false, false end

        -- Non-throwables will only snap to empty counters
        if (iData.noThrow or o.oContentCount ~= 0) and o2 then return false, false end
    end

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

        if not placeOnPlate then
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
            
            o2.oContents = o2.oContents | (containerData << (8 * o2.oContentCount))
            o2.oContentCount = o2.oContentCount + containerCount

            -- average cooking time
            if iData.pourable then
                o2.oCutOrCookTimer = o2.oCutOrCookTimer + o.oCutOrCookTimer
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
                    network_send_object(o, true)
                else
                    o.oContents = 0
                    o.oContentCount = 0
                end

                return true, true
            elseif iData.isPlate then
                children = find_all_object_children(o, id_bhvIngredient)
            end
            
            for i,c in ipairs(children) do
                c.parentObj = o2
                c.oParentSyncID = o2.oSyncID
                if m and m.playerIndex == 0 then
                    network_send_object(c, true)
                end
            end

            if iData.isPlate or o == placedObj then
                return true, (iData.isPlate)
            end
        end
        if o == placedObj and not forceCounterPlace then return true, false end
    end

    if counter then
        o = placedObj
        iData = ITEM_DATA[o.oBehParams] or ITEM_DATA[0]
        local allowPlace = true
        if counter.oBehParams2ndByte == COUNTER_TYPE_HEAT then
            allowPlace = iData.cookable or false
        elseif counter.oBehParams2ndByte == COUNTER_TYPE_TRASH then
            allowPlace = false
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
                    return true, false
                end
            end
        elseif counter.oBehParams2ndByte == COUNTER_TYPE_SERVING then
            if not iData.isPlate then
                if m and m.playerIndex == 0 and isHeld then
                    djui_chat_message_create("Needs plate!")
                end
                allowPlace = false
            else
                if m and m.playerIndex == 0 then
                    local items = {}
                    local children = find_all_object_children(o, id_bhvIngredient)
                    for i,c in ipairs(children) do
                        table.insert(items, {type = c.oBehParams, contents = c.oContents, contentCount = c.oContentCount})
                        obj_mark_for_deletion(c)
                    end
    
                    attempt_serve_order(items)

                    o.oPlateAppearTimer = 5 * 30
                    network_send_object(o, true)
                end
                return true, false
            end
        elseif counter.oBehParams2ndByte == COUNTER_TYPE_PLATES then
            allowPlace = false
        end

        if not allowPlace then return true, true end

        counter.usingObj = o
        o.usingObj = counter
        o.oUsingSyncID = counter.oSyncID
        o.oForwardVel = 0
        o.oVelY = 0
        obj_copy_pos(o, counter)
        o.oPosY = o.oPosY + (COUNTER_HEIGHT[counter.oBehParams2ndByte] or 34) * counter.header.gfx.scale.y
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
    if iData.isPlate or iData2.isPlate then
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
            if tables_contain_same_elements(contentTable, cookedData.items) then
                return cookedData
            end
        end
    end
end

function attempt_serve_order(items)
    if #items == 0 then
        djui_chat_message_create("Plate is empty")
        return false
    elseif #pending_orders == 0 then
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
    
    local myKitchen = gPlayerSyncTable[0].kitchen
    for a,pending_data in ipairs(pending_orders) do
        local orderID = pending_data.id or ORDER_PLAIN_SALAD
        local order = ORDER_DATA[orderID]
        if order and #order.items == #items and pending_data.kitchen == myKitchen and pending_data.vanishTimer == nil then
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
                djui_chat_message_create("Served "..order.name) -- TEMP
                network_send_include_self(true, {id = PACKET_SERVED_ORDER, orderID = orderID, from = network_global_index_from_local(0)})
                return true
            end
        end
    end
    djui_chat_message_create("This order wasn't available")
    return false
end

---@param o Object
function bhv_counter_init(o)
    o.oFlags = o.oFlags | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_scale_xyz(o, 1.5, 1.6, 1.5)

    o.collisionData = smlua_collision_util_get("main_counter_center_collision")
    cur_obj_set_home_once()

    if o.oBehParams2ndByte == COUNTER_TYPE_CUT then
        spawn_child_object(o, id_bhvCuttingBoard, E_MODEL_CHOPPING_BOARD, 0, 0, 0, nil)
    elseif o.oBehParams2ndByte == COUNTER_TYPE_SERVING then
        o.collisionData = smlua_collision_util_get("sink_collision")
    end

    network_init_object(o, false, {"oOvercookTimer"})
end

---@param o Object
function bhv_counter_loop(o)
    load_object_collision_model()

    -- validate object on counter
    if o.usingObj and o.usingObj ~= o and o.usingObj.usingObj ~= o then
        o.usingObj = nil
    end

    if o.oBehParams2ndByte == COUNTER_TYPE_HEAT then
        local heatOn = false
        local cookSound = SOUND_MOVING_LAVA_BURN
        local cookSoundChance = 1
        if o.usingObj and o.usingObj ~= o then
            local iData = ITEM_DATA[o.usingObj.oBehParams] or ITEM_DATA[0]
            if iData.cookable and o.usingObj.oContentCount ~= 0 then
                heatOn = true
                cookSound = iData.cookSound or cookSound
                cookSoundChance = iData.cookSoundChance or cookSoundChance
            end
        end
        if heatOn then
            smlua_anim_util_set_animation(o, "heat_on")
            if cookSoundChance == 1 or random_float() < cookSoundChance then
                cur_obj_play_sound_2(cookSound)
            end
        else
            smlua_anim_util_set_animation(o, "heat_off")
        end
    elseif o.oBehParams2ndByte == COUNTER_TYPE_INGREDIENT then
        if o.oOvercookTimer ~= 0 then
            o.oOvercookTimer = 0
            smlua_anim_util_set_animation(o, "box_open")
        elseif cur_obj_check_if_at_animation_end() ~= 0 then
            smlua_anim_util_set_animation(o, "box_closed")
            if is_nearest_mario_state_to_object(gMarioStates[0], o) then
                network_send_object(o, false)
            end
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