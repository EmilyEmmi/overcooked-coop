--- @param n GraphNode | FnGraphNode
function chopping_board_switch(n)
    local switch = cast_graph_node(n)
    local o = geo_get_current_object()

    local parent = o.parentObj
    if parent.usingObj and parent.usingObj ~= o then
        switch.selectedCase = 1
    else
        switch.selectedCase = 0
    end
end

--- @param n GraphNode | FnGraphNode
function box_label_switch(n)
    local switch = cast_graph_node(n)
    local o = geo_get_current_object()

    local item = o.oBehParams & 0xFF
    switch.selectedCase = BOX_LABEL_CASES[item] or 0
end

--- @param n GraphNode | FnGraphNode
function burger_switch(n)
    local switch = cast_graph_node(n)
    local o = geo_get_current_object()
    
    switch.selectedCase = 0
    if o.oContents == 0 or o.oContentCount == 0 then
        return
    end

    -- Change o.oContents to a different table format
    local contentExists = {}
    for i=0,o.oContentCount-1 do
        local ingredient = (o.oContents >> (8 * i)) & 0xFF
        contentExists[ingredient] = 1
    end

    -- OR each item (cheese, lettuce, tomato)
    if contentExists[ITEM_CHEESE_CUT] then
        switch.selectedCase = switch.selectedCase | 1
    end
    if contentExists[ITEM_LETTUCE_CUT] then
        switch.selectedCase = switch.selectedCase | 2
    end
    if contentExists[ITEM_TOMATO_CUT] then
        switch.selectedCase = switch.selectedCase | 4
    end

    -- Meatless are after the main states (9+)
    if not contentExists[ITEM_MEAT_COOKED] then
        if switch.selectedCase ~= 0 then -- 0 is no contents, 8 is full (so prevent picking 8 here)
            switch.selectedCase = switch.selectedCase | 8
        end
    else
        -- Add 1 to get the correct state (1 is plain, 2 is plain w/ cheese, etc.)
        switch.selectedCase = switch.selectedCase + 1
    end
end

--- @param n GraphNode | FnGraphNode
function pot_liquid_switch(n)
    local switch = cast_graph_node(n)
    local o = geo_get_current_object()

    if o.oContents == ITEM_BURNT then
        switch.selectedCase = 3
        return
    elseif o.oContentCount == 0 then
        switch.selectedCase = 1
        return
    end

    -- Set color based on ingredients (black if mixed)
    local firstIngredient = -1
    for i=0,o.oContentCount-1 do
        local ingredient = (o.oContents >> (8 * i)) & 0xFF
        if firstIngredient == -1 then
            firstIngredient = ingredient
        elseif firstIngredient ~= ingredient then
            firstIngredient = ITEM_BURNT
            break
        end
    end

    switch.selectedCase = 1 -- white by default (mushroom)
    if firstIngredient == ITEM_TOMATO_CUT then
        switch.selectedCase = 2
    elseif firstIngredient == ITEM_ONION_CUT then
        switch.selectedCase = 0
    elseif firstIngredient == ITEM_BURNT then
        switch.selectedCase = 3
    end
end

function alt_item_switch(n, altItem)
    local switch = cast_graph_node(n)
    local o = geo_get_current_object()
    switch.selectedCase = (o.oBehParams == altItem and 1) or 0
end

--- @param n GraphNode | FnGraphNode
function plate_switch(n)
    alt_item_switch(n, ITEM_DIRTY_PLATE)
end

--- @param n GraphNode | FnGraphNode
function mushroom_switch(n)
    handle_cut_switch(n, ITEM_MUSHROOM_CUT)
end

--- @param n GraphNode | FnGraphNode
function onion_switch(n)
    handle_cut_switch(n, ITEM_ONION_CUT)
end

--- @param n GraphNode | FnGraphNode
function tomato_switch(n)
    handle_cut_switch(n, ITEM_TOMATO_CUT)
end

--- @param n GraphNode | FnGraphNode
--- @param cutItem integer
function handle_cut_switch(n, cutItem)
    local switch = cast_graph_node(n)
    local o = geo_get_current_object()

    if o.oBehParams == cutItem or o.oCutOrCookTimer ~= 0 then
        switch.selectedCase = 0
    else
        switch.selectedCase = 1
    end
end

--- @param n GraphNode | FnGraphNode
function plate_tomato_switch(n)
    local switch = cast_graph_node(n)
    local o = geo_get_current_object()

    switch.selectedCase = 1
    if o.parentObj == nil or o.parentObj == o then return end
    local children = find_all_object_children(o.parentObj, id_bhvIngredient)
    for i,c in ipairs(children) do
        if c.oBehParams == ITEM_LETTUCE_CUT then
            switch.selectedCase = 0
            break
        end
    end
end

