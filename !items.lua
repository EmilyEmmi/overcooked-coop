E_MODEL_TOMATO = smlua_model_util_get_id("tomato_geo")
E_MODEL_ONION = smlua_model_util_get_id("onion_geo")
E_MODEL_MUSHROOM = smlua_model_util_get_id("mushroom_geo")
E_MODEL_STEAK = smlua_model_util_get_id("steak_geo")
E_MODEL_PATTY = smlua_model_util_get_id("patty_geo")
E_MODEL_BURGER = smlua_model_util_get_id("burger_geo")
E_MODEL_CHEESE = smlua_model_util_get_id("cheese_geo")
E_MODEL_LETTUCE = smlua_model_util_get_id("lettuce_geo")
E_MODEL_PLATE_LETTUCE = smlua_model_util_get_id("plate_lettuce_geo")
E_MODEL_PLATE_TOMATO = smlua_model_util_get_id("plate_tomato_geo")

E_MODEL_PLATE = smlua_model_util_get_id("plate_geo")
E_MODEL_POT = smlua_model_util_get_id("pot_geo")
E_MODEL_PAN = smlua_model_util_get_id("frying_pan_geo")

E_MODEL_COUNTER_CENTER = smlua_model_util_get_id("main_counter_center_geo")
E_MODEL_COUNTER_SIDE = smlua_model_util_get_id("main_counter_side_geo")
E_MODEL_COUNTER_CORNER = smlua_model_util_get_id("main_counter_corner_geo")
E_MODEL_CHOPPING_BOARD = smlua_model_util_get_id("chopping_board_geo")
E_MODEL_TRASH = smlua_model_util_get_id("trash_geo")
E_MODEL_INGREDIENT_BOX = smlua_model_util_get_id("box_geo")
E_MODEL_HEAT = smlua_model_util_get_id("heat_geo")
E_MODEL_SERVING = smlua_model_util_get_id("service_counter_geo")
E_MODEL_PLATE_COUNTER = smlua_model_util_get_id("plate_counter_geo")

E_MODEL_KNIFE = smlua_model_util_get_id("knife_geo")

ICON_BUN = get_texture_info("icon_bun")
ICON_MEAT = get_texture_info("icon_meat")
ICON_LETTUCE = get_texture_info("icon_lettuce")
ICON_TOMATO = get_texture_info("icon_tomato")
ICON_CHEESE = get_texture_info("icon_cheese")
ICON_ONION = get_texture_info("icon_onion")
ICON_MUSHROOM = get_texture_info("icon_mushroom")
ICON_POT = get_texture_info("icon_pot")
ICON_PAN = get_texture_info("icon_pan")
ICON_CUT = get_texture_info("icon_cut")
ICON_HEAT = get_texture_info("icon_heat")

ITEM_LETTUCE = 0
ITEM_LETTUCE_CUT = 1
ITEM_PLATE = 2
ITEM_POT = 3
ITEM_TOMATO = 4
ITEM_TOMATO_CUT = 5
ITEM_ONION = 6
ITEM_ONION_CUT = 7
ITEM_MUSHROOM = 8
ITEM_MUSHROOM_CUT = 9
ITEM_SOUP = 10
ITEM_BUN = 11
ITEM_MEAT = 12
ITEM_MEAT_CUT = 13
ITEM_MEAT_COOKED = 14
ITEM_PAN = 15
ITEM_BURNT = 16
ITEM_CHEESE = 17
ITEM_CHEESE_CUT = 18

SALAD_COMBO = {[ITEM_LETTUCE_CUT] = 1, [ITEM_TOMATO_CUT] = 1}
BURGER_COMBO = {[ITEM_MEAT_COOKED] = 1, [ITEM_LETTUCE_CUT] = 1, [ITEM_TOMATO_CUT] = 1, [ITEM_CHEESE_CUT] = 1}

BOX_LABEL_CASES = {
    [ITEM_MEAT] = 0,
    [ITEM_CHEESE] = 1,
    [ITEM_ONION] = 2,
    [ITEM_LETTUCE] = 3,
    [ITEM_BUN] = 4,
    [ITEM_TOMATO] = 5,
    [ITEM_MUSHROOM] = 6,
}

