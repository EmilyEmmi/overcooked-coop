function on_packet_order(data, self)
    if not data.orderID then return end

    local pending_orders = pending_orders_all[data.kitchen or 1]
    local order = {}
    order.id = data.orderID
    order.time = data.time or (get_order_fail_time() * 30)
    order.prevTime = order.time
    order.maxTime = data.maxTime or order.time
    table.insert(pending_orders, order)
end

function on_packet_served_order(data, self)
    if not data.orderID then return end

    local fromLocalIndex = (self and 0) or network_local_index_from_global(data.from)
    local fromKitchen = gPlayerSyncTable[fromLocalIndex].kitchen or 1
    local pending_orders = pending_orders_all[fromKitchen]
    local existingOrders = 0
    local servedOrderIndex = 0
    local firstOrder = false
    local minTime = -1
    -- get order matching ID with the lowest time
    for a,pending_data in ipairs(pending_orders) do
        local orderID = pending_data.id
        if pending_data.vanishTimer == nil then
            existingOrders = existingOrders + 1
            if orderID == data.orderID and (minTime == -1 or pending_data.time < minTime) then
                servedOrderIndex = a
                minTime = pending_data.time
                firstOrder = (existingOrders == 1)
            end
        end
    end

    if servedOrderIndex ~= 0 then
        local pending_data = pending_orders[servedOrderIndex]
        local orderID = pending_data.id
        pending_data.vanishTimer = 15
        if not gPlayerSyncTable[0].inPractice then
            play_sound(SOUND_GENERAL_COIN, gGlobalSoundSource)
        end
        if network_is_server() then
            gGlobalSyncTable["servedOrders"..fromKitchen] = gGlobalSyncTable["servedOrders"..fromKitchen] + 1
        end
        if self then
            local order = ORDER_DATA[orderID]
            
            -- score = base score + 20 * ingredient count + tip * multiplier
            local score = (order.baseScore or 0)
            for i, item in ipairs(order.items) do
                if not (ITEM_DATA[item.type].skipItem) then
                    score = score + 20
                end
                if item.contents then
                    score = score + 20 * #item.contents
                end
            end

            -- Tip based on how fast we served the order
            local tip = 8
            local timeRatio = pending_data.time / pending_data.maxTime
            local tipMultiField = "tipMulti"..fromKitchen
            if timeRatio < 0.33 then
                tip = 3
            elseif timeRatio < 0.66 then
                tip = 5
            end
            score = score + tip * (gGlobalSyncTable[tipMultiField] or 1)
            -- tip multiplier increases if we serve in order
            if firstOrder then
                gGlobalSyncTable[tipMultiField] = math.min(gGlobalSyncTable[tipMultiField] + 1, 4)
            else
                gGlobalSyncTable[tipMultiField] = 1
            end

            --djui_chat_message_create("Earned "..score.." points")
            gGlobalSyncTable.score = gGlobalSyncTable.score + score
        end
    end
end

function on_packet_request_orders(data, self)
    if #pending_orders == 0 or not data.from then return end

    local toLocalIndex = network_local_index_from_global(data.from)
    if toLocalIndex == 0 then return end
    for kitchen, pending_orders in ipairs(pending_orders_all) do
        for i,pending_data in ipairs(pending_orders) do
            if pending_data.vanishTimer == nil then
                network_send_to(toLocalIndex, true, {
                    id = PACKET_ORDER,
                    orderID = pending_data.id,
                    time = pending_data.time,
                    maxTime = pending_data.maxTime,
                    kitchen = kitchen,
                })
            end
        end
    end
end

function on_packet_desync_fix(data, self)
    attempt_desync_fix(data.from)
end

PACKET_ORDER = 0
PACKET_SERVED_ORDER = 1
PACKET_REQUEST_ORDERS = 2
PACKET_DESYNC_FIX = 3
local sPacketTable = {
    [PACKET_ORDER] = on_packet_order,
    [PACKET_SERVED_ORDER] = on_packet_served_order,
    [PACKET_REQUEST_ORDERS] = on_packet_request_orders,
    [PACKET_DESYNC_FIX] = on_packet_desync_fix,
}
function on_packet_receive(data)
    if data.id and sPacketTable[data.id] then
        sPacketTable[data.id](data, false)
    end
end
hook_event(HOOK_ON_PACKET_RECEIVE, on_packet_receive)

function network_send_include_self(reliable, data)
    network_send(reliable, data)
    if data.id and sPacketTable[data.id] then
        sPacketTable[data.id](data, true)
    end
end