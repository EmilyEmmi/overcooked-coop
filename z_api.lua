_G.overcookedAPI = {}
_G.overcookedAPIVersion = 1.0

-- Adds a new level. Set saveName to keep save data tied to the level, even if you change the name.
---@param data table Table of information for the level; see !levels.lua for info.
---@return integer levelNum The ID of the new level. Returns 0 on failure.
overcookedAPI.overcooked_add_level = function(data)
    if not data.name then return 0 end

    if not data.saveName then
        data.saveName = data.name:lower()
        -- Remove punctuation and replace space characters (and dashes) with underscores
        data.saveName = data.saveName:gsub("[-_]", " ")
        data.saveName = data.saveName:gsub("%p", "")
        data.saveName = data.saveName:gsub("%s", "_")
    end
    data.customLevel = true
    table.insert(OC_LEVEL_DATA, data)
    return #OC_LEVEL_DATA
end

overcookedAPI.ORDER_PLAIN_SALAD = ORDER_PLAIN_SALAD
overcookedAPI.ORDER_MIXED_SALAD = ORDER_MIXED_SALAD
overcookedAPI.ORDER_PLAIN_BURGER = ORDER_PLAIN_BURGER
overcookedAPI.ORDER_CHEESE_BURGER = ORDER_CHEESE_BURGER
overcookedAPI.ORDER_LETTUCE_BURGER = ORDER_LETTUCE_BURGER
overcookedAPI.ORDER_CHEESE_LETTUCE_BURGER = ORDER_CHEESE_LETTUCE_BURGER
overcookedAPI.ORDER_LETTUCE_TOMATO_BURGER = ORDER_LETTUCE_TOMATO_BURGER
overcookedAPI.ORDER_DELUXE_BURGER = ORDER_DELUXE_BURGER
overcookedAPI.ORDER_TOMATO_SOUP = ORDER_TOMATO_SOUP
overcookedAPI.ORDER_ONION_SOUP = ORDER_ONION_SOUP
overcookedAPI.ORDER_MUSHROOM_SOUP = ORDER_MUSHROOM_SOUP
overcookedAPI.ORDER_CHEESE_PIZZA = ORDER_CHEESE_PIZZA
overcookedAPI.ORDER_PEPPERONI_PIZZA = ORDER_PEPPERONI_PIZZA
overcookedAPI.ORDER_CHICKEN_PIZZA = ORDER_CHICKEN_PIZZA
overcookedAPI.ORDER_MUSHROOM_PIZZA = ORDER_MUSHROOM_PIZZA
overcookedAPI.ORDER_MEAT_PIZZA = ORDER_MEAT_PIZZA
overcookedAPI.ORDER_PEPPERONI_MUSHROOM_PIZZA = ORDER_PEPPERONI_MUSHROOM_PIZZA