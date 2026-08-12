LEVEL_TEST = level_register('level_ocTest_entry', COURSE_NONE, 'Test Level', 'test', 28000, 0x28, 0x28, 0x28)

ALL_ORDERS = {}
for i=0,#ORDER_DATA do
    table.insert(ALL_ORDERS, i)
end

OC_LEVEL_TEST = 0
OC_LEVEL_BOB = 1
OC_LEVEL_WF = 2
OC_LEVEL_SHIP = 3
OC_LEVEL_LAVA = 4
OC_LEVEL_SAND = 5
OC_LEVEL_TTC = 6
OC_LEVEL_RR = 7
OC_LEVEL_CCM = 8
OC_LEVEL_DATA = {
    [OC_LEVEL_TEST] = {
        name = "Test Level",
        desc = "Debug level containing all mechanics. Very challenging! Save it for last!",
        level = LEVEL_TEST,
        totalTime = 240,
        failTime = {210, 190, 160, 130},
        orders = ALL_ORDERS,
        starScores = {
            {100, 200, 500, 800},
            {150, 300, 600, 1000},
            {200, 400, 800, 1200},
            {250, 500, 950, 1500},
        },
    },
    [OC_LEVEL_BOB] = {
        name = "Bob-Omb Saladfield",
        desc = "A simple level with salad that teaches the basic mechanics. Start here!",
        level = LEVEL_BOB,
        totalTime = 180,
        failTime = {180, 150, 120, 90},
        orders = {ORDER_PLAIN_SALAD, ORDER_MIXED_SALAD},
        starScores = {
            {100, 250, 600, 1000},
            {200, 400, 800, 1200},
            {300, 700, 1000, 1500},
            {400, 800, 1200, 1700},
        },
    },
    [OC_LEVEL_WF] = {
        name = "Whomp's Spinning Salads",
        desc = "Tread carefully across the spinning platforms to create salads, and make sure you wash those dishes!",
        level = LEVEL_WF,
        totalTime = 210,
        failTime = {190, 160, 130, 100},
        orders = {ORDER_PLAIN_SALAD, ORDER_MIXED_SALAD},
        starScores = {
            {20, 100, 300, 500},
            {50, 150, 400, 600},
            {100, 200, 400, 700},
            {150, 300, 500, 800},
        },
    },
    [OC_LEVEL_SHIP] = {
        name = "Soupy Sea",
        desc = "Learn to make soup, but be careful- the counters will shift with the rocking boat...",
        level = LEVEL_JRB,
        totalTime = 240,
        failTime = {240, 210, 180, 160},
        orders = {ORDER_TOMATO_SOUP, ORDER_ONION_SOUP, ORDER_MUSHROOM_SOUP},
        starScores = {
            {100, 200, 400, 700},
            {150, 300, 550, 800},
            {200, 400, 700, 900},
            {250, 500, 850, 1000},
        },
    },
    [OC_LEVEL_LAVA] = {
        name = "Lethal Lava Puzzle",
        desc = "Make more soup, but watch your step! If you stand on a moving puzzle piece, you'll be dropped into lava!",
        level = LEVEL_LLL,
        totalTime = 240,
        failTime = {240, 240, 210, 180},
        orders = {ORDER_TOMATO_SOUP, ORDER_ONION_SOUP, ORDER_MUSHROOM_SOUP},
        starScores = {
            {20, 50, 200, 500},
            {50, 200, 400, 600},
            {150, 300, 500, 700},
            {200, 500, 600, 800},
        },
    },
    [OC_LEVEL_SAND] = {
        name = "Shifting Sand Burgers",
        desc = "Learn to make burgers, but don't fall into the quicksand!",
        level = LEVEL_SSL,
        totalTime = 210,
        failTime = {210, 210, 180, 160},
        orders = {ORDER_PLAIN_BURGER, ORDER_CHEESE_BURGER},
        starScores = {
            {50, 100, 300, 550},
            {100, 250, 500, 750},
            {250, 450, 650, 800},
            {300, 600, 850, 1000},
        },
    },
    [OC_LEVEL_TTC] = {
        name = "Burger Time",
        desc = "Make more complicated burgers! Use the Wall Kick to reach the ingredients!",
        level = LEVEL_TTC,
        totalTime = 210,
        failTime = {210, 210, 180, 160},
        orders = {ORDER_PLAIN_BURGER, ORDER_CHEESE_BURGER, ORDER_LETTUCE_BURGER, ORDER_CHEESE_LETTUCE_BURGER, ORDER_LETTUCE_TOMATO_BURGER, ORDER_DELUXE_BURGER},
        starScores = {
            {30, 100, 250, 400},
            {50, 150, 350, 600},
            {100, 200, 400, 800},
            {150, 300, 450, 1000},
        },
    },
    [OC_LEVEL_CCM] = {
        name = "Slip Slidin' Pizzas",
        desc = "Become aquainted with the realm of Pizza. Slide down to access the lower area quickly, but don't slip off of the mountain!",
        level = LEVEL_CCM,
        totalTime = 210,
        failTime = {210, 180, 150, 120},
        orders = {ORDER_CHEESE_PIZZA, ORDER_PEPPERONI_PIZZA, ORDER_CHICKEN_PIZZA, ORDER_MUSHROOM_PIZZA},
        starScores = {
            {50, 150, 400, 600},
            {100, 300, 500, 800},
            {200, 450, 700, 900},
            {300, 600, 900, 1100},
        },
    },
    [OC_LEVEL_RR] = {
        name = "Rainbow Cruise",
        desc = "Put burgers and salad together on this carpet ride! Take advantage of when the carpets are together!",
        level = LEVEL_RR,
        totalTime = 240,
        failTime = {240, 210, 180, 160},
        -- multiple copies of the salads so that they are more likely to apepar
        orders = {ORDER_PLAIN_BURGER, ORDER_CHEESE_BURGER, ORDER_LETTUCE_BURGER, ORDER_CHEESE_LETTUCE_BURGER, ORDER_LETTUCE_TOMATO_BURGER, ORDER_DELUXE_BURGER,
        ORDER_PLAIN_SALAD, ORDER_PLAIN_SALAD, ORDER_MIXED_SALAD, ORDER_MIXED_SALAD},
        starScores = {
            {50, 200, 350, 650},
            {100, 300, 450, 750},
            {200, 400, 600, 850},
            {250, 500, 700, 950},
        },
    },
}