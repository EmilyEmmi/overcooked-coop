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

function get_order_fail_time()
    -- Uses the lower amount of players expected per kitchen
    local data = OC_LEVEL_DATA[gGlobalSyncTable.ocLevel]
    local maxKitchens = gGlobalSyncTable.maxKitchens
    local lowPlayers = math.clamp(gGlobalSyncTable.peakPlayers // maxKitchens, 1, 4)
    return data.failTime[lowPlayers] or 240
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
            kitchenCount[i] = kitchenCount[i] + 1
            kitchenFreeSpawnIDs[i][sMario.spawnID] = nil
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
    return string.format("%d:%02d", time // 60, time % 60)
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