cmake_minimum_required (VERSION 2.6)
include_directories ("skyelib")
include_directories ("timercpp")
add_subdirectory (skyelib)
add_subdirectory (timercpp)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

project (dog)
add_executable(dog dog.cpp)
target_link_libraries(dog skyelib timercpp)

