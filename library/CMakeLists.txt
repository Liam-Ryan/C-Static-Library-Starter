option(BUILD_SHARED_LIBS "build as shared libraries" OFF)
add_library(library library.c)
target_include_directories(library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})