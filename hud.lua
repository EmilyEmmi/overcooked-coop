local FLAME_ANIM = {"flame_seg3_texture_03017320", "flame_seg3_texture_03017B20", "flame_seg3_texture_03018320", "flame_seg3_texture_03018B20", "flame_seg3_texture_03019320", "flame_seg3_texture_03019B20", "flame_seg3_texture_0301A320", "flame_seg3_texture_0301AB20"}
local HUD_LOCATIONS = {
    {10, false},
    {10, true},
    {180, false},
    {430, true},
}

function playing_hud()
    local screenWidth = djui_hud_get_screen_width()
    local intendedX = HUD_LOCATIONS[orderHUDLocation+1][1] or 10
    local fromRight = HUD_LOCATIONS[orderHUDLocation+1][2] or false
    if fromRight then
        intendedX = screenWidth - intendedX
    end

    local y = 0
    local scale = 2
    local widthPerItem = 30
    for i, pending_data in ipairs(pending_orders) do
        if fromRight ~= reverseReading then
            i = #pending_orders - i + 1
            pending_data = pending_orders[i]
        end
        local x = screenWidth + intendedX
        if reverseReading then
            x = intendedX - screenWidth
        end
        local prevX = x
        local timeRatio = (pending_data.time / pending_data.maxTime)
        if pending_data.inited then
            pending_data.lastX = pending_data.x
            if math.abs(pending_data.x - intendedX) <= 2 * scale then
                pending_data.x = intendedX
                if pending_data.vanishTimer == nil and timeRatio < 0.33 then
                    pending_data.x = pending_data.x + math.random(-2, 2) * scale
                end
            else
                pending_data.x = approach_f32_asymptotic(pending_data.x, intendedX, 0.25)
            end
            
            x = pending_data.x
            prevX = pending_data.lastX
        else
            pending_data.inited = true
            pending_data.x = x
            pending_data.lastX = prevX
        end

        local alpha = 255
        if pending_data.vanishTimer then
            alpha = (alpha * pending_data.vanishTimer // 30)
        end

        local order = ORDER_DATA[pending_data.id]
        local items = {}
        local mainIsCooked = false
        for a, item in ipairs(order.items) do
            if not ITEM_DATA[item.type].skipItem then
                table.insert(items, item.type)
            elseif ITEM_DATA[item.type].isCooked then
                mainIsCooked = true
            end
            if item.contents then
                for b, subitem in ipairs(item.contents) do
                    table.insert(items, subitem)
                end
            end
        end

        y = 0
        local width = math.max(#items, 2) * widthPerItem * scale
        if fromRight then
            x = x - width
            prevX = prevX - width
        end
        djui_hud_set_color(255, 255, 255, alpha)
        djui_hud_render_rect_interpolated(prevX, y, width, 40 * scale, x, y, width, 40 * scale)

        -- timer
        local maxTimerWidth = width - 10 * scale
        local timerWidth = maxTimerWidth * timeRatio
        local prevTimerWidth = maxTimerWidth * timeRatio
        local color = {r = 255, g = 0, b = 0}
        if timeRatio >= 0.66 then
            local colorRatio = (timeRatio - 1) / -0.34
            color = lerp_color({r = 0, g = 255, b = 0}, {r = 255, g = 255, b = 0}, colorRatio)
        elseif timeRatio >= 0.33 then
            local colorRatio = (timeRatio - 0.66) / -0.33
            color = lerp_color({r = 255, g = 255, b = 0}, color, colorRatio)
        end
        
        -- split into 3 segments
        local segmentX = x
        local prevSegmentX = prevX
        for a=1,3 do
            local maxSegmentWidth = maxTimerWidth / 3
            local segmentWidth = math.min(maxSegmentWidth, timerWidth)
            local prevSegmentWidth = math.min(maxSegmentWidth, prevTimerWidth)
            
            djui_hud_set_color(0, 50, 100, alpha)
            djui_hud_render_rect_interpolated(prevSegmentX, y, maxSegmentWidth, 10 * scale, segmentX, y, maxSegmentWidth, 10 * scale)
            if segmentWidth > 0 and prevSegmentWidth >= 0 then
                djui_hud_set_color(color.r, color.g, color.b, alpha)
                djui_hud_render_rect_interpolated(prevSegmentX, y, prevSegmentWidth, 10 * scale, segmentX, y, segmentWidth, 10 * scale)
            end
            
            segmentX = segmentX + maxSegmentWidth + 5 * scale
            prevSegmentX = prevSegmentX + maxSegmentWidth + 5 * scale
            timerWidth = timerWidth - segmentWidth
            prevTimerWidth = prevTimerWidth - prevSegmentWidth
        end

        -- item to serve
        djui_hud_set_color(255, 255, 255, alpha)
        local itemScale = scale * 2
        local tex = order.icon
        if tex then
            local texWidth = tex.width * itemScale
            local itemX = x + (width - texWidth) / 2
            local prevItemX = prevX + (width - texWidth) / 2
            djui_hud_render_texture_interpolated_x_only(tex, itemX, y + 5 * scale, itemScale, itemScale, prevItemX, itemScale)
        else
            local text = order.name
            local textScale = itemScale
            local textWidth = djui_hud_measure_text(text) * textScale
            if textWidth > width then
                textScale = (width / textWidth) * textScale
                textWidth = width
            end
            local itemX = x + (width - textWidth) / 2
            local prevItemX = prevX + (width - textWidth) / 2
            djui_hud_print_text_interpolated(text, prevItemX, y + 5 * (scale - itemScale), textScale, itemScale, itemX, y + 5 * (scale - itemScale), textScale, itemScale)
        end

        -- items
        local rectWidth = (widthPerItem - 5) * scale
        local rectX = x + 2.5 * scale
        local prevRectX = prevX + 2.5 * scale
        y = y + 42 * scale
        for a, item in ipairs(items) do
            djui_hud_render_rect_interpolated(prevRectX, y - 2 * scale, rectWidth, 20 * scale, rectX, y - 2 * scale, rectWidth, 20 * scale)
            itemScale = scale
            local itemX = rectX + rectWidth / 2
            local prevItemX = prevRectX + rectWidth / 2
            render_ingredient_icon_interpolated(item, prevItemX, y, itemScale, itemScale, itemX, y, itemScale, itemScale)
            if ITEM_DATA[item].cookItem and (mainIsCooked or ITEM_DATA[item].isCooked) then
                djui_hud_render_rect_interpolated(prevRectX, y + 18 * scale, rectWidth, 20 * scale, rectX, y + 18 * scale, rectWidth, 20 * scale)
                render_ingredient_icon_interpolated(ITEM_DATA[item].cookItem, prevItemX, y + 20 * scale, itemScale, itemScale, itemX, y + 20 * scale, itemScale, itemScale)
            end
            rectX = rectX + rectWidth + 5 * scale
            prevRectX = prevRectX + rectWidth + 5 * scale
        end

        local change = width + 10 * scale
        if fromRight then
            change = -change
        end
        intendedX = intendedX + change
    end

    djui_hud_reset_color()
    djui_hud_reset_text_color()
    djui_hud_set_text_alignment(TEXT_HALIGN_LEFT, TEXT_VALIGN_BOTTOM)

    -- score and tip combo
    scale = scale * 2
    local tipMulti = gGlobalSyncTable["tipMulti"..gPlayerSyncTable[0].kitchen] or 1
    local x = 20
    y = djui_hud_get_screen_height() - 8 * scale
    if tipMulti >= 4 then
        djui_hud_set_color(255, 0, 0, 255)
        local tex = get_texture_info(FLAME_ANIM[get_global_timer() % 16 // 2 + 1])
        djui_hud_render_texture(tex, x - 8 * scale, y - 32 * scale, scale, scale)
        djui_hud_reset_color()
    end
    djui_hud_render_texture(gTextures.coin, x, y - 22 * scale, scale, scale)
    x = x + 16 * scale
    djui_hud_print_text(tostring(gGlobalSyncTable.score), x, y, scale)
    scale = scale / 2
    x = 20
    y = y + 16 * scale
    djui_hud_print_text("Tip *"..tipMulti, x, y, scale)
    
    scale = scale * 2
    x = djui_hud_get_screen_width() - 32
    y = djui_hud_get_screen_height()
    djui_hud_set_text_alignment(TEXT_HALIGN_RIGHT, TEXT_VALIGN_BOTTOM)
    djui_hud_print_text(time_format(gGlobalSyncTable.timeLeft), x, y, scale)
end

local lastHudScore = 0
local lastHudStars = 0
function end_hud()
    local screenWidth, screenHeight = djui_hud_get_screen_width(), djui_hud_get_screen_height()
    djui_hud_set_color(0, 0, 0, 100)
    djui_hud_render_rect(0, 0, screenWidth + 16, screenHeight + 16)

    if gGlobalSyncTable.timeLeft < 3 then
        lastHudScore = gGlobalSyncTable.score
    elseif lastHudScore > gGlobalSyncTable.score then
        lastHudScore = gGlobalSyncTable.score
    elseif gGlobalSyncTable.timeLeft < 10 and get_global_timer() & 1 ~= 0 then
        if lastHudScore < gGlobalSyncTable.score then
            lastHudScore = math.min(lastHudScore + math.max(gGlobalSyncTable.score // (5 * 15), 1), gGlobalSyncTable.score)
            play_sound(SOUND_GENERAL_COIN, gGlobalSoundSource)
        end
    end

    local reachedEnd = (lastHudScore == gGlobalSyncTable.score)
    djui_hud_reset_color()
    local scale = 8
    local text = tostring(lastHudScore)
    local width = (16 + djui_hud_measure_text(text)) * scale
    local x = (screenWidth - width) / 2
    local y = screenHeight / 2 - 8 * scale
    djui_hud_render_texture(gTextures.coin, x, y, scale, scale)
    x = x + 16 * scale
    djui_hud_set_text_alignment(TEXT_HALIGN_LEFT, TEXT_VALIGN_TOP)
    djui_hud_print_text(text, x, y, scale)

    local stars = 4
    local maxStars = 3
    local neededPoints = get_star_scores(gGlobalSyncTable.ocLevel)
    while stars > 0 do
        if lastHudScore >= neededPoints[stars] then break end
        stars = stars - 1
    end
    maxStars = get_star_record(gGlobalSyncTable.ocLevel)
    maxStars = math.clamp(maxStars + 1, 3, 4)
    if stars >= 3 and (stars >= 4 or reachedEnd) then
        maxStars = 4
    end
    if lastHudStars < stars then
        play_sound(SOUND_MENU_COLLECT_SECRET + ((stars + 1) << 16), gGlobalSoundSource)
    end
    lastHudStars = stars

    djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
    x = screenWidth / 2 - (10 * (maxStars - 1)) * scale
    for i=1,maxStars do
        y = screenHeight / 2 + 24 * scale
        if i <= stars then
            if i < 4 then
                djui_hud_set_color(255, 255, 255, 255)
            else
                djui_hud_set_color(255, 20, 20, 255)
            end
        else
            djui_hud_set_color(0, 0, 0, 100)
        end
        djui_hud_render_texture(gTextures.star, x - 8 * scale, y, scale, scale)
        y = y + 16 * scale
        djui_hud_set_color(255, 255, 255, 255)
        djui_hud_print_text(tostring(neededPoints[i]), x, y, scale / 4)
        x = x + 20 * scale
    end

    if reachedEnd and gotNewRecord then
        scale = scale / 4
        x = screenWidth / 2
        y = screenHeight - 24 * scale
        djui_hud_print_text("NEW RECORD!!!", x, y, scale)
    end
end

function setup_hud()
    local screenWidth, screenHeight = djui_hud_get_screen_width(), djui_hud_get_screen_height()

    local scale = 4
    local x = screenWidth / 2
    local y = 20
    djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
    local timeLeft = gGlobalSyncTable.timeLeft - 3
    if timeLeft <= 0 then timeLeft = timeLeft + 3 end
    djui_hud_print_text(time_format(timeLeft), x, y, scale)

    if gMarioStates[0].action == ACT_SELECT_START and gMarioStates[0].actionState == 0 and gGlobalSyncTable.timeLeft > 3 then
        x = x - 70 * scale
        y = screenHeight - 60 * scale
        if gMarioStates[0].actionArg ~= 0 then
            y = y + 20 * scale
        end
        render_ingredient_icon(ITEM_TOMATO, x, y, scale, scale)

        y = screenHeight - 60 * scale
        x = x + 20 * scale
        djui_hud_set_text_alignment(TEXT_HALIGN_LEFT, TEXT_VALIGN_TOP)

        local text = "Kitchen <"..(gPlayerSyncTable[0].kitchen) .. ">"
        djui_hud_set_color(255, 255, 255, 255)
        if gGlobalSyncTable.maxKitchens <= 1 then
            text = "Kitchen: 1"
            djui_hud_set_color(100, 100, 100, 255)
        end
        djui_hud_print_text(text, x, y, scale)

        y = y + 20 * scale
        local maxSpawnID = math.ceil(gGlobalSyncTable.peakPlayers / gGlobalSyncTable.maxKitchens)
        text = "Spawn Point <"..(gPlayerSyncTable[0].spawnID+1) .. ">"
        djui_hud_set_color(255, 255, 255, 255)
        if maxSpawnID <= 1 then
            text = "Spawn Point: 1"
            djui_hud_set_color(100, 100, 100, 255)
        end
        djui_hud_print_text(text, x, y, scale)

        djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
        x = screenWidth / 2
        y = y + 20 * scale
        text = "[A] Confirm"
        if confirmTime ~= 0 then
            local width = djui_hud_measure_text(text) * scale
            local barWidth = width * (confirmTime / 30)
            djui_hud_set_color(0, 255, 0, 255)
            djui_hud_render_rect(x - width / 2, y, barWidth, 18 * scale)
        end
        djui_hud_set_color(255, 255, 255, 255)
        djui_hud_print_text(text, x, y, scale)
    else
        y = screenHeight - 20 * scale
        djui_hud_print_text("Ready!", x, y, scale)
    end
end

function on_hud_render()
    djui_hud_set_resolution(RESOLUTION_DJUI)
    djui_hud_set_font(FONT_CUSTOM_HUD)
    djui_hud_reset_color()
    djui_hud_reset_text_color()

    if inMenu then
        render_menu()
    elseif gGlobalSyncTable.gameState == GAME_STATE_PLAYING then
        lastHudScore = 0
        playing_hud()
    elseif gGlobalSyncTable.gameState == GAME_STATE_END then
        end_hud()
    elseif gGlobalSyncTable.gameState == GAME_STATE_SETUP then
        lastHudScore = 0
        setup_hud()
    end
end
hook_event(HOOK_ON_HUD_RENDER, on_hud_render)

local objectRadarStorage = {}
function behind_hud_render()
    djui_hud_set_resolution(RESOLUTION_DJUI)
    djui_hud_set_font(FONT_CUSTOM_HUD)
    hud_hide()
    djui_hud_reset_color()
    djui_hud_reset_text_color()

    local o = obj_get_first_with_behavior_id(id_bhvIngredient)
    local toRenderObj = {}
    while o do
        local validForRender = true
        if o.oHeldState == HELD_FREE then
            if (o.header.gfx.node.flags & GRAPH_RENDER_INVISIBLE ~= 0 or o.header.gfx.node.flags & GRAPH_RENDER_ACTIVE == 0) then
                validForRender = false
            elseif (o.parentObj and o.parentObj ~= o) then
                validForRender = false
            end
        else
            local m = gMarioStates[o.heldByPlayerIndex]
            if m.marioBodyState.mirrorMario or m.marioBodyState.updateHeadPosTime ~= get_global_timer() then
                validForRender = false
            end
        end

        if validForRender then
            local pos = {x = o.oPosX, y = o.oPosY + 100, z = o.oPosZ}
            if o.oHeldState ~= HELD_FREE then
                local m = gMarioStates[o.heldByPlayerIndex]
                vec3f_copy(pos, m.marioBodyState.headPos)
                pos.y = pos.y + 80
            end

            local out = gVec3fZero()
            djui_hud_world_pos_to_screen_pos(pos, out)
            if out.z < 0 then
                local radar = objectRadarStorage[o]
                if not radar then
                    radar = {}
                    radar.x = -50
                    radar.y = -50
                    radar.scale = 0
                    radar.barWidth = 0
                    radar.prevX = -50
                    radar.prevY = -50
                    radar.prevScale = 0
                    radar.prevBarWidth = 0
                    radar.frameLastRendered = 0
                    objectRadarStorage[o] = radar
                end

                radar.x = out.x
                radar.y = out.y
                radar.scale = -2000 / out.z * djui_hud_get_fov_coeff()
                table.insert(toRenderObj, {out.z, o})
            end
        end
        o = obj_get_next_with_same_behavior_id(o)
    end

    -- render progress bar for sinks
    o = obj_get_first_with_behavior_id(id_bhvCounter)
    while o do
        if o.oBehParams2ndByte == COUNTER_TYPE_SINK and o.oPlateAppearTimer ~= 0 then
            local pos = {x = o.oPosX, y = o.oPosY + 100, z = o.oPosZ}
            local out = gVec3fZero()
            djui_hud_world_pos_to_screen_pos(pos, out)
            if out.z < 0 then
                local radar = objectRadarStorage[o]
                if not radar then
                    radar = {}
                    radar.x = -50
                    radar.y = -50
                    radar.scale = 0
                    radar.barWidth = 0
                    radar.prevX = -50
                    radar.prevY = -50
                    radar.prevScale = 0
                    radar.prevBarWidth = 0
                    radar.frameLastRendered = 0
                    objectRadarStorage[o] = radar
                end

                radar.x = out.x
                radar.y = out.y
                radar.scale = -2000 / out.z * djui_hud_get_fov_coeff()
                table.insert(toRenderObj, {out.z, o})
            end
        end
        o = obj_get_next_with_same_behavior_id(o)
    end

    -- sort by z
    table.sort(toRenderObj, function(renderData1, renderData2)
        return renderData1[1] < renderData2[1]
    end)

    for i, renderData in ipairs(toRenderObj) do
        local o = renderData[2]
        local radar = objectRadarStorage[o]
        if obj_has_behavior_id(o, id_bhvIngredient) ~= 0 then
            local iData = ITEM_DATA[o.oBehParams]
            local items = {}
            local children = {o}
            local allCooked = (iData.isCooked or false)
            if iData.isPlate then
                children = find_all_object_children(o, id_bhvIngredient)
            end

            for i, c in ipairs(children) do
                if c.oContents == ITEM_BURNT then
                    table.insert(items, ITEM_BURNT)
                else
                    local iDataC = ITEM_DATA[c.oBehParams]
                    if iDataC.icon and not (iDataC.noTrash or iDataC.skipItem) then
                        table.insert(items, c.oBehParams)
                    end
                    
                    if c.oContentCount ~= 0 then
                        local maxCookTime = iData.cookTime or DEFAULT_COOK_TIME
                        allCooked = (iData.cookable and c.oCutOrCookTimer >= maxCookTime)

                        local cookedData = get_cooked_data(c)
                        local renderContents = true
                        if cookedData then
                            allCooked = true
                            local ingredient = cookedData.result
                            local iDataR = ITEM_DATA[ingredient]
                            if iDataR.icon and not (iDataR.noTrash or iDataR.skipItem) then
                                table.insert(items, cookedData.result)
                            end
                            renderContents = cookedData.inheritContents
                        end

                        if renderContents then
                            for i=0,c.oContentCount-1 do
                                local ingredient = (c.oContents >> (8 * i)) & 0xFF
                                table.insert(items, ingredient)
                            end
                        end
                    end
                end
            end

            if #items ~= 0 or o.oCutOrCookTimer ~= 0 or o.oNotifyTimer ~= 0 then
                if radar.frameLastRendered + 1 ~= get_global_timer() then
                    radar.prevX = radar.x
                    radar.prevY = radar.y
                    radar.prevScale = radar.scale
                    radar.prevBarWidth = radar.barWidth
                end
                radar.frameLastRendered = get_global_timer()

                djui_hud_set_color(255, 255, 255, 255)
                local x, y, scale = radar.x, radar.y, radar.scale
                local prevX, prevY, prevScale = radar.prevX, radar.prevY, radar.prevScale
                local maxColumns = 3
                local columns = math.min(#items, maxColumns)
                if #items == 1 then
                    render_ingredient_icon_interpolated(items[1], prevX, prevY, prevScale, prevScale, x, y, scale, scale, true, allCooked)
                elseif #items ~= 0 then
                    y = y - 20 * scale * math.ceil(#items / columns)
                    prevY = prevY - 20 * prevScale * math.ceil(#items / columns)
                    for i, item in ipairs(items) do
                        if i % columns == 1 then
                            x = radar.x - 10 * scale * (columns - 1)
                            prevX = radar.prevX - 10 * prevScale * (columns - 1)
                            y = y + 20 * scale
                            prevY = prevY + 20 * prevScale
                        else
                            x = x + 20 * scale
                            prevX = prevX + 20 * prevScale
                        end
                        render_ingredient_icon_interpolated(item, prevX, prevY, prevScale, prevScale, x, y, scale, scale, true, allCooked)
                    end
                end

                -- cooking/cutting progress
                if o.oCutOrCookTimer ~= 0 then
                    x = radar.x - 20 * scale
                    y = radar.y + 20 * scale
                    prevX = radar.prevX - 20 * prevScale
                    prevY = radar.prevY + 20 * prevScale
                    radar.barWidth = 0
                    if iData.cut then
                        radar.barWidth = o.oCutOrCookTimer / 30
                    elseif iData.cookable then
                        local maxCookTime = iData.cookTime or DEFAULT_COOK_TIME
                        radar.barWidth = o.oCutOrCookTimer / maxCookTime
                    end

                    if radar.barWidth ~= 0 and radar.barWidth ~= 1 then
                        local width = 40 * radar.barWidth
                        djui_hud_render_rect_interpolated(prevX, prevY, 40 * prevScale, 10 * prevScale, x, y, 40 * scale, 10 * scale)
                        djui_hud_set_color(0, 255, 0, 255)
                        djui_hud_render_rect_interpolated(prevX, prevY, width * prevScale, 10 * prevScale, x, y, width * scale, 10 * scale)
                    end
                end
                -- notification for cooking progress
                if o.oNotifyTimer ~= 0 then
                    local text = (o.oOvercookTimer >= 5 * 30 and "!!!") or "Done"
                    djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
                    x = radar.x
                    y = radar.y + 8 * scale
                    prevX = radar.prevX
                    prevY = radar.prevY + 8 * prevScale
                    local alpha = 255
                    if o.oNotifyTimer > 20 then
                        alpha = ((30 - o.oNotifyTimer) / 10) * alpha
                    elseif o.oNotifyTimer < 10 then
                        alpha = (o.oNotifyTimer / 10) * alpha
                    end
                    o.oNotifyTimer = o.oNotifyTimer - 1
                    djui_hud_set_color(255, 255, 255, alpha)
                    djui_hud_print_text_interpolated(text, prevX, prevY, prevScale, x, y, scale)
                end

                radar.prevX = radar.x
                radar.prevY = radar.y
                radar.prevScale = radar.scale
                radar.prevBarWidth = radar.barWidth
            end
        else
            if radar.frameLastRendered + 1 ~= get_global_timer() then
                radar.prevX = radar.x
                radar.prevY = radar.y
                radar.prevScale = radar.scale
                radar.prevBarWidth = radar.barWidth
            end
            radar.frameLastRendered = get_global_timer()

            djui_hud_set_color(255, 255, 255, 255)
            local x, y, scale = radar.x, radar.y, radar.scale
            local prevX, prevY, prevScale = radar.prevX, radar.prevY, radar.prevScale
            x = radar.x - 20 * scale
            y = radar.y + 20 * scale
            prevX = radar.prevX - 20 * prevScale
            prevY = radar.prevY + 20 * prevScale
            radar.barWidth = o.oPlateAppearTimer / (3 * 30)

            if radar.barWidth ~= 0 and radar.barWidth ~= 1 then
                local width = 40 * radar.barWidth
                djui_hud_render_rect_interpolated(prevX, prevY, 40 * prevScale, 10 * prevScale, x, y, 40 * scale, 10 * scale)
                djui_hud_set_color(0, 255, 0, 255)
                djui_hud_render_rect_interpolated(prevX, prevY, width * prevScale, 10 * prevScale, x, y, width * scale, 10 * scale)
            end

            radar.prevX = radar.x
            radar.prevY = radar.y
            radar.prevScale = radar.scale
            radar.prevBarWidth = radar.barWidth
        end
    end
end
hook_event(HOOK_ON_HUD_RENDER_BEHIND, behind_hud_render)

-- The menu format from geoguessr again...
local MENU_COLORS = {
    bg = {r = 0, g = 0, b = 25, a = 200},
    bgTex = {r = 200, g = 200, b = 255, a = 50},
    desc = {r = 255, g = 255, b = 255, a = 255},
    option = {r = 0, g = 200, b = 200},
    descBg = {r = 0, g = 25, b = 50, a = 255},
    scrollBg = {r = 0, g = 10, b = 25, a = 255},
    scrollBar = {r = 155, g = 180, b = 180, a = 155},
}
TEX_TRIANGLE = get_texture_info("triangle")

function build_level_menu(menu)
    local min = 0 -- Change to 1 when the debug level is no longer wanted
    local unclearedLevel = false

    for i=min,#OC_LEVEL_DATA do
        local lData = OC_LEVEL_DATA[i]
        local desc = lData.desc or "No description available."
        desc = desc .. "\n\n"
        local savePrefix = "record_"..i.."_"
        local bestOverallPlayers = mod_storage_load_integer(savePrefix.."players")
        local bestOverallScore, bestOverallStars = 0, 0
        if bestOverallPlayers ~= 0 then
            local savePrefixBest = savePrefix..bestOverallPlayers.."_"
            bestOverallScore = mod_storage_load_integer(savePrefixBest.."score")
            bestOverallStars = mod_storage_load_integer(savePrefixBest.."stars")
        end

        local bestStars = 0
        local maxStars = 3
        if bestOverallScore ~= 0 then
            -- score for this many players
            local players = gGlobalSyncTable.peakPlayers
            local savePrefixPlayers = "record_"..i.."_"..players.."_"
            local bestPlayerScore = mod_storage_load_integer(savePrefixPlayers.."score")
            local bestPlayerStars = mod_storage_load_integer(savePrefixPlayers.."stars")

            -- score for the most stars obtained
            local bestStarsPlayers = mod_storage_load_integer(savePrefix.."max_stars_players")
            local bestStarsScore = 0
            if bestStarsPlayers ~= 0 then
                local savePrefixBestStars = savePrefix..bestStarsPlayers.."_"
                bestStarsScore = mod_storage_load_integer(savePrefixBestStars.."score")
                bestStars = mod_storage_load_integer(savePrefixBestStars.."stars")
            end

            maxStars = math.clamp(bestStars+1, 3, 4)
            for stars=1,maxStars do
                desc = desc .. string.rep("", stars) .. ": %d\n"
            end

            local starStrPlayer = (bestPlayerStars == 0 and "0") or string.rep("", bestPlayerStars)
            local starStrMostStars = (bestStars == 0 and "0") or string.rep("", bestStars)
            local starStrOverall = (bestOverallStars == 0 and "0") or string.rep("", bestOverallStars)
            if bestPlayerScore ~= 0 then
                desc = desc .. string.format("\nBest %dP: %d (%s)", players, bestPlayerScore, starStrPlayer)
            else
                desc = desc .. string.format("\nBest %dP: 0", players)
            end
            desc = desc .. string.format("\nBest Stars: %d (%s, %dP)", bestStarsScore, starStrMostStars, bestStarsPlayers)
            desc = desc .. string.format("\nBest Overall: %d (%s, %dP)", bestOverallScore, starStrOverall, bestOverallPlayers)
        else
            for stars=1,maxStars do
                desc = desc .. string.rep("", stars) .. ": %d\n"
            end
            desc = desc .. "\nNo scores saved."
        end
                
        table.insert(menu, {
            lData.name,
            function()
                if gGlobalSyncTable.gameState == GAME_STATE_LEVEL_SELECT then
                    start_level_command(tostring(i))
                end
                inMenu = false
            end,
            desc = desc,
            true,
            descExtra = function()
                local maxKitchens = math.clamp(math.ceil(gGlobalSyncTable.peakPlayers / 4), 1, MAX_KITCHENS)
                local neededPoints = get_star_scores(i, maxKitchens)
                local result = {}
                for stars=1,maxStars do
                    table.insert(result, neededPoints[stars])
                end
                return table.unpack(result)
            end,
        })

        -- require 1 star to unlock the next level
        if i ~= 0 and bestStars == 0 and i ~= #OC_LEVEL_DATA and not cheatsApi then
            unclearedLevel = true
            break
        end
    end

    if unclearedLevel then
        table.insert(menu, {
            "???",
            function()
            end,
            desc = "Earn at least 1 star on the previous level to unlock this level.",
            true,
        })
    end
end

grabButtonIndex = 3
actionButtonIndex = 0
throwButtonIndex = 0
orderHUDLocation = 0
reverseReading = false

inMenu = false
local menuOption = 1
local menuID = 1
local stickCooldownX = 0
local stickCooldownY = 0
local menu_history = {}
local menuMotionEnabled = true
local confirmText = ""
local confirmFunc
-- menu data
local menu_data = {
    [1] = {
        {
            "Continue",
            function(x)
                play_sound(SOUND_MENU_PAUSE, gGlobalSoundSource)
                inMenu = false
            end,
            false,
            desc = "Unpause the game.",
        },
        {
            "Retry",
            function(x)
                confirmText = "Are you sure you want to restart? Any unsaved progress will be lost!"
                confirmFunc = function(x)
                    inMenu = false
                    gGlobalSyncTable.gameState = GAME_STATE_PREPARE
                    gGlobalSyncTable.timeLeft = 10
                end
                enter_menu(2)
            end,
            true,
            function()
                return gGlobalSyncTable.gameState ~= GAME_STATE_PLAYING and gGlobalSyncTable.gameState ~= GAME_STATE_SETUP
            end,
            desc = "Restart the level.",
        },
        {
            "Quit",
            function(x)
                confirmText = "Are you sure you want to quit? Any unsaved progress will be lost!"
                confirmFunc = function(x)
                    inMenu = false
                    gGlobalSyncTable.gameState = GAME_STATE_LEVEL_SELECT
                end
                enter_menu(2)
            end,
            true,
            function()
                return gGlobalSyncTable.gameState ~= GAME_STATE_PLAYING and gGlobalSyncTable.gameState ~= GAME_STATE_SETUP
            end,
            desc = "Exit the level.",
        },
        {
            "Level Select",
            function(x)
                enter_menu(3)
            end,
            true,
            function()
                return gGlobalSyncTable.gameState ~= GAME_STATE_LEVEL_SELECT
            end,
            desc = "Pick a level to start.",
        },
        {
            "Spectate",
            function(x)
                stayInSpectate = (x == 1)
                if stayInSpectate then
                    gPlayerSyncTable[0].spectator = true
                end
            end,
            runOnChange = true,
            currNum = (stayInSpectate and 1) or 0,
            maxNum = 1,
            nameRef = { "\\#ff5050\\Off", "\\#50ff50\\On" },
            desc = {"You'll automatically join the action when an opening is available.", "You'll stay in spectate mode."},
            updateNum = function(button)
                button.currNum = (stayInSpectate and 1) or 0
            end,
        },
        {
            "Preferences",
            function(x)
                enter_menu(4)
            end,
            false,
            desc = "Change settings for yourself. These don't affect other players.",
        },
        {
            "DJUI Menu",
            function(x)
                waitOpenDJUI = true
            end,
            false,
            desc = "Enter the DJUI menu. You can also press the R button to access this.",
        },
    },
    [2] = {
        {
            "Yes",
            function(x)
                if confirmFunc == nil then return end
                return confirmFunc(x)
            end,
            true,
            desc = "%s",
            descExtra = function()
                return confirmText
            end,
        },
        {
            "No",
            function(x)
                if #menu_history ~= 0 then
                    enter_menu(menu_history[#menu_history][1], menu_history[#menu_history][2], true)
                    table.remove(menu_history, #menu_history)
                else
                    enter_menu(1, 1, true)
                end
            end,
            true,
            desc = "%s",
            descExtra = function()
                return confirmText
            end,
        },
        title = "Confirm?",
    },
    [3] = {
        buildFunc = build_level_menu,
        title = "Level Select",
    },
    [4] = {
        {
            "Grab Button",
            function(x)
                grabButtonIndex = x
            end,
            runOnChange = true,
            currNum = grabButtonIndex,
            maxNum = 3,
            nameRef = { "X", "Y", "L", "B" },
            save = "grabButtonIndex",
            localSave = true,
            desc = "Use this button to place/pick up ingredients. Takes priority over the button's normal action.",
        },
        {
            "Action Button",
            function(x)
                actionButtonIndex = x
            end,
            runOnChange = true,
            currNum = actionButtonIndex,
            maxNum = 3,
            nameRef = { "X", "Y", "L", "B" },
            save = "actionButtonIndex",
            localSave = true,
            desc = "Use this button to chop ingredients and wash dishes.\nNote that using B will cause these actions to take priority over grabbing.",
        },
        {
            "Throw Button",
            function(x)
                throwButtonIndex = x
            end,
            runOnChange = true,
            currNum = throwButtonIndex,
            maxNum = 3,
            nameRef = { "X", "Y", "L", "B" },
            save = "throwButtonIndex",
            localSave = true,
            desc = "Use this button to throw ingredients.\nNote that grabbing/placing takes priority if using B.",
        },
        {
            "Reduced Menu Motion",
            function(x)
                menuMotionEnabled = (x ~= 0)
            end,
            runOnChange = true,
            currNum = (menuMotionEnabled and 1) or 0,
            maxNum = 1,
            nameRef = { "\\#50ff50\\On", "\\#ff5050\\Off" },
            save = "menuMotionEnabled",
            localSave = true,
            desc = "Turns off moving parts in the menu.",
        },
        {
            "Order HUD Location",
            function(x)
                orderHUDLocation = x
            end,
            runOnChange = true,
            currNum = orderHUDLocation,
            maxNum = 3,
            nameRef = { "Left", "Right", "Shift From Left", "Shift From Right" },
            save = "orderHUDLocation",
            localSave = true,
            desc = {"Orders appear on the left side of the screen.", "Orders appear on the right side of the screen.", "Orders appear on the left side of the screen, shifted right so the FPS counter doesn't cover them.", "Orders appear on the right side of the screen, shifted left so the popups don't cover them."},
        },
        {
            "Order Priority",
            function(x)
                reverseReading = (x == 1)
            end,
            runOnChange = true,
            currNum = (reverseReading and 1) or 0,
            maxNum = 1,
            nameRef = { "Left to Right", "Right to Left" },
            save = "reverseReading",
            localSave = true,
            desc = {"The oldest order will be on the left side of the queue. Serve *left to right* to maintain the tip combo.", "The oldest order will be on the right side of the queue. Serve *right to left* to maintain the tip combo."},
        },
        title = "Preferences",
    },
    [5] = {
        {
            "Put Me In!",
            function()
                inMenu = false
                stayInSpectate = false
                local m, sMario = gMarioStates[0], gPlayerSyncTable[0]
                local kitchen, spawnID = join_smallest_kitchen(0)
                sMario.kitchen = kitchen
                if spawnID == -1 then
                    sMario.spectator = true
                    sMario.spawnID = 0
                    djui_chat_message_create("Too many cooks in the kitchen! Please wait until a spot opens up.")
                else
                    sMario.spectator = false
                    sMario.spawnID = spawnID
                    m.flags = m.flags &~ MARIO_VANISH_CAP
                    if m.action & ACT_GROUP_MASK == ACT_GROUP_CUTSCENE then
                        on_death(m)
                    else
                        drop_and_set_mario_action(m, ACT_SELECT_START, 0)
                    end
                end
            end,
            desc = "Join the action right now, or until a spot opens up.",
        },
        {
            "Don't wanna cook",
            function()
                inMenu = false
                stayInSpectate = true
                gPlayerSyncTable[0].spectator = true
            end,
            desc = "Become a spectator until you disable spectating in the pause menu.",
        },
        title = "Join?",
        noBack = true,
    },
}

-- load menu settings; never nesters be crying rn
for a, menu in ipairs(menu_data) do
    for b, button in ipairs(menu) do
        if (network_is_server() or button.localSave) and button.save then
            local value = tonumber(mod_storage_load(button.save))
            local min = button.minNum or 0
            local max = button.maxNum or 999
            if value and value % 1 == 0 and button.currNum and value >= min and value <= max then
                button[2](value)
                button.currNum = value
            end
        end
    end
end

-- show the menu
local menuMotionY = 0
local bgTexScroll = 0
local menuMotionScrollY = -1
local resetMenuMotion = false
local menuMotionButton = {}
local frameCounter = 0
function render_menu()
    djui_hud_set_resolution(RESOLUTION_DJUI)
    djui_hud_set_font(djui_menu_get_font())

    local screenWidth = djui_hud_get_screen_width()
    local screenHeight = djui_hud_get_screen_height()

    djui_hud_set_color_from_table(MENU_COLORS.bg)
    djui_hud_render_rect(0, 0, screenWidth + 10, screenHeight + 10)

    local tex = ICON_TOMATO
    if gMarioStates[0].heldObj then
        local o = gMarioStates[0].heldObj
        tex = (ITEM_DATA[o.oBehParams] and ITEM_DATA[o.oBehParams].icon) or tex
    end
    local bgTexScale = 5
    local maxTexX = math.ceil(screenWidth / (tex.width * bgTexScale))
    local maxTexY = math.ceil(screenHeight / (tex.height * bgTexScale))
    djui_hud_set_color_from_table(MENU_COLORS.bgTex)
    for tileY=-1,maxTexY do
        for tileX=-1,maxTexX do
            if tileX % 2 == tileY % 2 then
                djui_hud_render_texture(tex,
                bgTexScroll + tex.width * tileX * bgTexScale,
                bgTexScroll + tex.height * tileY * bgTexScale, bgTexScale, bgTexScale)
            end
        end
    end
    if menuMotionEnabled then
        bgTexScroll = (bgTexScroll + 2) % (tex.width * bgTexScale)
    else
        bgTexScroll = 0
    end
    local arrowTex = TEX_TRIANGLE

    local menu = menu_data[menuID]
    if not menu then return end

    frameCounter = frameCounter + 1
    if frameCounter >= 60 then frameCounter = 0 end
    
    -- title
    local scale = 3
    local y = 64 * scale
    local title = menu.title or "Menu"
    if menu.title == nil and (gGlobalSyncTable.gameState ~= GAME_STATE_LEVEL_SELECT) then
        local lData = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel]
        title = lData.name or title
        y = y + 40 * scale
    end

    -- determine menu size
    local scroll = false
    local totalButtons = 0
    local downBy = 0
    local maxDownBy = 0
    for i, button in ipairs(menu) do
        if option_valid(button, true) then
            totalButtons = totalButtons + 1

            local buttonY = y + 32 * scale * (totalButtons - maxDownBy)
            while buttonY > screenHeight do
                maxDownBy = maxDownBy + 1
                scroll = true
                buttonY = y + 32 * scale * (totalButtons - maxDownBy)
                if i == menuOption then
                    downBy = maxDownBy
                end
            end
        end
    end
    if not scroll then
        y = math.max(y, screenHeight / 2 - 16 * scale * (totalButtons - 1))
    end

    local desc = ""
    local x = 0
    y = y - 40 * (scale-1) * downBy
    if resetMenuMotion or (not menuMotionEnabled) then
        menuMotionY = y
        menuMotionScrollY = -1
        menuMotionButton = {}
        resetMenuMotion = false
    else
        local prevY = menuMotionY
        y = smooth_approach(y, prevY, 0.25)
        menuMotionY = y
    end

    for i, button in ipairs(menu) do
        if option_valid(button, true) then
            local text = button[1]
            local origTextScale = scale
            local textScale = origTextScale
            local isSelectable = option_valid(button)
            if i == menuOption then
                if button.desc then
                    desc = button.desc
                    if type(desc) == "table" then
                        local currNum = button.currNum or 0
                        local min = button.minNum or 0
                        desc = desc[currNum - min + 1] or desc[#desc] or ""
                    end
                    if button.descExtra then
                        desc = string.format(desc, button.descExtra(button.currNum or 0))
                    else
                        desc = string.format(desc, button.currNum or 0)
                    end
                end
            else
                textScale = textScale - 1
            end

            if button.currNum then
                local optionText = ""
                local optionColor = string.format("\\#%02x%02x%02x\\", MENU_COLORS.option.r, MENU_COLORS.option.g, MENU_COLORS.option.b)
                local min = button.minNum or 0
                if button.playerRef then
                    if button.currNum ~= -1 then
                        local np = gNetworkPlayers[button.currNum]
                        if not np.connected then
                            button.currNum = 0
                            np = gNetworkPlayers[0]
                        end
                        local playerColor = network_get_player_text_color_string(np.localIndex)
                        optionText = playerColor .. np.name
                    else
                        optionText = "Random"
                    end
                elseif button.nameRef and button.nameRef[button.currNum - min + 1] then
                    optionText = button.nameRef[button.currNum - min + 1]
                elseif button.timeRef then
                    if button.currNum ~= 0 then
                        local seconds = button.currNum
                        local minutes = seconds // 60
                        seconds = seconds % 60
                        optionText = string.format("%d:%02d", minutes, seconds)
                    else
                        optionText = "Infinite"
                    end
                elseif button.levelRef then
                    local level = level_list[button.currNum] or 0
                    local area = get_menu_option(menuID, i + 1) or 0
                    optionText = get_level_name_custom(get_level_course_num(level), level, area)
                else
                    local numScale = button.scale or 1
                    optionText = tostring(button.currNum * numScale)
                    if button.optionPrefix then
                        optionText = button.optionPrefix .. optionText
                    end
                end
                if i == menuOption and isSelectable then
                    optionText = " < " .. optionText .. optionColor .. " >"
                else
                    optionText = ": " .. optionText
                end
                optionText = optionColor .. " " .. optionText
                text = text .. optionText
            end

            x = screenWidth * 0.35
            local width = djui_hud_measure_text(text) * textScale
            local testWidth = width / textScale * scale / 2
            if x + 20 * scale + testWidth > screenWidth * 0.7 - arrowTex.width then
                local origScale = textScale
                textScale = textScale / 2
                width = width / origScale * textScale
            end

            if menuMotionButton[i] == nil or (not menuMotionEnabled) then
                menuMotionButton[i] = {}
                menuMotionButton[i].x = x
                menuMotionButton[i].scale = textScale
            else
                --local prevX = menuMotionButton[i].x
                local prevScale = menuMotionButton[i].scale
                local origScale = textScale
                --x = smooth_approach(x, prevX, 0.25)
                textScale = smooth_approach(textScale * 10, prevScale * 10, 0.25) / 10
                menuMotionButton[i].x = x
                menuMotionButton[i].scale = textScale
                width = width / origScale * textScale
            end
        
            --djui_hud_set_color(255, 255, 255, 255)
            local valid = option_valid(button)
            local alpha = (valid and 255) or 100
            djui_hud_set_color(255, 255, 255, alpha)
            djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_CENTER)
            djui_hud_print_text(text, x, y, textScale)
            if i == menuOption then
                djui_hud_set_color(64, 128, 64, sins(frameCounter * 500) * 50 + 25)
                frameCounter = frameCounter + 1
                if frameCounter >= 60 then frameCounter = 0 end
                local height = 32 * textScale
                djui_hud_render_rect(x - width / 2 - 6, y - height / 2 + 6, width + 12, height + 12)
                --[[if button.currNum and (not button.playerRef) and tonumber(button.maxNum) and button.maxNum >= 10 and isSelectable then
                    x = x + width + 20
                    djui_hud_set_color(255, 255, 255, 255)
                    djui_hud_print_text("Hold X to change by 10", x, y+15*textScale, textScale*0.25)
                end]]
            end
            y = y + 32 * origTextScale
        end
    end

    -- title
    local titleScale = scale * 2
    djui_hud_reset_color()
    djui_hud_reset_text_color()
    djui_hud_set_font(FONT_CUSTOM_HUD)
    djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
    x, y = screenWidth * 0.35, 20
    local width = djui_hud_measure_text(title) * titleScale
    if width > screenWidth * 0.5 then
        titleScale = (screenWidth * 0.5 / width) * titleScale
        width = screenWidth * 0.5
    end
    djui_hud_print_text(title, x, y, titleScale)

    if menu.title == nil and (gGlobalSyncTable.gameState ~= GAME_STATE_LEVEL_SELECT) then
        local starScale = scale * 2
        local stars = 4
        local maxStars = get_star_record(gGlobalSyncTable.ocLevel)
        maxStars = math.clamp(maxStars + 1, 3, 4)
        local neededPoints = get_star_scores(gGlobalSyncTable.ocLevel)
        while stars > 0 do
            if gGlobalSyncTable.score >= neededPoints[stars] then break end
            stars = stars - 1
        end

        djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
        x = screenWidth * 0.35 - (10 * (maxStars - 1)) * starScale
        for i=1,maxStars do
            y = 32 + 32 * scale
            if i <= stars then
                if i < 4 then
                    djui_hud_set_color(255, 255, 255, 255)
                else
                    djui_hud_set_color(255, 20, 20, 255)
                end
            else
                djui_hud_set_color(0, 0, 0, 100)
            end
            djui_hud_render_texture(gTextures.star, x - 8 * starScale, y, starScale, starScale)
            y = y + 16 * starScale
            djui_hud_set_color(255, 255, 255, 255)
            djui_hud_print_text(tostring(neededPoints[i]), x, y, starScale / 4)
            x = x + 20 * starScale
        end
    end

    -- desc
    djui_hud_set_font(djui_menu_get_font())
    djui_hud_set_text_alignment(TEXT_HALIGN_LEFT, TEXT_VALIGN_TOP)
    djui_hud_set_color_from_table(MENU_COLORS.descBg)
    djui_hud_render_rect(screenWidth * 0.7, 0, screenWidth + 10, screenHeight + 10)
    y = -arrowTex.height
    while y < screenHeight do
        djui_hud_render_texture(TEX_TRIANGLE, screenWidth * 0.7 - arrowTex.width, y, 1, 2)
        y = y + arrowTex.height * 2
    end
    if #desc ~= 0 then
        local descScale = 1
        local lines = {}
        local line = ""
        desc = desc:gsub("\n", " \n ")
        local words = split(desc, " ")
        local width = 0
        local spaceWidth = djui_hud_measure_text(" ") * descScale
        for i, word in ipairs(words) do
            if word == "\n" then
                table.insert(lines, line)
                line = ""
                width = 0
            else
                local wordWidth = djui_hud_measure_text(word) * descScale
                if width + wordWidth > screenWidth * 0.3 - 50 then
                    table.insert(lines, line)
                    line = ""
                    width = 0
                end
                line = line .. word .. " "
                width = width + wordWidth + spaceWidth
            end
        end
        if #line ~= 0 then
            table.insert(lines, line)
        end
        x = screenWidth * 0.7 + 25
        y = (screenHeight / 2) - (#lines * 16 + 16) * descScale
        for i,line in ipairs(lines) do
            djui_hud_set_color_from_table(MENU_COLORS.desc)
            djui_hud_print_text(line, x, y, descScale)
            y = y + 32 * descScale
        end
    end

    if scroll then
        x = 50 - 16
        y = 50
        djui_hud_set_color_from_table(MENU_COLORS.scrollBg)
        djui_hud_render_rect(x, y, 20, screenHeight - 100)
        local portion = 1 / (maxDownBy+1)
        local height = (screenHeight - 104) * portion
        y = y + ((screenHeight - 104) - height) * downBy / maxDownBy
        if menuMotionEnabled and menuMotionScrollY ~= -1 then
            local prevY = menuMotionScrollY
            y = smooth_approach(y, prevY, 0.25)
            menuMotionScrollY = y
        else
            menuMotionScrollY = y
        end
        djui_hud_set_color_from_table(MENU_COLORS.scrollBar)
        djui_hud_render_rect(x + 2, y + 2, 16, height)
    end
end

-- menu controls
sMenuInputsPressed = 0
sMenuInputsDown = 0
---@param m MarioState
function menu_controls(m)
    if m.playerIndex ~= 0 then return end

    if m.freeze < 3 then m.freeze = 3 end

    -- Disable controls for everything but the menu
    sMenuInputsPressed = m.controller.buttonDown & (m.controller.buttonDown ~ sMenuInputsDown)
    sMenuInputsDown = m.controller.buttonDown
    m.controller.buttonDown = 0
    m.controller.buttonPressed = 0
    m.controller.stickX = 0
    m.controller.stickY = 0

    local stickX = m.controller.rawStickX
    if (sMenuInputsDown & L_JPAD) ~= 0 then
        stickX = stickX - 65
    end
    if (sMenuInputsDown & R_JPAD) ~= 0 then
        stickX = stickX + 65
    end
    local stickY = m.controller.rawStickY
    if (sMenuInputsDown & D_JPAD) ~= 0 then
        stickY = stickY - 65
    end
    if (sMenuInputsDown & U_JPAD) ~= 0 then
        stickY = stickY + 65
    end

    if stickCooldownY > 0 then stickCooldownY = stickCooldownY - 1 end
    if stickCooldownX > 0 then stickCooldownX = stickCooldownX - 1 end

    local menu = menu_data[menuID]
    if not menu then
        inMenu = false
        return
    end
    local button = menu[menuOption]

    if (sMenuInputsPressed & A_BUTTON) ~= 0 and button and button[2] and not button.runOnChange then
        if not option_valid(button) then
            play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource)
        else
            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource)
            button[2](button.currNum)
            if (network_is_server() or button.localSave) and button.save then
                mod_storage_save(button.save, tostring(button.currNum))
            end
        end
    elseif (sMenuInputsPressed & B_BUTTON) ~= 0 and not menu.noBack then
        if #menu_history ~= 0 then
            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource)
            enter_menu(menu_history[#menu_history][1], menu_history[#menu_history][2], true)
            table.remove(menu_history, #menu_history)
        else
            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource)
            m.controller.buttonDown = B_BUTTON
            inMenu = false
        end
    elseif (sMenuInputsPressed & L_TRIG) ~= 0 and button and button[2] and button.currNum then
        if not option_valid(button) then
            play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource)
        else
            button.currNum = button.minNum or 0
            play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource)

            button[2](button.currNum)
            if (network_is_server() or button.localSave) and button.save then
                mod_storage_save(button.save, tostring(button.currNum))
            end
        end
    elseif (sMenuInputsPressed & R_TRIG) ~= 0 then
        djui_open_pause_menu()
    elseif (sMenuInputsPressed & START_BUTTON) ~= 0 and not menu.noBack then
        play_sound(SOUND_MENU_PAUSE, gGlobalSoundSource)
        inMenu = false
        m.controller.buttonDown = sMenuInputsDown
        return
    end

    if not button then return end

    if button.currNum and stickCooldownX == 0 then
        local change = (sMenuInputsDown & (X_BUTTON | Z_TRIG) ~= 0 and 10) or 1
        if stickX > 64 then
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource)
            button.currNum = button.currNum + change
            local max = button.maxNum or 999
            if max == "total_ss" then
                max = #screenshots - 1
                if max < 0 then max = 0 end
            end

            if max < button.currNum then
                button.currNum = button.minNum or 0
            elseif max == button.excludeNum then
                button.currNum = button.currNum + 1
            end

            if button.playerRef then
                local np = gNetworkPlayers[button.currNum]
                while not np.connected do
                    button.currNum = button.currNum + 1
                    if max < button.currNum then
                        button.currNum = button.minNum or 0
                    elseif button.currNum == button.excludeNum then
                        button.currNum = button.currNum + 1
                    end
                    np = gNetworkPlayers[button.currNum]
                end
            end

            stickCooldownX = 5
            if button.runOnChange and button[2] then
                button[2](button.currNum)
                if (network_is_server() or button.localSave) and button.save then
                    mod_storage_save(button.save, tostring(button.currNum))
                end
            end
        elseif stickX < -64 then
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource)
            button.currNum = button.currNum - change
            local min = button.minNum or 0
            local max = button.maxNum or 999
            if button.currNum < min then
                button.currNum = max
            elseif button.currNum == button.excludeNum then
                button.currNum = button.currNum - 1
            end

            if button.playerRef then
                local np = gNetworkPlayers[button.currNum]
                while not np.connected do
                    button.currNum = button.currNum - 1
                    if button.currNum < min then
                        button.currNum = button.maxNum
                    elseif button.currNum == button.excludeNum then
                        button.currNum = button.currNum - 1
                    end
                    np = gNetworkPlayers[button.currNum]
                end
            end

            stickCooldownX = 5
            if button.runOnChange and button[2] then
                button[2](button.currNum)
                if (network_is_server() or button.localSave) and button.save then
                    mod_storage_save(button.save, tostring(button.currNum))
                end
            end
        end
    end

    if #menu > 1 and stickCooldownY == 0 then
        if stickY > 64 then
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource)
            local valid = true
            local LIMIT = #menu
            while valid and LIMIT ~= 0 do
                LIMIT = LIMIT - 1
                menuOption = menuOption - 1
                if menuOption < 1 then
                    menuOption = #menu
                end
                button = menu[menuOption]
                valid = not option_valid(button)
            end
            stickCooldownY = 5
        elseif stickY < -64 then
            play_sound(SOUND_MENU_CHANGE_SELECT, gGlobalSoundSource)
            local valid = true
            local LIMIT = #menu
            while valid and LIMIT ~= 0 do
                LIMIT = LIMIT - 1
                menuOption = menuOption + 1
                if #menu < menuOption then
                    menuOption = 1
                end
                button = menu[menuOption]
                valid = not option_valid(button)
            end
            stickCooldownY = 5
        end
    end
end

function open_menu()
    inMenu = not inMenu
    if inMenu then
        sMenuInputsDown = gControllers[0].buttonDown
        menu_history = {}
        enter_menu(1, 1, true)
    end
    return true
end

function enter_menu(id, option, back)
    if not back then
        table.insert(menu_history, { menuID, menuOption })
    end

    menuID = id or 1
    menuOption = option or 1

    -- check for valid options
    local menu = menu_data[menuID]
    if not menu then
        inMenu = false
        return
    elseif menu.buildFunc then
        menu_data[menuID] = { buildFunc = menu.buildFunc, title = menu.title }
        menu = menu_data[menuID]
        menu.buildFunc(menu)
    end
    local totalValid = 0
    local lastValidOption = 0
    for i = 1, #menu do
        if option_valid(menu[i]) then
            totalValid = totalValid + 1
            lastValidOption = i
        elseif menuOption == i then
            if lastValidOption == 0 then
                menuOption = menuOption + 1
            else
                menuOption = lastValidOption
            end
        end
    end

    if totalValid == 0 then
        if #menu_history ~= 0 then
            enter_menu(menu_history[#menu_history][1], menu_history[#menu_history][2], true)
            table.remove(menu_history, #menu_history)
        else
            inMenu = false
        end
        return
    end

    menu = menu_data[menuID]
    for i, button in ipairs(menu) do
        if button.save then
            local value = 0
            if not button.localSave then
                value = gGlobalSyncTable[button.save]
            else
                value = _ENV[button.save]
            end
            if type(value) == "boolean" then
                button.currNum = (value and 1) or 0
            elseif type(value) == "number" and value % 1 == 0 then
                button.currNum = value
                local min = button.minNum or 0
                local max = button.maxNum or 100
                if value < min then
                    button.currNum = min
                elseif value > max then
                    button.currNum = max
                end
            end
        end
        if button.updateNum then
            button.updateNum(button)
        end
    end
end

function set_menu_option(id, option, value)
    menu_data[id][option].currNum = value
end

function get_menu_option(id, option)
    return menu_data[id][option].currNum
end

function option_valid(button, ignoreSelect)
    if (not ignoreSelect) and button.selectInvalid and button.selectInvalid() then
        return false
    end

    if button[3] and not (network_is_server() or network_is_moderator()) then
        return false
    elseif type(button[4]) == "function" then
        return not (button[4]())
    end
    return true
end

function djui_hud_set_color_from_table(color, alpha)
    djui_hud_set_color(color.r or 255, color.g or 255, color.b or 255, alpha or color.a or 255)
end

-- returns the current value approach the goal value at some rate (50% for going halfway there each time, etc)
function smooth_approach(goal, current, rate)
    local diff = (goal - current)
    local result = goal
    if diff > 1 then
        result = current + math.ceil(diff * rate)
    elseif diff < 1 then
        result = current + math.floor(diff * rate)
    end
    return result
end

function render_ingredient_icon(item, x, y, scaleX, scaleY, allowHeatIcon, forceHeatIcon)
    local tex = ITEM_DATA[item].icon
    if tex then
        local texWidth = tex.width * scaleX
        local itemX = x - texWidth / 2
        
        djui_hud_render_texture(tex, itemX, y, scaleX, scaleY)
        local subTex = ITEM_DATA[item].subIcon
        if allowHeatIcon and (forceHeatIcon or ITEM_DATA[item].isCooked) then
            subTex = ICON_HEAT
        end
        if subTex then
            local texHeight = tex.height * scaleY
            local subTexWidth = subTex.width * scaleX
            local subTexHeight = subTex.height * scaleX
            itemX = x + texWidth / 2 - subTexWidth
            djui_hud_render_texture(subTex, itemX, y + texHeight - subTexHeight, scaleX, scaleY)
        end
    else
        local text = string.format("%02X", item)
        local texWidth = 16 * scaleX
        local itemX = x - texWidth / 2
        djui_hud_print_text(text, itemX, y, scaleX / 2, scaleY)
    end
end

function render_ingredient_icon_interpolated(item, prevX, prevY, prevScaleX, prevScaleY, x, y, scaleX, scaleY, allowHeatIcon, forceHeatIcon)
    local tex = ITEM_DATA[item].icon
    if tex then
        local texWidth = tex.width * scaleX
        local prevTexWidth = tex.width * prevScaleX
        local itemX = x - texWidth / 2
        local prevItemX = prevX - prevTexWidth / 2
        
        djui_hud_render_texture_interpolated(tex, prevItemX, prevY, prevScaleX, prevScaleY, itemX, y, scaleX, scaleY)
        local subTex = ITEM_DATA[item].subIcon
        if allowHeatIcon and (forceHeatIcon or ITEM_DATA[item].isCooked) then
            subTex = ICON_HEAT
        end
        if subTex then
            local texHeight = tex.height * scaleY
            local prevTexHeight = tex.height * prevScaleY
            local subTexWidth = subTex.width * scaleX
            local subTexHeight = subTex.height * scaleY
            local prevSubTexWidth = subTex.width * prevScaleX
            local prevSubTexHeight = subTex.height * prevScaleY
            itemX = x + texWidth / 2 - subTexWidth
            prevItemX = prevX + prevTexWidth / 2 - prevSubTexWidth
            djui_hud_render_texture_interpolated(subTex, prevItemX, prevY + prevTexHeight - prevSubTexHeight, prevScaleX, prevScaleY, itemX, y + texHeight - subTexHeight, scaleX, scaleY)
        end
    else
        y = y - 10 * scaleY
        prevY = prevY - 10 * prevScaleY

        local text = string.format("%02X", item)
        local texWidth = 16 * scaleX
        local prevTexWidth = 16 * prevScaleX
        local itemX = x - texWidth / 2
        local prevItemX = prevX - prevTexWidth / 2
        djui_hud_print_text_interpolated(text, prevItemX, prevY, prevScaleX / 2, prevScaleY, itemX, y, scaleX / 2, scaleY)
    end
end