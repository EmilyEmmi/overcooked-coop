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
OC_LEVEL_DATA = {
    [OC_LEVEL_TEST] = {
        name = "Test Level",
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
        name = "Level 1",
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
        name = "Level 2",
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
        name = "Level 3",
        level = LEVEL_JRB,
        totalTime = 240,
        failTime = {240, 210, 180, 160},
        orders = {ORDER_TOMATO_SOUP, ORDER_ONION_SOUP, ORDER_MUSHROOM_SOUP},
        starScores = {
            {100, 200, 400, 700},
            {250, 550, 900, 1200},
            {350, 750, 1100, 1500},
            {400, 800, 1200, 1700},
        },
    },
    [OC_LEVEL_LAVA] = {
        name = "Level 4",
        level = LEVEL_SSL,
        totalTime = 210,
        failTime = {210, 210, 180, 160},
        orders = {ORDER_PLAIN_BURGER, ORDER_CHEESE_BURGER},
        starScores = {
            {50, 100, 300, 500},
            {100, 250, 500, 900},
            {250, 450, 700, 1200},
            {300, 600, 900, 1500},
        },
    },
}