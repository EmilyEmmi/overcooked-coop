LEVEL_TEST = level_register('level_ocTest_entry', COURSE_NONE, 'Test Level', 'test', 28000, 0x28, 0x28, 0x28)

ALL_ORDERS = {}
for i=0,#ORDER_DATA do
    table.insert(ALL_ORDERS, i)
end

OC_LEVEL_TEST = 0
OC_LEVEL_DATA = {
    [OC_LEVEL_TEST] = {
        name = "Test Level",
        level = LEVEL_TEST,
        totalTime = 240,
        failTime = {130, 130, 130, 130},
        orders = ALL_ORDERS,
    },
}