--- @param n GraphNode | FnGraphNode
function plate_soup_switch(n)
    local switch = cast_graph_node(n)
    local o = geo_get_current_object()

    switch.selectedCase = 0
    local children = find_all_object_children(o, id_bhvIngredient)
    for i,c in ipairs(children) do
        if c.oBehParams == ITEM_SOUP then
            local item = c.oContents & 0xFF -- use first ingredient for color
            if item == ITEM_ONION_CUT then
                switch.selectedCase = 1
            elseif item == ITEM_MUSHROOM_CUT then
                switch.selectedCase = 2
            elseif item == ITEM_TOMATO_CUT then
                switch.selectedCase = 3
            else
                switch.selectedCase = 4 -- unused
            end
            break
        end
    end
end

--- @param n GraphNode | FnGraphNode
function patty_switch(n)
    local switch = cast_graph_node(n)
    local o = geo_get_current_object()
    if o.oBehParams == ITEM_BURNT then
        switch.selectedCase = 2
        return
    end
    switch.selectedCase = (o.oBehParams == ITEM_MEAT_COOKED and 1) or 0
end

--- @param n GraphNode | FnGraphNode
function cheese_switch(n)
    alt_item_switch(n, ITEM_CHEESE_CUT)
end

--- @param n GraphNode | FnGraphNode
function chicken_switch(n)
    alt_item_switch(n, ITEM_CHICKEN_CUT)
end

--- @param n GraphNode | FnGraphNode
function sausage_switch(n)
    alt_item_switch(n, ITEM_SAUSAGE_CUT)
end

--- @param n GraphNode | FnGraphNode
function pizza_dough_switch(n)
    local switch = cast_graph_node(n)
    local o = geo_get_current_object()
    if o.oContents == ITEM_BURNT then
        switch.selectedCase = 2
        return
    end
    switch.selectedCase = (o.oBehParams == ITEM_DOUGH_COOKED and 1) or 0
end

--- @param n GraphNode | FnGraphNode
function handle_pizza_topping_switch(n, topping)
    local switch = cast_graph_node(n)
    local o = geo_get_current_object()
    switch.selectedCase = 0
    if o.oContents == ITEM_BURNT or o.oContents == 0 or o.oContentCount == 0 then
        return
    end

    -- Check for the item
    for i=0,o.oContentCount-1 do
        local ingredient = (o.oContents >> (8 * i)) & 0xFF
        if ingredient == topping then
            switch.selectedCase = 1
            break
        end
    end
end

--- @param n GraphNode | FnGraphNode
function handle_pizza_topping_switch(n, topping, cookedForm)
    local switch = cast_graph_node(n)
    local o = geo_get_current_object()
    switch.selectedCase = 0
    if o.oContents == ITEM_BURNT or o.oContents == 0 or o.oContentCount == 0 then
        return
    end

    -- Check for the item
    for i=0,o.oContentCount-1 do
        local ingredient = (o.oContents >> (8 * i)) & 0xFF
        if ingredient == topping then
            switch.selectedCase = (cookedForm and o.oBehParams == ITEM_DOUGH_COOKED and 2) or 1
            break
        end
    end
end

--- @param n GraphNode | FnGraphNode
function pizza_tomato_sauce_switch(n)
    handle_pizza_topping_switch(n, ITEM_TOMATO_CUT, true)
end

--- @param n GraphNode | FnGraphNode
function pizza_cheese_switch(n)
    handle_pizza_topping_switch(n, ITEM_CHEESE_CUT, true)
end

--- @param n GraphNode | FnGraphNode
function pizza_sausage_switch(n)
    handle_pizza_topping_switch(n, ITEM_SAUSAGE_CUT)
end

--- @param n GraphNode | FnGraphNode
function pizza_chicken_switch(n)
    handle_pizza_topping_switch(n, ITEM_CHICKEN_CUT, true)
end

--- @param n GraphNode | FnGraphNode
function pizza_mushroom_switch(n)
    handle_pizza_topping_switch(n, ITEM_MUSHROOM_CUT)
end

-- UV scrolling using djoslin's UV scroll library
local UvScroll = require("/lib/uv-scroll")

-- Scroll the uvs up
local function uv_scroll_up(input_vtx, original_uv, current_uv)
    -- adjustable constants
    local speed = 25

    -- move the UVs up
    current_uv[2] = current_uv[2] + speed
end

-- Scroll the uvs with a simple ripple effect
local function uv_scroll_ripple(input_vtx, original_uv, current_uv)
    if disableWaterEffect then
        current_uv[1] = original_uv[1]
        current_uv[1] = original_uv[1]
        return
    end

    -- adjustable constants
    local strength = 128
    local speed = 0.05
    local scale = 0.01

    -- equation for ripple effect
    local t = get_global_timer() * speed
    local offset = {
        math.sin(t + input_vtx.x * scale) * strength,
        math.cos(t + input_vtx.y * scale) * strength
    }

    current_uv[1] = original_uv[1] + offset[1]
    current_uv[2] = original_uv[2] + offset[2]
end

UvScroll.hook_scrolling_function("service_counter_service_counter_model_mesh_layer_1_tri_1", uv_scroll_up)
UvScroll.hook_scrolling_function("jrb_dl_Moving_Water_mesh_layer_5_tri_0", uv_scroll_ripple)