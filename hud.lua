function playing_hud()
    local screenWidth = djui_hud_get_screen_width()
    local intendedX = 10
    local y = 0
    local scale = 2
    local widthPerItem = 30
    for i, pending_data in ipairs(pending_orders) do
        if pending_data.kitchen == gPlayerSyncTable[0].kitchen then
            local x = screenWidth + intendedX
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
                if pending_data.vanishTimer <= 0 then
                    table.remove(pending_orders, i)
                    alpha = 0
                else
                    alpha = (alpha * pending_data.vanishTimer // 30)
                    pending_data.vanishTimer = pending_data.vanishTimer - 1
                end
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

            intendedX = intendedX + width + 10 * scale
        end
    end

    djui_hud_reset_color()
    djui_hud_reset_text_color()
    djui_hud_set_text_alignment(TEXT_HALIGN_LEFT, TEXT_VALIGN_BOTTOM)

    -- score and tip combo
    scale = scale * 2
    local x = 20
    y = djui_hud_get_screen_height() - 8 * scale
    djui_hud_render_texture(gTextures.coin, x, y - 22 * scale, scale, scale)
    x = x + 16 * scale
    djui_hud_print_text(tostring(gGlobalSyncTable.score), x, y, scale)
    scale = scale / 2
    x = 20
    y = y + 16 * scale
    local tipMulti = gGlobalSyncTable["tipMulti"..gPlayerSyncTable[0].kitchen] or 1
    djui_hud_print_text("Tip *"..tipMulti, x, y, scale)
    
    scale = scale * 2
    x = djui_hud_get_screen_width() - 32
    y = djui_hud_get_screen_height()
    djui_hud_set_text_alignment(TEXT_HALIGN_RIGHT, TEXT_VALIGN_BOTTOM)
    djui_hud_print_text(time_format(gGlobalSyncTable.timeLeft), x, y, scale)
end

function end_hud()
    local screenWidth, screenHeight = djui_hud_get_screen_width(), djui_hud_get_screen_height()
    djui_hud_set_color(0, 0, 0, 100)
    djui_hud_render_rect(0, 0, screenWidth + 16, screenHeight + 16)

    djui_hud_reset_color()
    local scale = 8
    local text = tostring(gGlobalSyncTable.score)
    local width = (16 + djui_hud_measure_text(text)) * scale
    local x = (screenWidth - width) / 2
    local y = screenHeight / 2 - 8 * scale
    djui_hud_render_texture(gTextures.coin, x, y, scale, scale)
    x = x + 16 * scale
    djui_hud_set_text_alignment(TEXT_HALIGN_LEFT, TEXT_VALIGN_TOP)
    djui_hud_print_text(text, x, y, scale)

    -- Star requirements are based on how many players.
    local lData = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel]
    local stars = 4
    local neededPoints = {9999, 9999, 9999, 9999}
    if lData and lData.starScores then
        local maxKitchens = gGlobalSyncTable.maxKitchens
        local maxPlayers = network_player_connected_count()

        if maxKitchens == 1 then
            neededPoints = lData.starScores[math.clamp(maxPlayers, 1, 4)]
        else
            -- If there are more than 4 players, we add based on the amount of players in each kitchen.
            -- For example, 5 players expects the 2 and 3 players scores added together.   
            neededPoints = {0, 0, 0, 0}
            while maxKitchens ~= 0 do
                local players = math.clamp(math.ceil(maxPlayers / maxKitchens), 1, 4)
                for i=1,4 do
                    neededPoints[i] = neededPoints[i] + lData.starScores[players][i]
                end
                maxKitchens = maxKitchens - 1
                maxPlayers = maxPlayers - players
            end
        end
    end
    while stars > 0 do
        if gGlobalSyncTable.score >= neededPoints[stars] then break end
        stars = stars - 1
    end
    local maxStars = math.clamp(stars + 1, 3, 4)

    djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
    x = screenWidth / 2 - (10 * (maxStars - 1)) * scale
    for i=1,maxStars do
        y = screenHeight / 2 + 24 * scale
        if i <= stars then
            djui_hud_set_color(255, 255, 255, 255)
        else
            djui_hud_set_color(0, 0, 0, 100)
        end
        djui_hud_render_texture(gTextures.star, x - 8 * scale, y, scale, scale)
        y = y + 16 * scale
        djui_hud_set_color(255, 255, 255, 255)
        djui_hud_print_text(tostring(neededPoints[i]), x, y, scale / 4)
        x = x + 20 * scale
    end
end

function setup_hud()
    if gGlobalSyncTable.timeLeft <= 3 then return end
    local screenWidth, screenHeight = djui_hud_get_screen_width(), djui_hud_get_screen_height()

    local scale = 4
    local x = screenWidth / 2
    local y = 20
    djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
    djui_hud_print_text(time_format(gGlobalSyncTable.timeLeft-1), x, y, scale)

    if gMarioStates[0].actionState == 0 then
        x = x - 70 * scale
        y = screenHeight - 60 * scale
        if gMarioStates[0].actionArg ~= 0 then
            y = y + 20 * scale
        end
        render_ingredient_icon(ITEM_TOMATO, x, y, scale, scale)

        y = screenHeight - 60 * scale
        x = x + 20 * scale
        djui_hud_set_text_alignment(TEXT_HALIGN_LEFT, TEXT_VALIGN_TOP)
        djui_hud_print_text("Kitchen: "..(gPlayerSyncTable[0].kitchen+1), x, y, scale)
        y = y + 20 * scale
        djui_hud_print_text("Spawn Point: "..(gPlayerSyncTable[0].spawnID+1), x, y, scale)

        djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
        x = screenWidth / 2
        y = y + 20 * scale
        djui_hud_print_text("Hold A to confirm...", x, y, scale)
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

    if gGlobalSyncTable.gameState == GAME_STATE_PLAYING then
        playing_hud()
    elseif gGlobalSyncTable.gameState == GAME_STATE_END then
        end_hud()
    elseif gGlobalSyncTable.gameState == GAME_STATE_SETUP then
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
            radar.scale = 2000 / -out.z
            table.insert(toRenderObj, {out.z, o})
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
        local iData = ITEM_DATA[o.oBehParams]
        local items = {}
        local children = {o}
        local allCooked = (iData.isCooked or false)
        if iData.isPlate then
            children = find_all_object_children(o, id_bhvIngredient)
        elseif o.parentObj and o.parentObj ~= o and o.oHeldState == HELD_FREE then
            children = {} -- Don't render if on plate
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

        if #items ~= 0 then
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
            else
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
    end
end
hook_event(HOOK_ON_HUD_RENDER_BEHIND, behind_hud_render)

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