LEVEL_TEST = level_register('level_ocTest_entry', COURSE_NONE, 'Test Level', 'test', 28000, 0x28, 0x28, 0x28)

ALL_ORDERS = {}
for i=0,#ORDER_DATA do
    table.insert(ALL_ORDERS, i)
end

OC_LEVEL_TEST = 0
OC_LEVEL_BOB = 1
OC_LEVEL_WF = 2
OC_LEVEL_DATA = {
    [OC_LEVEL_TEST] = {
        name = "Test Level",
        level = LEVEL_TEST,
        totalTime = 240,
        failTime = {210, 190, 160, 130},
        orders = ALL_ORDERS,
        starScores = {
            {200, 400, 800, 1000},
            {200, 400, 800, 1000},
            {200, 400, 800, 1000},
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
            {200, 400, 800, 1000},
            {200, 400, 800, 1000},
            {200, 400, 800, 1000},
            {200, 400, 800, 1000},
        },
    },
    [OC_LEVEL_WF] = {
        name = "Level 2",
        level = LEVEL_WF,
        totalTime = 180,
        failTime = {180, 150, 120, 90},
        orders = {ORDER_PLAIN_SALAD, ORDER_MIXED_SALAD},
        starScores = {
            {200, 300, 450, 600},
            {100, 300, 600, 800},
            {100, 300, 600, 800},
            {100, 300, 600, 800},
        },
    },
}