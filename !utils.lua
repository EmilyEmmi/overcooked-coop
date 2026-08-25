function obj_get_nearest_behavior_id_with_condition(o, id, condFunction)
    local nearest = nil
    local maxDist = 100000
    local o2 = obj_get_first_with_behavior_id(id)
    while o2 do
        local dist = dist_between_objects(o, o2)
        if dist < maxDist and condFunction(o2) then
            nearest = o2
            maxDist = dist
        end
        o2 = obj_get_next_with_same_behavior_id(o2)
    end
    return nearest, maxDist
end

function nearest_behavior_id_from_pos_with_condition(pos, id, condFunction)
    local nearest = nil
    local maxDist = 100000
    local o = obj_get_first_with_behavior_id(id)
    while o do
        local dist = dist_between_object_and_point(o, pos.x, pos.y, pos.z)
        if dist < maxDist and condFunction(o) then
            nearest = o
            maxDist = dist
        end
        o = obj_get_next_with_same_behavior_id(o)
    end
    return nearest, maxDist
end

---@param o Object
---@param soundBits integer
---@param freqScale number
function obj_play_sound_with_freq_scale(o, soundBits, freqScale)
    if not o then return end
    if o.header.gfx.node.flags & GRAPH_RENDER_ACTIVE ~= 0 then
        play_sound_with_freq_scale(soundBits, o.header.gfx.cameraToObject, freqScale)
    end
end

function find_all_object_children(o, id)
    local children = {}
    local c = obj_get_first_with_behavior_id(id)
    while c do
        if c ~= o and c.parentObj == o then
            table.insert(children, c)
        end
        c = obj_get_next_with_same_behavior_id(c)
    end
    return children
end

function find_all_object_using(o, id)
    local using = {}
    local other = obj_get_first_with_behavior_id(id)
    while other do
        if other ~= o and other.usingObj == o then
            table.insert(using, other)
        end
        other = obj_get_next_with_same_behavior_id(other)
    end
    return using
end

function spawn_child_object(parent, id, model, offsetX, offsetY, offsetZ, initFunc, sync)
    local spawnFunc = spawn_non_sync_object
    if sync then
        spawnFunc = spawn_sync_object
    end
    
    return spawnFunc(id, model, 0, 0, 0, function(o)
        o.parentObj = parent
        obj_copy_pos_and_angle(o, parent)
        obj_set_parent_relative_pos(o, offsetX, offsetY, offsetZ)
        o.oPosX = o.oPosX + offsetX
        o.oPosY = o.oPosY + offsetY
        o.oPosZ = o.oPosZ + offsetZ

        if initFunc then initFunc(o) end
    end)
end

---@param o Object
function obj_position_relative_to_parent(o)
    if not o then return end
    local parent = o.parentObj;
    if not parent then return end

    local relTranslation = {x = o.oParentRelativePosX, y = o.oParentRelativePosY, z = o.oParentRelativePosZ}
    local relRotation = {x = o.oParentRelativeAnglePitch, y = o.oParentRelativeAngleYaw, z = o.oParentRelativeAngleRoll}
    local mtx = gMat4Zero()
    mtxf_rotate_zxy_and_translate(mtx, relTranslation, relRotation);
    local mtx2 = gMat4Zero()
    local toRotate = {x = o.parentObj.oFaceAnglePitch, y = o.parentObj.oFaceAngleYaw, z = o.parentObj.oFaceAngleRoll}
    mtxf_rotate_zxy_and_translate(mtx2, {x = 0, y = 0, z = 0}, toRotate);
    mtxf_mul(mtx, mtx, mtx2)

    local prevPosX, prevPosY, prevPosZ = o.oPosX, o.oPosY, o.oPosZ
    local prevPitch, prevYaw, prevRoll = o.oFaceAnglePitch, o.oFaceAngleYaw, o.oFaceAngleRoll
    o.oPosX = o.parentObj.oPosX + mtx.m30
    o.oPosY = o.parentObj.oPosY + mtx.m31
    o.oPosZ = o.parentObj.oPosZ + mtx.m32
    o.oFaceAnglePitch = radians_to_sm64(math.asin(-mtx.m21))
    o.oFaceAngleYaw = radians_to_sm64(math.atan(mtx.m20, mtx.m22))
    o.oFaceAngleRoll = radians_to_sm64(math.atan(mtx.m01, mtx.m11))

    o.oVelX, o.oVelY, o.oVelZ = o.oPosX - prevPosX, o.oPosY - prevPosY, o.oPosZ - prevPosZ
    o.oAngleVelPitch = o.oFaceAnglePitch - prevPitch
    o.oAngleVelYaw = o.oFaceAngleYaw - prevYaw
    o.oAngleVelRoll = o.oFaceAngleRoll - prevRoll
