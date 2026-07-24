function on_hud_render()
    djui_hud_set_resolution(RESOLUTION_DJUI)
    hud_hide()
    djui_hud_set_font(FONT_CUSTOM_HUD)
    djui_hud_reset_color()
    djui_hud_reset_text_color()

    local screenWidth = djui_hud_get_screen_width()
    local intendedX = 10
    local y = 0
    local scale = 2
    local widthPerItem = 30
    for i, pending_data in ipairs(pending_orders) do
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
        djui_hud_set_color(color.r, color.g, color.b, alpha)
        -- split into 3 segments
        local segmentX = x
        local prevSegmentX = prevX
        for a=1,3 do
            local segmentWidth = math.min(maxTimerWidth / 3, timerWidth)
            local prevSegmentWidth = math.min(maxTimerWidth / 3, prevTimerWidth)
            djui_hud_render_rect_interpolated(prevSegmentX, y, prevSegmentWidth, 10 * scale, segmentX, y, segmentWidth, 10 * scale)
            segmentX = segmentX + maxTimerWidth / 3 + 5 * scale
            prevSegmentX = prevSegmentX + maxTimerWidth / 3 + 5 * scale
            timerWidth = timerWidth - segmentWidth
            prevTimerWidth = prevTimerWidth - prevSegmentWidth
            if timerWidth <= 0 and prevTimerWidth <= 0 then break end
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

    --scale = scale * 2
    djui_hud_reset_color()
    djui_hud_reset_text_color()
    djui_hud_set_text_alignment(TEXT_HALIGN_RIGHT, TEXT_VALIGN_BOTTOM)
    intendedX = djui_hud_get_screen_width() - 20
    y = djui_hud_get_screen_height() - 20
    djui_hud_print_text(time_format(gGlobalSyncTable.timeLeft), intendedX, y, scale, scale)
    y = y - 32 * scale
    djui_hud_print_text("Tip x"..gGlobalSyncTable.tipMulti, intendedX, y, scale, scale)
    y = y - 32 * scale
    djui_hud_print_text("$"..tostring(gGlobalSyncTable.score), intendedX, y, scale, scale)
end
hook_event(HOOK_ON_HUD_RENDER, on_hud_render)

function render_ingredient_icon(item, x, y, scaleX, scaleY, allowHeatIcon)
    local tex = ITEM_DATA[item].icon
    if tex then
        local texWidth = tex.width * scaleX
        local itemX = x - texWidth / 2
        
        djui_hud_render_texture(tex, itemX, y, scaleX, scaleY)
        local subTex = ITEM_DATA[item].subIcon
        if allowHeatIcon and ITEM_DATA[item].isCooked then
            subTex = gTextures.star -- Heat icon (TEMP)
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

function render_ingredient_icon_interpolated(item, prevX, prevY, prevScaleX, prevScaleY, x, y, scaleX, scaleY, allowHeatIcon)
    local tex = ITEM_DATA[item].icon
    if tex then
        local texWidth = tex.width * scaleX
        local prevTexWidth = tex.width * prevScaleX
        local itemX = x - texWidth / 2
        local prevItemX = prevX - prevTexWidth / 2
        
        djui_hud_render_texture_interpolated(tex, prevItemX, prevY, prevScaleX, prevScaleY, itemX, y, scaleX, scaleY)
        local subTex = ITEM_DATA[item].subIcon
        if allowHeatIcon and ITEM_DATA[item].isCooked then
            subTex = gTextures.star -- Heat icon (TEMP)
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