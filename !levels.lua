LEVEL_TEST = level_register('level_ocTest_entry', COURSE_NONE, 'Test Level', 'test', 28000, 0x28, 0x28, 0x28)

ALL_ORDERS = {}
for i=0,#ORDER_DATA do
    table.insert(ALL_ORDERS, i)
end

OC_LEVEL_TEST = 0
OC_LEVEL_BOB = 1
OC_LEVEL_DATA = {
    [OC_LEVEL_TEST] = {
        name = "Test Level",
        level = LEVEL_TEST,
        totalTime = 240,
        failTime = {130, 130, 130, 130},
        orders = ALL_ORDERS,
    },
    [OC_LEVEL_BOB] = {
        name = "Level 1",
        level = LEVEL_BOB,
        totalTime = 180,
        failTime = {150, 120, 90, 60},
        orders = {ORDER_PLAIN_SALAD, ORDER_MIXED_SALAD},
    },
}