end

---@param o Object
---@param otherObject Object?
function obj_resolve_object_collisions_custom(o, otherObject)
    if not o then return 0 end
    local dx;
    local dz;
    local angle;
    local radius;
    local otherRadius;
    local relativeRadius;
    local newCenterX;
    local newCenterZ;

    if (otherObject == nil and o.numCollidedObjs ~= 0) then
        otherObject = o.collidedObjs[1]
    end

    if otherObject and (otherObject.oInteractType & INTERACT_PLAYER == 0) then
        --! If one object moves after collisions are detected and this code
        --  runs, the objects can move toward each other (transport cloning)
        dx = otherObject.oPosX - o.oPosX;
        dz = otherObject.oPosZ - o.oPosZ;
        angle = atan2s(dx, dz); -- This should be atan2s(dz, dx) (not fixed b/c it is still broken)

        radius = o.hitboxRadius;
        otherRadius = otherObject.hitboxRadius;
        relativeRadius = radius / (radius + otherRadius);

        newCenterX = o.oPosX + dx * relativeRadius;
        newCenterZ = o.oPosZ + dz * relativeRadius;

        o.oPosX = newCenterX - radius * coss(angle);
        o.oPosZ = newCenterZ - radius * sins(angle);

        otherObject.oPosX = newCenterX + otherRadius * coss(angle);
        otherObject.oPosZ = newCenterZ + otherRadius * sins(angle);

        if (abs_angle_diff(o.oMoveAngleYaw, angle) < 0x4000) then
            -- Bounce off object
            local targetYaw = limit_angle(angle - o.oMoveAngleYaw + angle + 0x8000);
            return 1, targetYaw;
        end
    end

    return 0, 0;
end

---@param o Object
---@param name string
---@return boolean
function smlua_anim_util_set_animation_if_new(o, name)
    if smlua_anim_util_get_current_animation_name(o) ~= name then
        smlua_anim_util_set_animation(o, name)
        o.header.gfx.animInfo.animFrame = 0
        o.header.gfx.animInfo.animAccel = 0
        return true
    end
    return false
end

