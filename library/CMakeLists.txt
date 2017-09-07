set(SOURCE_FILES library.c library.h)
add_library(library ${SOURCE_FILES})
target_include_directories(library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})