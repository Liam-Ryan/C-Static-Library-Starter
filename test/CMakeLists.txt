find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
link_directories(${CHECK_LIBRARY_DIRS})

add_executable(testexec test.c)
target_link_libraries(testexec library ${CHECK_LIBRARIES} pthread)