function get_order_fail_time()
    -- Uses the lower amount of players expected per kitchen
    local data = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel]
    local maxKitchens = gGlobalSyncTable.maxKitchens
    local lowPlayers = math.clamp(gGlobalSyncTable.peakPlayers // maxKitchens, 1, 4)
    return data.failTime[lowPlayers] or 240
end

-- from extended moveset
function limit_angle(a)
  return (a + 0x8000) % 0x10000 - 0x8000
end

function clear_pending_orders_table()
    pending_orders_all = {}
    for i=1,MAX_KITCHENS do
        table.insert(pending_orders_all, {})
    end
    pending_orders = pending_orders_all[gPlayerSyncTable[0].kitchen] or {}
end

-- Returns the kitchen with the least amount of players
-- Also returns the spawn ID (-1 if all kitchens are full)
function join_smallest_kitchen(index)
    local kitchenCount = {}
    local kitchenFreeSpawnIDs = {}
    for i=1,gGlobalSyncTable.maxKitchens do
        kitchenCount[i] = 0
        kitchenFreeSpawnIDs[i] = {}
        for a=0,3 do
            kitchenFreeSpawnIDs[i][a] = 1
        end
    end

    for i=0,MAX_PLAYERS-1 do
        local np, sMario = gNetworkPlayers[i], gPlayerSyncTable[i]
        local kitchen = sMario.kitchen or 0
        if i ~= index and np.connected and (not sMario.spectator)
        and kitchen >= 1 and kitchen <= gGlobalSyncTable.maxKitchens then
            kitchenCount[kitchen] = kitchenCount[kitchen] + 1
            kitchenFreeSpawnIDs[kitchen][sMario.spawnID] = nil
        end
    end

    local smallestKitchens = {}
    local smallestCount = 99
    for kitchen, count in ipairs(kitchenCount) do
        if count < smallestCount then
            smallestCount = count
            smallestKitchens = {kitchen}
        elseif count == smallestCount then
            table.insert(smallestKitchens, kitchen)
        end
    end

    if #smallestKitchens == 0 then return 1, -1 end -- failsafe

    local kitchen = table.remove(smallestKitchens)
    if smallestCount >= 4 then return kitchen, -1 end
    for spawnID=0,3 do
        if kitchenFreeSpawnIDs[kitchen][spawnID] then
            return kitchen, spawnID
        end
    end
    return kitchen, -1
end

function get_active_player_count()
    local totalPlayers = 0
    for i=0,MAX_PLAYERS-1 do
        local np, sMario = gNetworkPlayers[i], gPlayerSyncTable[i]
        if np.connected and not sMario.spectator then
            totalPlayers = totalPlayers + 1
        end
    end
    return totalPlayers
end

function is_active_player_in_area(maxToCheck)
    local total = 0
    for i=0,MAX_PLAYERS-1 do
        local m, sMario = gMarioStates[i], gPlayerSyncTable[i]
        if is_player_active(m) ~= 0 and not sMario.spectator then
            total = total + 1
            if maxToCheck == nil or total >= maxToCheck then
                return true
            end
        end
    end
    return false
end

-- Calculates level star requirements are based on how many players and kitchens are present.
function get_star_scores(oc_level, maxKitchens, maxPlayers)
    local lData = OC_LEVEL_DATA[oc_level]
    local neededPoints = {9999, 9999, 9999, 9999}
    if lData and lData.starScores then
        maxKitchens = maxKitchens or gGlobalSyncTable.maxKitchens
        maxPlayers = maxPlayers or gGlobalSyncTable.peakPlayers

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
    return neededPoints
end

function save_new_score()
    local oc_level = gGlobalSyncTable.ocLevel
    local lData = OC_LEVEL_DATA[oc_level]
    if not lData then return false end
    local levelSaveName = lData.saveName or tostring(oc_level)
    
    local neededPoints = get_star_scores(oc_level)
    local stars = 4
    while stars > 0 do
        if gGlobalSyncTable.score >= neededPoints[stars] then break end
        stars = stars - 1
    end

    -- per-player score
    local savePrefix = string.format("record_%s_%d_", levelSaveName, gGlobalSyncTable.peakPlayers)
    local maxScorePlayers = mod_storage_load_integer(savePrefix.."score")
    if maxScorePlayers < gGlobalSyncTable.score then
        maxScorePlayers = gGlobalSyncTable.score
        mod_storage_save_integer(savePrefix.."score", maxScorePlayers)
        mod_storage_save_integer(savePrefix.."stars", stars)
    end

    -- global score
    savePrefix = string.format("record_%s_players", levelSaveName)
    local bestOverallPlayers = mod_storage_load_integer(savePrefix)
    local maxScore = mod_storage_load_integer(string.format("record_%s_%d_score", levelSaveName, bestOverallPlayers))
    local saveMax = false
    if maxScore < maxScorePlayers then
        saveMax = true
        mod_storage_save_integer(savePrefix, gGlobalSyncTable.peakPlayers)
    end

    -- most stars score
    savePrefix = string.format("record_%s_max_stars_players", levelSaveName)
    local bestStarsPlayers = mod_storage_load_integer(savePrefix)
    local maxStars = mod_storage_load_integer(string.format("record_%s_%d_stars", levelSaveName, bestStarsPlayers))
    if maxStars < stars then
        mod_storage_save_integer(savePrefix, gGlobalSyncTable.peakPlayers)
    end
    return saveMax
end

function get_star_record(oc_level)
    local score, stars = get_record_for_level(oc_level, 0, true)
    return stars
end

function get_record_for_level(oc_level, players, checkMaxStars)
    local lData = OC_LEVEL_DATA[oc_level]
    if not lData then return 0, 0, 0 end
    local levelSaveName = lData.saveName or tostring(oc_level)

    if players == nil or players == 0 then
        local savePrefix = ""
        if checkMaxStars then
            savePrefix = string.format("record_%s_max_stars_players", levelSaveName)
        else
            savePrefix = string.format("record_%s_players", levelSaveName)
        end
        players = mod_storage_load_integer(savePrefix)
        if players == 0 then
            if checkMaxStars then
                return get_record_for_level(oc_level, players) -- try without stars
            else
                return 0, 0, 0
            end
        end
    end

    local savePrefix = string.format("record_%s_%d_", levelSaveName, players)
    local score = mod_storage_load_integer(savePrefix.."score")
    local stars = mod_storage_load_integer(savePrefix.."stars")
    return score, stars, players
end

---@param level integer
---@param field string
---@return string? text
function get_level_translated_field(level, field)
    local lData = OC_LEVEL_DATA[level]
    if not lData then return end

    ---@type string
    local text = lData[field]
    if text and lang ~= "en" then
        if lData.customLevel then
            text = lData[field.."_"..lang] or text
        else
            text = trans("level_"..field.."_"..level)
        end
    end
    return text
end

function attempt_desync_fix(from)
    if not network_is_server() then
        clear_pending_orders_table()
        network_send_to(1, true, {id = PACKET_DESYNC_FIX, from = (from or network_global_index_from_local(0))})
        return
    end

    sync_value(gGlobalSyncTable, "ocLevel")
    sync_value(gGlobalSyncTable, "gameState")
    sync_value(gGlobalSyncTable, "score")
    sync_value(gGlobalSyncTable, "timeLeft")
    sync_value(gGlobalSyncTable, "maxKitchens")
    sync_value(gGlobalSyncTable, "peakPlayers")
    if from then
        on_packet_request_orders({from = from})
        local sMario = gPlayerSyncTable[network_local_index_from_global(from)]
        sync_value(sMario, "spectator")
        sync_value(sMario, "kitchen")
        sync_value(sMario, "spawnID")
        sync_value(sMario, "readyToStart")
    end
end

-- Returns if table1 and table2 contain the same amount of each element (ignoring order)
-- No this function isn't AI, I just felt like being descriptive today
function tables_contain_same_elements(table1, table2)
    if #table1 ~= #table2 then return false end -- Both tables need to have the same amount of elements

    -- Count amount of each element in table 1
    local amountOf1 = {}
    for i,element in ipairs(table1) do
        if amountOf1[element] == nil then
            amountOf1[element] = 0
        end
        amountOf1[element] = amountOf1[element] + 1
    end

    -- Count amount of each element in table 2, returning false if it's more than table 1
    local amountOf2 = {}
    for i,element in ipairs(table2) do
        if amountOf2[element] == nil then
            amountOf2[element] = 0
        end
        amountOf2[element] = amountOf2[element] + 1
        if amountOf1[element] == nil or amountOf2[element] > amountOf1[element] then
            --djui_chat_message_create(string.format("%d: %d, %d", element, amountOf1[element] or 0, amountOf2[element]))
            return false
        end
    end

    -- Otherwise, they must have the same contents (size check gets cases where this wouldn't apply)
    return true
end

function time_format(time)
    return trans("time_format", time // 60, time % 60)
end

-- roughly calculates the DJUI scale
function get_djui_scale()
    local prevResolution = djui_hud_get_resolution()

    djui_hud_set_resolution(RESOLUTION_N64)
    local n64_sw = djui_hud_get_screen_width()
    djui_hud_set_resolution(RESOLUTION_DJUI)
    local djui_sw = djui_hud_get_screen_width()

    djui_hud_set_resolution(prevResolution)
    return n64_sw / djui_sw / 0.289375
end

function djui_hud_render_texture_interpolated_x_only(tex, x, y, scaleX, scaleY, prevX, prevScaleX)
    return djui_hud_render_texture_interpolated(tex, prevX, y, prevScaleX, scaleY, x, y, scaleX, scaleY)
end

function lerp_color(color1, color2, t)
    local color = {r = 0, g = 0, b = 0}
    color.r = math.lerp(color1.r, color2.r, t)
    color.g = math.lerp(color1.g, color2.g, t)
    color.b = math.lerp(color1.b, color2.b, t)
    return color
end

-- Converts string into a table using a determiner (but stop splitting after a certain amount)
function split(s, delimiter, limit_)
  local limit = limit_ or 999
  local result = {}
  local finalmatch = ""
  local i = 0
  for match in (s):gmatch(string.format("[^%s]+", delimiter)) do
    --djui_chat_message_create(match)
    i = i + 1
    if i >= limit then
      finalmatch = finalmatch .. match .. delimiter
    else
      table.insert(result, match)
    end
  end
  if i >= limit then
    finalmatch = string.sub(finalmatch, 1, string.len(finalmatch) - string.len(delimiter))
    table.insert(result, finalmatch)
  end
  return result
end

function set_without_sync(syncTable, field, value)
    rawset(syncTable._table, field, value)
end

function sync_value(syncTable, field)
    _set_sync_table_field(syncTable, field, syncTable[field])
end