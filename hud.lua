local FLAME_ANIM = {"flame_seg3_texture_03017320", "flame_seg3_texture_03017B20", "flame_seg3_texture_03018320", "flame_seg3_texture_03018B20", "flame_seg3_texture_03019320", "flame_seg3_texture_03019B20", "flame_seg3_texture_0301A320", "flame_seg3_texture_0301AB20"}
local HUD_LOCATIONS = {
    {10, false},
    {10, true},
    {180, false},
    {430, true},
}

scoreModifiers = {}
function playing_hud()
    local screenWidth = djui_hud_get_screen_width()
    local intendedX = HUD_LOCATIONS[orderHUDLocation+1][1] or 10
    local fromRight = HUD_LOCATIONS[orderHUDLocation+1][2] or false
    if fromRight then
        intendedX = screenWidth - intendedX
    end

    local y = 0
    local scale = 2
    local widthPerItem = 25
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
        local r = 0
        if pending_data.vanishTimer then
            alpha = (alpha * pending_data.vanishTimer // 30)
        elseif pending_data.redTimer then
            r = (255 * pending_data.redTimer // 30)
            pending_data.redTimer = pending_data.redTimer - 1
            if pending_data.redTimer == 0 then pending_data.redTimer = nil end
        end

        local order = ORDER_DATA[pending_data.id]
        local item_groups = {}
        for a, item in ipairs(order.items) do
            local items = {}
            if not ITEM_DATA[item.type].skipItem then
                table.insert(items, item.type)
            end
            if ITEM_DATA[item.type].isCooked and ITEM_DATA[item.type].cookIcon then
                if ITEM_DATA[item.type].cookIcon[1] then -- support table of icons
                    items.cookIcons = ITEM_DATA[item.type].cookIcon
                else
                    items.cookIcons = {ITEM_DATA[item.type].cookIcon}
                end
            end
            if item.contents then
                for b, subitem in ipairs(item.contents) do
                    table.insert(items, subitem)
                end
            end
            if #items ~= 0 then
                table.insert(item_groups, items)
            end
        end

        y = 0
        local width = -5 * scale
        for a, items in ipairs(item_groups) do
            width = width + (5 + #items * widthPerItem) * scale
        end
        width = math.max(width, 2 * widthPerItem * scale)

        if fromRight then
            x = x - width
            prevX = prevX - width
        end
        djui_hud_set_color(255, 255 - r, 255 - r, alpha)
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
        djui_hud_set_color(255, 255 - r, 255 - r, alpha)
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
            djui_hud_print_text_interpolated(text, prevItemX, y + 15 * (scale - itemScale), textScale, itemScale, itemX, y + 15 * (scale - itemScale), textScale, itemScale)
        end

        -- items
        local rectWidth = widthPerItem * scale
        local rectX = x
        local prevRectX = prevX
        y = y + 42 * scale
        itemScale = scale
        for a, items in ipairs(item_groups) do
            if items.cookIcons then
                local iconWidth = items.cookIcons[1].width
                local totalWidth = #items * rectWidth
                djui_hud_render_rect_interpolated(prevRectX, y + 18 * scale, totalWidth, 20 * scale, rectX, y + 18 * scale, totalWidth, 20 * scale)
                
                local iconStartX = (totalWidth - ((iconWidth + 2) * #items.cookIcons - 2) * itemScale) / 2
                local iconX = rectX + iconStartX
                local prevIconX = prevRectX + iconStartX
                for b, icon in ipairs(items.cookIcons) do
                    djui_hud_render_texture_interpolated(icon, prevIconX, y + 20 * itemScale, itemScale, itemScale, iconX, y + 20 * itemScale, itemScale, itemScale)
                    iconX = iconX + (iconWidth + 4) * itemScale
                    prevIconX = prevIconX + (iconWidth + 4) * itemScale
                end
            end

            for b, item in ipairs(items) do
                djui_hud_render_rect_interpolated(prevRectX, y - 2 * scale, rectWidth, 20 * scale, rectX, y - 2 * scale, rectWidth, 20 * scale)
                local itemX = rectX + rectWidth / 2
                local prevItemX = prevRectX + rectWidth / 2
                render_ingredient_icon_interpolated(item, prevItemX, y, itemScale, itemScale, itemX, y, itemScale, itemScale)
                if (not items.cookIcons) and (ITEM_DATA[item].isCooked and ITEM_DATA[item].cookIcon) then
                    djui_hud_render_rect_interpolated(prevRectX, y + 18 * scale, rectWidth, 20 * scale, rectX, y + 18 * scale, rectWidth, 20 * scale)
                    local cookTex = ITEM_DATA[item].cookIcon
                    if cookTex[1] then cookTex = cookTex[1] end
                    djui_hud_render_texture_interpolated(cookTex, prevItemX - cookTex.width * itemScale / 2, y + 20 * scale, itemScale, itemScale, itemX - cookTex.width * itemScale / 2, y + 20 * itemScale, itemScale, itemScale)
                end
                rectX = rectX + rectWidth
                prevRectX = prevRectX + rectWidth
            end

            rectX = rectX + 5 * scale
            prevRectX = prevRectX + 5 * scale
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

    -- score
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
    -- modifers (+30, etc.)
    for i, data in ipairs(scoreModifiers) do
        local text = tostring(data.value)
        if not data.inited then
            data.y = 0
            data.prevY = 0
            data.vanishTimer = 30
            data.inited = true
        else
            data.prevY = data.y
            data.y = data.y + 1
            data.vanishTimer = data.vanishTimer - 1
            if data.vanishTimer == 0 then
                table.remove(scoreModifiers, i)
            end
        end
        djui_hud_set_font(FONT_RECOLOR_HUD)
        if data.value > 0 then
            text = "+"..text
            djui_hud_set_text_color(0, 255, 0, data.vanishTimer * 200 // 30)
        else
            djui_hud_set_text_color(255, 0, 0, data.vanishTimer * 200 // 30)
        end
        djui_hud_print_text_interpolated(text, x, y - (data.prevY + 16) * scale, scale, x, y - (data.y + 16) * scale, scale)
        djui_hud_set_font(FONT_CUSTOM_HUD)
        djui_hud_reset_text_color()
    end
    -- tip combo
    scale = scale / 2
    x = 20
    y = y + 16 * scale
    djui_hud_print_text("Tip *"..tipMulti, x, y, scale)

    -- timer
    scale = scale * 2
    x = djui_hud_get_screen_width() - 32
    y = djui_hud_get_screen_height()
    djui_hud_set_text_alignment(TEXT_HALIGN_RIGHT, TEXT_VALIGN_BOTTOM)
    djui_hud_print_text(time_format(gGlobalSyncTable.timeLeft), x, y, scale)

    -- cooking indicators (if enabled)
    if showCookIndicators then
        x = djui_hud_get_screen_width() - 32
        y = djui_hud_get_screen_height() - 20 * scale
        scale = scale / 2
        local o = obj_get_first_with_behavior_id(id_bhvIngredient)
        while o do
            -- notification for cooking progress
            if o.oNotifyTimer ~= 0 then
                local text = (o.oOvercookTimer >= 5 * 30 and "!!!") or trans("cook_done")
                local alpha = 255
                if o.oNotifyTimer > 20 then
                    alpha = ((30 - o.oNotifyTimer) / 10) * alpha
                elseif o.oNotifyTimer < 10 then
                    alpha = (o.oNotifyTimer / 10) * alpha
                end
                o.oNotifyTimer = o.oNotifyTimer - 1
                djui_hud_set_color(255, 255, 255, alpha)
                djui_hud_print_text(text, x, y, scale)
                y = y - 32 * scale
            end
            o = obj_get_next_with_same_behavior_id(o)
        end
    end
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
    x = screenWidth / 2 - (10 * (maxStars - 1) + 20) * scale -- center align after writing player count
    y = screenHeight / 2 + 24 * scale
    djui_hud_print_text(trans("short_player_count", gGlobalSyncTable.peakPlayers), x, y + 5 * scale, scale / 2)
    x = x + 20 * scale
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
    local x = 20
    local y = 20
    djui_hud_set_text_alignment(TEXT_HALIGN_LEFT, TEXT_VALIGN_TOP)
    local timeLeft = gGlobalSyncTable.timeLeft - 3
    if timeLeft <= 0 then timeLeft = timeLeft + 3 end
    djui_hud_print_text(time_format(timeLeft), x, y, scale)

    -- level title
    x = screenWidth / 2
    djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
    local titleScale = scale
    local lData = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel]
    local text = get_level_translated_field(gGlobalSyncTable.ocLevel, "name") or "???"
    local width = djui_hud_measure_text(text) * titleScale
    if width > screenWidth * 0.7 then
        titleScale = (screenWidth * 0.7) / width * titleScale
    end
    djui_hud_print_text(text, x, y, titleScale, titleScale)

    -- advice
    if lData.advice then
        y = 50 * scale
        local adviceScale = scale / 2
        local buttonNames = { "X", "Y", "L", "B" }
        text = trans("tip")

        local advice = get_level_translated_field(gGlobalSyncTable.ocLevel, "advice") or "???"
        advice = advice:gsub("%[GRAB%]", "["..buttonNames[grabButtonIndex+1].."]")
        advice = advice:gsub("%[ACTION%]", "["..buttonNames[actionButtonIndex+1].."]")
        advice = advice:gsub("%[THROW%]", "["..buttonNames[throwButtonIndex+1].."]")

        for i, word in ipairs(split(advice, " ")) do
            local newText = text
            if #newText == 0 then
                newText = word
            else
                newText = newText .. " " .. word
            end
            width = djui_hud_measure_text(newText) * adviceScale
            if width < screenWidth * 0.7 then
                text = newText
            else
                text = text .. "\n" .. word
            end
        end
        djui_hud_set_font(FONT_RECOLOR_HUD)
        djui_hud_set_text_color(0, 255, 200, 255)
        djui_hud_print_text(text, x, y, adviceScale, adviceScale)
        djui_hud_set_font(FONT_CUSTOM_HUD)
        djui_hud_reset_text_color()
    end

    -- stars
    local starScale = scale
    local maxScorePlayers = get_record_for_level(gGlobalSyncTable.ocLevel, gGlobalSyncTable.peakPlayers)
    local stars = 4
    local maxStars = get_star_record(gGlobalSyncTable.ocLevel)
    maxStars = math.clamp(maxStars + 1, 3, 4)
    local neededPoints = get_star_scores(gGlobalSyncTable.ocLevel)
    while stars > 0 do
        if maxScorePlayers >= neededPoints[stars] then break end
        stars = stars - 1
    end
    x = screenWidth / 2 - (10 * (maxStars - 1) + 20) * starScale -- center align after writing player count
    y = 32 + 16 * scale
    djui_hud_print_text(trans("short_player_count", gGlobalSyncTable.peakPlayers), x, y + 5 * starScale, starScale / 2)
    x = x + 20 * starScale
    for i=1,maxStars do
        y = 32 + 16 * scale
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

    -- spawn placement
    x = screenWidth / 2
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

        text = trans("kitchen")
        djui_hud_set_color(255, 255, 255, 255)
        if gGlobalSyncTable.maxKitchens <= 1 then
            text = text .. ": 1"
            djui_hud_set_color(100, 100, 100, 255)
        else
            text = text .. " <"..(gPlayerSyncTable[0].kitchen) .. ">"
        end
        djui_hud_print_text(text, x, y, scale)

        y = y + 20 * scale
        local maxSpawnID = math.ceil(gGlobalSyncTable.peakPlayers / gGlobalSyncTable.maxKitchens)
        text = trans("spawn_point")
        djui_hud_set_color(255, 255, 255, 255)
        if maxSpawnID <= 1 then
            text = text .. ": 1"
            djui_hud_set_color(100, 100, 100, 255)
        else
            text = text .. " <"..(gPlayerSyncTable[0].spawnID+1) .. ">"
        end
        djui_hud_print_text(text, x, y, scale)

        djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
        x = screenWidth / 2
        y = y + 20 * scale
        text = trans("confirm_key")
        if confirmTime < 0 then
            text = trans("taken")
        elseif confirmTime ~= 0 then
            local width = djui_hud_measure_text(text) * scale
            local barWidth = width * (confirmTime / 30)
            djui_hud_set_color(0, 255, 0, 255)
            djui_hud_render_rect(x - width / 2, y, barWidth, 18 * scale)
        end
        djui_hud_set_color(255, 255, 255, 255)
        djui_hud_print_text(text, x, y, scale)
    else
        y = screenHeight - 20 * scale
        djui_hud_print_text(trans("ready"), x, y, scale)
    end
end

function level_select_hud()
    scale = 2
    x = djui_hud_get_screen_width() - 32
    y = djui_hud_get_screen_height()
    djui_hud_set_text_alignment(TEXT_HALIGN_RIGHT, TEXT_VALIGN_BOTTOM)
    local text = trans("waiting_for_host")
    if gPlayerSyncTable[0].inPractice then
        text = trans("menu_practice")
    elseif gGlobalSyncTable.autoStart then
        text = time_format(gGlobalSyncTable.timeLeft)
    elseif network_is_server() or network_is_moderator() then
        text = trans("press_start")
    end
    djui_hud_print_text(text, x, y, scale)

    -- cooking indicators (if enabled)
    if showCookIndicators then
        x = djui_hud_get_screen_width() - 32
        y = djui_hud_get_screen_height() - 20 * scale
        local o = obj_get_first_with_behavior_id(id_bhvIngredient)
        while o do
            -- notification for cooking progress
            if o.oNotifyTimer ~= 0 then
                local text = (o.oOvercookTimer >= 5 * 30 and "!!!") or trans("cook_done")
                local alpha = 255
                if o.oNotifyTimer > 20 then
                    alpha = ((30 - o.oNotifyTimer) / 10) * alpha
                elseif o.oNotifyTimer < 10 then
                    alpha = (o.oNotifyTimer / 10) * alpha
                end
                o.oNotifyTimer = o.oNotifyTimer - 1
                djui_hud_set_color(255, 255, 255, alpha)
                djui_hud_print_text(text, x, y, scale)
                y = y - 32 * scale
            end
            o = obj_get_next_with_same_behavior_id(o)
        end
    end
end

function advice_hud()
    local screenWidth, screenHeight = djui_hud_get_screen_width(), djui_hud_get_screen_height()

    local scale = 4
    local x = 20
    local y = 20
    djui_hud_set_text_alignment(TEXT_HALIGN_LEFT, TEXT_VALIGN_TOP)
    djui_hud_print_text(time_format(gGlobalSyncTable.timeLeft), x, y, scale)

    -- level title
    x = screenWidth / 2
    djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
    local titleScale = scale
    local lData = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel]
    local text = get_level_translated_field(gGlobalSyncTable.ocLevel, "name") or "???"
    local width = djui_hud_measure_text(text) * titleScale
    if width > screenWidth * 0.7 then
        titleScale = (screenWidth * 0.7) / width * titleScale
    end
    djui_hud_print_text(text, x, y, titleScale, titleScale)

    -- advice + picture
    if lData.tutorial then
        local texScale = scale / 2
        local tex = get_texture_info("tip_bg")
        x = (screenWidth - tex.width * texScale) / 2
        y = (screenHeight - tex.height * texScale) / 2
        djui_hud_reset_color()
        djui_hud_render_texture(tex, x, y, texScale, texScale)
        if lData.tutorialPic then
            djui_hud_render_texture(lData.tutorialPic, x, y, texScale, texScale)
        end

        x = screenWidth / 2
        y = y + 7.5 * scale
        local adviceScale = scale / 2
        local buttonNames = { "X", "Y", "L", "B" }
        text = ""

        local advice = get_level_translated_field(gGlobalSyncTable.ocLevel, "tutorial") or "???"
        advice = advice:gsub("%[GRAB%]", "["..buttonNames[grabButtonIndex+1].."]")
        advice = advice:gsub("%[ACTION%]", "["..buttonNames[actionButtonIndex+1].."]")
        advice = advice:gsub("%[THROW%]", "["..buttonNames[throwButtonIndex+1].."]")

        for i, word in ipairs(split(advice, " ")) do
            local newText = text
            if #newText == 0 then
                newText = word
            else
                newText = newText .. " " .. word
            end
            width = djui_hud_measure_text(newText) * adviceScale
            if width < (tex.width - 16) * texScale then
                text = newText
            else
                text = text .. "\n" .. word
            end
        end
        djui_hud_set_font(FONT_RECOLOR_HUD)
        djui_hud_set_text_color(0, 255, 200, 255)
        djui_hud_print_text(text, x, y, adviceScale, adviceScale)
        djui_hud_set_font(FONT_CUSTOM_HUD)
        djui_hud_reset_text_color()
    end

    -- spawn placement
    x = screenWidth / 2
    if gMarioStates[0].action == ACT_SELECT_START and not gPlayerSyncTable[0].readyToStart then
        djui_hud_set_text_alignment(TEXT_HALIGN_CENTER, TEXT_VALIGN_TOP)
        y = screenHeight - 20 * scale
        text = trans("confirm_key")
        if confirmTime > 0 then
            local width = djui_hud_measure_text(text) * scale
            local barWidth = width * (confirmTime / 30)
            djui_hud_set_color(0, 255, 0, 255)
            djui_hud_render_rect(x - width / 2, y, barWidth, 18 * scale)
        end
        djui_hud_set_color(255, 255, 255, 255)
        djui_hud_print_text(text, x, y, scale)
    else
        y = screenHeight - 20 * scale
        djui_hud_print_text(trans("ready"), x, y, scale)
    end
end

function on_hud_render()
    djui_hud_set_resolution(RESOLUTION_DJUI)
    djui_hud_set_font(FONT_CUSTOM_HUD)
    djui_hud_reset_color()
    djui_hud_reset_text_color()

    if inMenu then
        render_menu()
    elseif hideOcHud then
        -- nothing
    elseif gPlayerSyncTable[0].inPractice or gGlobalSyncTable.gameState == GAME_STATE_LEVEL_SELECT then
        level_select_hud()
    elseif gGlobalSyncTable.gameState == GAME_STATE_PLAYING then
        lastHudScore = 0
        playing_hud()
    elseif gGlobalSyncTable.gameState == GAME_STATE_END then
        scoreModifiers = {}
        end_hud()
    elseif gGlobalSyncTable.gameState == GAME_STATE_SETUP then
        lastHudScore = 0
        scoreModifiers = {}
        setup_hud()
    elseif gGlobalSyncTable.gameState == GAME_STATE_ADVICE then
        lastHudScore = 0
        scoreModifiers = {}
        advice_hud()
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

    if hideOcHud then return end

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

    -- render progress bar for sinks (+ counter button prompt)
    o = obj_get_first_with_behavior_id(id_bhvCounter)
    while o do
        if (grabPromptValid and o == selectedCounter and selectedItem == nil)
        or (o.oBehParams2ndByte == COUNTER_TYPE_SINK and o.oPlateAppearTimer ~= 0) then
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
                    allCooked = false
                else
                    local iDataC = ITEM_DATA[c.oBehParams]
                    if iDataC.icon and not (iDataC.noTrash or iDataC.skipItem) then
                        table.insert(items, c.oBehParams)
                    end
                    
                    if c.oContentCount ~= 0 then
                        local maxCookTime = iDataC.cookTime or DEFAULT_COOK_TIME
                        allCooked = allCooked or iDataC.isCooked or (iDataC.cookType == COOK_TYPE_HEAT and c.oCutOrCookTimer >= maxCookTime)

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

            if #items ~= 0 or o.oCutOrCookTimer ~= 0 or o.oNotifyTimer ~= 0 or (grabPromptValid and o == selectedItem) then
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
                if #items == 1 then
                    render_ingredient_icon_interpolated(items[1], prevX, prevY, prevScale, prevScale, x, y, scale, scale, true, allCooked)
                elseif #items ~= 0 then
                    local maxColumns = 3
                    local columns = math.min(#items, maxColumns)
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
                    elseif iData.cookType then
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
                    local text = (o.oOvercookTimer >= 5 * 30 and "!!!") or trans("cook_done")
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
                    if (gGlobalSyncTable.gameState ~= GAME_STATE_PLAYING and gGlobalSyncTable.gameState ~= GAME_STATE_LEVEL_SELECT) or not showCookIndicators then
                        o.oNotifyTimer = o.oNotifyTimer - 1
                    end
                    djui_hud_set_color(255, 255, 255, alpha)
                    djui_hud_print_text_interpolated(text, prevX, prevY, prevScale, x, y, scale)
                end
                -- button prompt
                if grabPromptValid and o == selectedItem and o.oHeldState == HELD_FREE then
                    local buttonIndex = grabButtonIndex
                    if iData.cut then
                        local counter = o.usingObj
                        if counter and counter.oBehParams2ndByte == COUNTER_TYPE_CUT then
                            buttonIndex = actionButtonIndex
                        end
                    end
                    local tex = get_texture_info("button_"..buttonIndex)
                    x = radar.x - tex.width * scale / 2
                    y = radar.y + 20 * scale
                    prevX = radar.prevX - tex.width * prevScale / 2
                    prevY = radar.prevY + 20 * prevScale
                    djui_hud_set_color(255, 255, 255, 255)
                    djui_hud_render_texture_interpolated(tex, prevX, prevY, prevScale, prevScale, x, y, scale, scale)
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

            if o.oBehParams2ndByte == COUNTER_TYPE_SINK then
                radar.barWidth = o.oPlateAppearTimer / (3 * 30)
                if radar.barWidth ~= 0 and radar.barWidth ~= 1 then
                    local width = 40 * radar.barWidth
                    djui_hud_render_rect_interpolated(prevX, prevY, 40 * prevScale, 10 * prevScale, x, y, 40 * scale, 10 * scale)
                    djui_hud_set_color(0, 255, 0, 255)
                    djui_hud_render_rect_interpolated(prevX, prevY, width * prevScale, 10 * prevScale, x, y, width * scale, 10 * scale)
                end
            end

            -- button prompt
            local washable = (gMarioStates[0].heldObj == nil and o.oBehParams2ndByte == COUNTER_TYPE_SINK and o.oPlatesStackedExtra ~= 0)
            if o == selectedCounter and ((selectedItem == nil and grabPromptValid) or washable) then
                local buttonIndex = (washable and actionButtonIndex) or grabButtonIndex
                local tex = get_texture_info("button_"..buttonIndex)
                x = radar.x - tex.width * scale / 2
                y = radar.y
                prevX = radar.prevX - tex.width * prevScale / 2
                prevY = radar.prevY
                djui_hud_set_color(255, 255, 255, 255)
                djui_hud_render_texture_interpolated(tex, prevX, prevY, prevScale, prevScale, x, y, scale, scale)
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
    local min = 0
    -- Unlock test level if we've 3 starred every other level
    if not (cheatsApi or mod_storage_load_bool("unlockTestLevel")) then
        for i=1,#OC_LEVEL_DATA do
            local stars = get_star_record(i)
            if stars < 3 then
                min = 1
                break
            end
        end
        if min == 0 then
            djui_popup_create("You've 3 starred every stage!\nYou've unlocked the Test Level!", 2)
            mod_storage_save_bool("unlockTestLevel", true)
        end
    end
    local unclearedLevel = false

    for i=min,#OC_LEVEL_DATA do
        local levelName = get_level_translated_field(i, "name")
        local desc = get_level_translated_field(i, "desc") or trans("menu_no_desc")
        desc = desc .. "\n\n"
        local bestOverallScore, bestOverallStars, bestOverallPlayers = get_record_for_level(i)

        local bestStars = 0
        local maxStars = 3
        if bestOverallScore ~= 0 then
            -- score for this many players
            local players = gGlobalSyncTable.peakPlayers
            local bestPlayerScore, bestPlayerStars = get_record_for_level(i, players)

            -- score for the most stars obtained
            local bestStarsScore, bestStarsPlayers = 0, 0
            bestStarsScore, bestStars, bestStarsPlayers = get_record_for_level(i, 0, true)

            maxStars = math.clamp(bestStars+1, 3, 4)
            for stars=1,maxStars do
                desc = desc .. string.rep("", stars) .. ": %d\n"
            end

            local starStrPlayer = (bestPlayerStars == 0 and "0") or string.rep("", bestPlayerStars)
            local starStrMostStars = (bestStars == 0 and "0") or string.rep("", bestStars)
            local starStrOverall = (bestOverallStars == 0 and "0") or string.rep("", bestOverallStars)
            if players ~= 0 then
                if bestPlayerScore ~= 0 then
                    desc = desc .. string.format("\n"..trans("menu_record_best_players").." %d (%s)", players, bestPlayerScore, starStrPlayer)
                else
                    desc = desc .. string.format("\n"..trans("menu_record_best_players").." 0", players)
                end
            end
            desc = desc .. string.format("\n"..trans("menu_record_best_stars").." %d (%s, %dP)", bestStarsScore, starStrMostStars, bestStarsPlayers)
            desc = desc .. string.format("\n"..trans("menu_record_best_overall").." %d (%s, %dP)", bestOverallScore, starStrOverall, bestOverallPlayers)
        else
            for stars=1,maxStars do
                desc = desc .. string.rep("", stars) .. ": %d\n"
            end
            desc = desc .. "\nNo scores saved."
        end
                
        table.insert(menu, {
            levelName,
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
            noLang = true,
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

local recordsPlayers = 0
local reloadRecords = false
function build_records_menu(menu)
    local min = 0
    table.insert(menu, {
        "menu_players",
        function(x)
            if recordsPlayers ~= x then
                reloadRecords = true
                recordsPlayers = x
                enter_menu(6, 1, true)
                set_menu_option(6, 1, x)
                reloadRecords = false
            end
        end,
        runOnChange = true,
        currNum = 0,
        minNum = 0,
        nameRef = {"menu_overall"},
        maxNum = MAX_PLAYERS,
        desc = {"menu_desc_records_players_overall", "menu_desc_records_players_solo", "menu_desc_records_players"},
        updateNum = function(button)
            if reloadRecords then return end
            button.currNum = math.clamp(gGlobalSyncTable.peakPlayers, 0, MAX_PLAYERS)
            if recordsPlayers ~= button.currNum then
                reloadRecords = true
                recordsPlayers = button.currNum
                enter_menu(6, 1, true)
                set_menu_option(6, 1, button.currNum)
                reloadRecords = false
            end
        end,
    })
    for i=min,#OC_LEVEL_DATA do
        local levelName = get_level_translated_field(i, "name")
        local desc = get_level_translated_field(i, "desc") or trans("menu_no_desc")
        desc = desc .. "\n\n"
        local bestOverallScore, bestOverallStars, bestOverallPlayers = get_record_for_level(i)

        local bestStars = 0
        local maxStars = 3
        if bestOverallScore ~= 0 then
            -- score for this many players
            local players = recordsPlayers
            local bestPlayerScore, bestPlayerStars = get_record_for_level(i, players)
            if players == 0 or bestPlayerScore ~= 0 then
                -- score for the most stars obtained
                local bestStarsScore, bestStarsPlayers = 0, 0
                bestStarsScore, bestStars, bestStarsPlayers = get_record_for_level(i, 0, true)

                maxStars = math.clamp(bestStars+1, 3, 4)
                for stars=1,maxStars do
                    desc = desc .. string.rep("", stars) .. ": %d\n"
                end

                local starStrPlayer = (bestPlayerStars == 0 and "0") or string.rep("", bestPlayerStars)
                local starStrMostStars = (bestStars == 0 and "0") or string.rep("", bestStars)
                local starStrOverall = (bestOverallStars == 0 and "0") or string.rep("", bestOverallStars)
                if players ~= 0 then
                    desc = desc .. string.format("\n"..trans("menu_record_best_players").." %d (%s)", players, bestPlayerScore, starStrPlayer)
                end
                desc = desc .. string.format("\n"..trans("menu_record_best_stars").." %d (%s, %dP)", bestStarsScore, starStrMostStars, bestStarsPlayers)
                desc = desc .. string.format("\n"..trans("menu_record_best_overall").." %d (%s, %dP)", bestOverallScore, starStrOverall, bestOverallPlayers)

                table.insert(menu, {
                    levelName,
                    function() end,
                    desc = desc,
                    false,
                    descExtra = function()
                        local maxKitchens = math.clamp(math.ceil(players / 4), 1, MAX_KITCHENS)
                        local neededPoints = get_star_scores(i, maxKitchens, players)
                        local result = {}
                        for stars=1,maxStars do
                            table.insert(result, neededPoints[stars])
                        end
                        return table.unpack(result)
                    end,
                    noLang = true,
                })
            end
        end
    end
end

function build_language_menu(menu)
    for i, thisLang in ipairs(lang_order_table) do
        table.insert(menu, {
            langdata[thisLang].name_menu,
            function()
                switch_lang(thisLang)
            end,
            noLang = true,
        })
    end
end

grabButtonIndex = 3
actionButtonIndex = 0
throwButtonIndex = 0
orderHUDLocation = 0
reverseReading = false
showButtonPrompts = true
showCookIndicators = false
disableWaterEffect = false
oldPlatePlace = false
hideOCHud = false

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
            "menu_continue",
            function(x)
                play_sound(SOUND_MENU_PAUSE, gGlobalSoundSource)
                inMenu = false
            end,
            false,
            desc = "menu_desc_continue",
        },
        {
            "menu_retry",
            function(x)
                confirmText = "menu_desc_confirm_restart"
                confirmFunc = function(x)
                    inMenu = false
                    gGlobalSyncTable.gameState = GAME_STATE_PREPARE
                    gGlobalSyncTable.timeLeft = 10
                end
                enter_menu(2)
            end,
            true,
            function()
                return not is_game_state_level_running()
            end,
            desc = "menu_desc_restart",
        },
        {
            "menu_quit",
            function(x)
                confirmText = "menu_desc_confirm_quit"
                confirmFunc = function(x)
                    inMenu = false
                    gGlobalSyncTable.gameState = GAME_STATE_LEVEL_SELECT
                end
                enter_menu(2)
            end,
            true,
            function()
                return not is_game_state_level_running()
            end,
            desc = "menu_desc_quit",
        },
        {
            "menu_level_select",
            function(x)
                enter_menu(3)
            end,
            true,
            function()
                return gGlobalSyncTable.gameState ~= GAME_STATE_LEVEL_SELECT
            end,
            desc = "menu_desc_level_select",
        },
        {
            "menu_host_options",
            function(x)
                enter_menu(8)
            end,
            true,
            desc = "menu_desc_host_options",
        },
        {
            "menu_spectate",
            function(x)
                stayInSpectate = (x == 1)
                if stayInSpectate then
                    gPlayerSyncTable[0].spectator = true
                end
            end,
            runOnChange = true,
            currNum = (stayInSpectate and 1) or 0,
            maxNum = 1,
            nameRef = { "menu_off", "menu_on" },
            desc = {"menu_desc_spectate_off", "menu_desc_spectate_on"},
            updateNum = function(button)
                button.currNum = (stayInSpectate and 1) or 0
            end,
        },
        {
            "menu_practice",
            function()
                confirmText = "menu_desc_confirm_practice"
                confirmFunc = function()
                    inMenu = false
                    gPlayerSyncTable[0].inPractice = true
                    gPlayerSyncTable[0].spectator = true
                end
                enter_menu(2)
            end,
            false,
            function()
                return gPlayerSyncTable[0].inPractice
            end,
            desc = "menu_desc_join_practice",
        },
        {
            "menu_quit_practice",
            function()
                inMenu = false
                gPlayerSyncTable[0].inPractice = false
            end,
            false,
            function()
                return not gPlayerSyncTable[0].inPractice
            end,
            desc = "menu_desc_quit_practice",
        },
        {
            "menu_preferences",
            function(x)
                enter_menu(4)
            end,
            false,
            desc = "menu_desc_preferences",
        },
        {
            "menu_char_select",
            function(x)
                inMenu = false
                charSelect.set_menu_open(true)
            end,
            false,
            function() return not charSelect end,
            desc = "menu_desc_char_select",
        },
        {
            "menu_records",
            function(x)
                enter_menu(6)
            end,
            false,
            desc = "menu_desc_records",
        },
        {
            "menu_djui_menu",
            function(x)
                waitOpenDJUI = true
            end,
            false,
            desc = "menu_desc_djui_menu",
        },
    },
    [2] = {
        {
            "menu_yes",
            function(x)
                if confirmFunc == nil then return end
                return confirmFunc(x)
            end,
            false,
            desc = "%s",
            noLangDesc = true,
            descExtra = function()
                return trans(confirmText)
            end,
        },
        {
            "menu_no",
            function(x)
                if #menu_history ~= 0 then
                    enter_menu(menu_history[#menu_history][1], menu_history[#menu_history][2], true)
                    table.remove(menu_history, #menu_history)
                else
                    enter_menu(1, 1, true)
                end
            end,
            false,
            desc = "%s",
            noLangDesc = true,
            descExtra = function()
                return trans(confirmText)
            end,
        },
        title = "menu_title_confirm",
    },
    [3] = {
        buildFunc = build_level_menu,
        title = "menu_level_select",
    },
    [4] = {
        {
            "menu_grab_button",
            function(x)
                grabButtonIndex = x
            end,
            runOnChange = true,
            currNum = grabButtonIndex,
            maxNum = 3,
            nameRef = { "X", "Y", "L", "B" },
            noLangOption = true,
            save = "grabButtonIndex",
            localSave = true,
            desc = "menu_desc_grab_button",
        },
        {
            "menu_action_button",
            function(x)
                actionButtonIndex = x
            end,
            runOnChange = true,
            currNum = actionButtonIndex,
            maxNum = 3,
            nameRef = { "X", "Y", "L", "B" },
            noLangOption = true,
            save = "actionButtonIndex",
            localSave = true,
            desc = "menu_desc_action_button",
        },
        {
            "menu_throw_button",
            function(x)
                throwButtonIndex = x
            end,
            runOnChange = true,
            currNum = throwButtonIndex,
            maxNum = 3,
            nameRef = { "X", "Y", "L", "B" },
            noLangOption = true,
            save = "throwButtonIndex",
            localSave = true,
            desc = "menu_desc_throw_button",
        },
        {
            "menu_old_plate_place",
            function(x)
                oldPlatePlace = (x ~= 0)
            end,
            runOnChange = true,
            currNum = (oldPlatePlace and 1) or 0,
            maxNum = 1,
            nameRef = { "menu_off", "menu_on"},
            save = "oldPlatePlace",
            localSave = true,
            desc = {"menu_desc_old_plate_place_off", "menu_desc_old_plate_place_on"},
        },
        {
            "menu_reduced_motion",
            function(x)
                menuMotionEnabled = (x ~= 0)
            end,
            runOnChange = true,
            currNum = (menuMotionEnabled and 1) or 0,
            maxNum = 1,
            nameRef = { "menu_on", "menu_off"},
            save = "menuMotionEnabled",
            localSave = true,
            desc = "menu_desc_reduced_motion",
        },
        {
            "menu_order_hud_location",
            function(x)
                orderHUDLocation = x
            end,
            runOnChange = true,
            currNum = orderHUDLocation,
            maxNum = 3,
            nameRef = { "menu_left", "menu_right", "menu_left_offset", "menu_right_offset" },
            save = "orderHUDLocation",
            localSave = true,
            desc = {"menu_desc_order_left", "menu_desc_order_right", "menu_desc_order_left_offset", "menu_desc_order_right_offset"},
        },
        {
            "menu_order_priority",
            function(x)
                reverseReading = (x == 1)
            end,
            runOnChange = true,
            currNum = (reverseReading and 1) or 0,
            maxNum = 1,
            nameRef = { "menu_left_to_right", "menu_right_to_left" },
            save = "reverseReading",
            localSave = true,
            desc = {"menu_desc_left_to_right", "menu_desc_right_to_left"},
        },
        {
            "menu_button_prompts",
            function(x)
                showButtonPrompts = (x == 1)
            end,
            runOnChange = true,
            currNum = (showButtonPrompts and 1) or 0,
            maxNum = 1,
            nameRef = { "menu_off", "menu_on" },
            save = "showButtonPrompts",
            localSave = true,
            desc = "menu_desc_button_prompts",
        },
        {
            "menu_cook_indicators",
            function(x)
                showCookIndicators = (x == 1)
            end,
            runOnChange = true,
            currNum = (showCookIndicators and 1) or 0,
            maxNum = 1,
            nameRef = { "menu_off", "menu_on" },
            save = "showCookIndicators",
            localSave = true,
            desc = "menu_desc_cook_indicators",
        },
        {
            "menu_disable_water_effect",
            function(x)
                disableWaterEffect = (x == 1)
            end,
            runOnChange = true,
            currNum = (disableWaterEffect and 1) or 0,
            maxNum = 1,
            nameRef = { "menu_off", "menu_on" },
            save = "disableWaterEffect",
            localSave = true,
            desc = "menu_desc_disable_water_effect",
        },
        {
            "menu_hide_hud",
            function(x)
                hideOcHud = (x == 1)
            end,
            runOnChange = true,
            currNum = (hideOcHud and 1) or 0,
            maxNum = 1,
            nameRef = { "menu_off", "menu_on" },
            desc = "menu_desc_hide_hud",
        },
        {
            "menu_language",
            function(x)
                enter_menu(7)
            end,
            false,
            function()
                return (#lang_order_table <= 1)
            end,
            desc = "menu_desc_language",
        },
        title = "menu_preferences",
    },
    [5] = {
        {
            "menu_join_practice",
            function()
                inMenu = false
                stayInSpectate = false
                gPlayerSyncTable[0].inPractice = true
            end,
            desc = "menu_desc_join_practice",
        },
        {
            "menu_join_now",
            function()
                inMenu = false
                stayInSpectate = false
                if not is_game_state_level_running() then
                    return
                end
                local sMario = gPlayerSyncTable[0]
                local kitchen, spawnID = join_smallest_kitchen(0)
                sMario.kitchen = kitchen
                if spawnID == -1 then
                    sMario.spectator = true
                    sMario.spawnID = 0
                    djui_chat_message_create(trans("too_many_cooks"))
                else
                    sMario.spawnID = spawnID
                    sMario.spectator = false
                    sMario.canRejoin = true
                end
            end,
            false,
            function()
                return is_game_state_level_running() and not (gGlobalSyncTable.allowMidGameJoin or gPlayerSyncTable[0].canRejoin)
            end,
            desc = "menu_desc_join_now",
        },
        {
            "menu_join_wait",
            function()
                inMenu = false
                stayInSpectate = false
            end,
            false,
            function()
                return (not is_game_state_level_running()) or (gGlobalSyncTable.allowMidGameJoin or gPlayerSyncTable[0].canRejoin)
            end,
            desc = "menu_desc_join_now",
        },
        {
            "menu_join_spectate",
            function()
                inMenu = false
                stayInSpectate = true
            end,
            desc = "menu_desc_join_spectate",
        },
        title = "menu_title_join",
        noBack = true,
    },
    [6] = {buildFunc = build_records_menu, title = "menu_records"},
    [7] = {buildFunc = build_language_menu, title = "menu_language"},
    [8] = {
        {
            "menu_auto_start",
            function(x)
                gGlobalSyncTable.autoStart = (x ~= 0)
            end,
            true,
            function()
                return gGlobalSyncTable.gameState ~= GAME_STATE_LEVEL_SELECT
            end,
            runOnChange = true,
            currNum = (gGlobalSyncTable.autoStart and 1) or 0,
            maxNum = 1,
            nameRef = { "menu_off", "menu_on" },
            desc = {"menu_desc_auto_start_off", "menu_desc_auto_start_on"},
            updateNum = function(button)
                button.currNum = (gGlobalSyncTable.autoStart and 1) or 0
            end,
        },
        {
            "menu_allow_mid_game_join",
            function(x)
                gGlobalSyncTable.allowMidGameJoin = (x ~= 0)
            end,
            true,
            runOnChange = true,
            currNum = (gGlobalSyncTable.allowMidGameJoin and 1) or 0,
            maxNum = 1,
            nameRef = { "menu_off", "menu_on" },
            desc = {"menu_desc_mid_game_join_off", "menu_desc_mid_game_join_on"},
            updateNum = function(button)
                button.currNum = (gGlobalSyncTable.allowMidGameJoin and 1) or 0
            end,
        },
        title = "menu_host_options",
    }
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
    local title = menu.title or "menu_title_default"
    if menu.title == nil and (gGlobalSyncTable.gameState ~= GAME_STATE_LEVEL_SELECT) then
        title = get_level_translated_field(gGlobalSyncTable.ocLevel, "name") or "???"
        y = y + 40 * scale
    elseif menu.title == nil or not menu.noLang then
        title = trans(title)
    end

    -- version (bottom left)
    local version = "v" .. overcookedAPIVersion
    djui_hud_set_text_alignment(TEXT_HALIGN_LEFT, TEXT_VALIGN_BOTTOM)
    djui_hud_set_color_from_table(MENU_COLORS.desc)
    djui_hud_print_text(version, 10, screenHeight - 10, scale / 4, scale / 4)

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
            if not button.noLang then
                text = trans(text)
            end
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
                    if not (button.noLang or button.noLangDesc) then desc = trans(desc) end

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
                    if not button.noLangOption then
                        optionText = trans(optionText)
                    end
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
        x = screenWidth * 0.35 - (10 * (maxStars - 1) + 20) * starScale -- center align after writing player count
        y = 32 + 32 * scale
        djui_hud_print_text(trans("short_player_count", gGlobalSyncTable.peakPlayers), x, y + 5 * starScale, starScale / 2)
        x = x + 20 * starScale
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
    elseif (sMenuInputsPressed & Z_TRIG) ~= 0 and charSelect and not menu.noBack then
        play_sound(SOUND_MENU_CLICK_FILE_SELECT, gGlobalSoundSource)
        inMenu = false
        charSelect.set_menu_open(true)
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

function get_current_menu()
    return menuID
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