ITEM_DATA = {
    [ITEM_PLATE] = {
        model = E_MODEL_PLATE,
        noTrash = true,
        noThrow = true,
        isPlate = true,
    },
    [ITEM_POT] = {
        model = E_MODEL_POT,
        contentSlots = 3,
        accepts = {[ITEM_TOMATO_CUT] = 0, [ITEM_ONION_CUT] = 0, [ITEM_MUSHROOM_CUT] = 0},
        pourable = true,
        cookable = true,
        noTrash = true,
        noThrow = true,
        cookSound = SOUND_GENERAL_QUIET_BUBBLE2,
        cookSoundChance = 1/16,
        renderFunc = function(o)
            local amount = math.clamp(o.oContentCount, 0, 3)
            smlua_anim_util_set_animation(o, "pot_liquid_"..amount)
        end,
        icon = ICON_POT,
    },
    [ITEM_LETTUCE] = {
        model = E_MODEL_LETTUCE,
        cut = ITEM_LETTUCE_CUT,
        icon = ICON_LETTUCE,
    },
    [ITEM_LETTUCE_CUT] = {
        model = E_MODEL_PLATE_LETTUCE,
        plateable = true,
        plateCombine = BURGER_COMBO,
        icon = ICON_LETTUCE,
        subIcon = ICON_CUT,
    },
    [ITEM_TOMATO] = {
        model = E_MODEL_TOMATO,
        cut = ITEM_TOMATO_CUT,
        idleAnim = "tomato_idle",
        cutAnim = "tomato_cut",
        icon = ICON_TOMATO,
    },
    [ITEM_TOMATO_CUT] = {
        model = E_MODEL_TOMATO,
        modelOnPlate = E_MODEL_PLATE_TOMATO,
        plateable = true,
        plateCombine = BURGER_COMBO,
        idleAnim = "tomato_cut",
        cutAnim = "tomato_cut",
        pickupAnim = "tomato_pickup",
        plateAnim =  "tomato_idle",
        icon = ICON_TOMATO,
        subIcon = ICON_CUT,
        cookItem = ITEM_POT,
    },
    [ITEM_ONION] = {
        model = E_MODEL_ONION,
        cut = ITEM_ONION_CUT,
        idleAnim = "onion_idle",
        cutAnim = "onion_cut",
        icon = ICON_ONION,
    },
    [ITEM_ONION_CUT] = {
        model = E_MODEL_ONION,
        idleAnim = "onion_cut",
        cutAnim = "onion_cut",
        pickupAnim = "onion_pickup",
        icon = ICON_ONION,
        subIcon = ICON_CUT,
        cookItem = ITEM_POT,
    },
    [ITEM_MUSHROOM] = {
        model = E_MODEL_MUSHROOM,
        cut = ITEM_MUSHROOM_CUT,
        idleAnim = "mushroom_idle",
        cutAnim = "mushroom_cut",
        icon = ICON_MUSHROOM,
    },
    [ITEM_MUSHROOM_CUT] = {
        model = E_MODEL_MUSHROOM,
        idleAnim = "mushroom_cut",
        cutAnim = "mushroom_cut",
        pickupAnim = "mushroom_pickup",
        icon = ICON_MUSHROOM,
        subIcon = ICON_CUT,
        cookItem = ITEM_POT,
    },
    [ITEM_SOUP] = {
        model = E_MODEL_POT,
        scale = 0.5,
        isCooked = true,
        plateable = true,
        skipItem = true,
        invisOnPlate = true,
        renderFunc = function(o)
            smlua_anim_util_set_animation(o, "pot_liquid_3") -- failsafe if not on plate
        end,
    },
    [ITEM_BUN] = {
        model = E_MODEL_BURGER,
        contentSlots = 4,
        accepts = BURGER_COMBO,
        plateable = true,
        icon = ICON_BUN,
    },
    [ITEM_MEAT] = {
        model = E_MODEL_STEAK,
        cut = ITEM_MEAT_CUT,
        icon = ICON_MEAT,
    },
    [ITEM_MEAT_CUT] = {
        model = E_MODEL_PATTY,
        icon = ICON_MEAT,
        subIcon = ICON_CUT,
    },
    [ITEM_MEAT_COOKED] = {
        model = E_MODEL_PATTY,
        isCooked = true,
        plateable = true,
        plateCombine = BURGER_COMBO,
        cookItem = ITEM_PAN,
        icon = ICON_MEAT,
        subIcon = ICON_CUT,
    },
    [ITEM_PAN] = {
        model = E_MODEL_PAN,
        contentSlots = 1,
        accepts = {[ITEM_MEAT_CUT] = 0},
        pourable = true,
        cookable = true,
        noTrash = true,
        noThrow = true,
        icon = ICON_PAN,
    },
    [ITEM_BURNT] = {
        model = E_MODEL_PATTY
    },
    [ITEM_CHEESE] = {
        model = E_MODEL_CHEESE,
        cut = ITEM_CHEESE_CUT,
        icon = ICON_CHEESE,
    },
    [ITEM_CHEESE_CUT] = {
        model = E_MODEL_CHEESE,
        plateable = true,
        plateCombine = BURGER_COMBO,
        icon = ICON_CHEESE,
        subIcon = ICON_CUT,
    },
}

DEFAULT_COOK_TIME = 12 * 30 -- 12 seconds
COOKED_DATA = {
    [ITEM_POT] = {
        {
            items = {ITEM_TOMATO_CUT, ITEM_TOMATO_CUT, ITEM_TOMATO_CUT},
            result = ITEM_SOUP,
            inheritContents = true,
        },
        {
            items = {ITEM_ONION_CUT, ITEM_ONION_CUT, ITEM_ONION_CUT},
            result = ITEM_SOUP,
            inheritContents = true,
        },
        {
            items = {ITEM_MUSHROOM_CUT, ITEM_MUSHROOM_CUT, ITEM_MUSHROOM_CUT},
            result = ITEM_SOUP,
            inheritContents = true,
        },
    },
    [ITEM_PAN] = {
        {
            items = {ITEM_MEAT_CUT},
            result = ITEM_MEAT_COOKED,
        },
    },
}

