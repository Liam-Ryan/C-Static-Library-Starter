find_package(Check REQUIRED)
add_executable(testexec test.c)
target_link_libraries(testexec library ${CHECK_LIBRARIES} pthread)
ADD_TEST(UnitTests testexec)