COUNTER_TYPE_DEFAULT = 0
COUNTER_TYPE_CUT = 1
COUNTER_TYPE_TRASH = 2
COUNTER_TYPE_INGREDIENT = 3
COUNTER_TYPE_HEAT = 4
COUNTER_TYPE_SERVING = 5
COUNTER_TYPE_PLATES = 6

COUNTER_HEIGHT = {
    [COUNTER_TYPE_HEAT] = 36,
}

SPECIAL_COUNTER_MODELS = {
    [COUNTER_TYPE_TRASH] = E_MODEL_TRASH,
    [COUNTER_TYPE_INGREDIENT] = E_MODEL_INGREDIENT_BOX,
    [COUNTER_TYPE_HEAT] = E_MODEL_HEAT,
    [COUNTER_TYPE_SERVING] = E_MODEL_SERVING,
    [COUNTER_TYPE_PLATES] = E_MODEL_PLATE_COUNTER,
}

ORDER_PLAIN_SALAD = 0
ORDER_MIXED_SALAD = 1
ORDER_PLAIN_BURGER = 2
ORDER_CHEESE_BURGER = 3
ORDER_LETTUCE_BURGER = 4
ORDER_CHEESE_LETTUCE_BURGER = 5
ORDER_LETTUCE_TOMATO_BURGER = 6
ORDER_DELUXE_BURGER = 7
ORDER_TOMATO_SOUP = 8
ORDER_ONION_SOUP = 9
ORDER_MUSHROOM_SOUP = 10

ORDER_DATA = {
    [ORDER_PLAIN_SALAD] = {
        name = "Plain Salad",
        items = {
            {type = ITEM_LETTUCE_CUT},
        },
        icon = get_texture_info("icon_plain_salad"),
    },
    [ORDER_MIXED_SALAD] = {
        name = "Mixed Salad",
        items = {
            {type = ITEM_LETTUCE_CUT},
            {type = ITEM_TOMATO_CUT},
        },
        icon = get_texture_info("icon_mixed_salad"),
    },
    [ORDER_PLAIN_BURGER] = {
        name = "Plain Burger",
        items = {
            {type = ITEM_BUN, contents = {ITEM_MEAT_COOKED}},
        },
        icon = get_texture_info("icon_plain_burger"),
    },
    [ORDER_CHEESE_BURGER] = {
        name = "Cheeseburger",
        items = {
            {type = ITEM_BUN, contents = {ITEM_MEAT_COOKED, ITEM_CHEESE_CUT}},
        },
        icon = get_texture_info("icon_cheeseburger"),
    },
    [ORDER_LETTUCE_BURGER] = {
        name = "Lettuce Burger",
        items = {
            {type = ITEM_BUN, contents = {ITEM_MEAT_COOKED, ITEM_LETTUCE_CUT}},
        },
        icon = get_texture_info("icon_lettuce_burger"),
    },
    [ORDER_CHEESE_LETTUCE_BURGER] = {
        name = "Lettuce Cheeseburger",
        items = {
            {type = ITEM_BUN, contents = {ITEM_MEAT_COOKED, ITEM_LETTUCE_CUT, ITEM_CHEESE_CUT}},
        },
        icon = get_texture_info("icon_lettuce_cheeseburger"),
    },
    [ORDER_LETTUCE_TOMATO_BURGER] = {
        name = "Veggie Lovers' Burger",
        items = {
            {type = ITEM_BUN, contents = {ITEM_MEAT_COOKED, ITEM_LETTUCE_CUT, ITEM_TOMATO_CUT}},
        },
        icon = get_texture_info("icon_lettuce_tomato_burger"),
    },
    [ORDER_DELUXE_BURGER] = {
        name = "Deluxe Burger",
        items = {
            {type = ITEM_BUN, contents = {ITEM_MEAT_COOKED, ITEM_LETTUCE_CUT, ITEM_TOMATO_CUT, ITEM_CHEESE_CUT}},
        },
        icon = get_texture_info("icon_deluxe_burger"),
    },
    [ORDER_TOMATO_SOUP] = {
        name = "Tomato Soup",
        items = {
            {type = ITEM_SOUP, contents = {ITEM_TOMATO_CUT, ITEM_TOMATO_CUT, ITEM_TOMATO_CUT}},
        },
        icon = get_texture_info("icon_tomato_soup"),
    },
    [ORDER_ONION_SOUP] = {
        name = "Onion Soup",
        items = {
            {type = ITEM_SOUP, contents = {ITEM_ONION_CUT, ITEM_ONION_CUT, ITEM_ONION_CUT}},
        },
        icon = get_texture_info("icon_onion_soup"),
    },
    [ORDER_MUSHROOM_SOUP] = {
        name = "Mushroom Soup",
        items = {
            {type = ITEM_SOUP, contents = {ITEM_MUSHROOM_CUT, ITEM_MUSHROOM_CUT, ITEM_MUSHROOM_CUT}},
        },
        icon = get_texture_info("icon_mushroom_soup"),
    },
}