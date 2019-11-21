cmake_minimum_required (VERSION 2.6)
SET (CMAKE_CXX_COMPILER "/usr/bin/g++")
include_directories ("skyelib")
include_directories ("timercpp")
include_directories ("yaml-cpp")
include_directories ("include")
add_subdirectory (skyelib)
add_subdirectory (timercpp)
add_subdirectory (yaml-cpp)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

project (dog)
add_executable(dog src/dog.cpp src/command.cpp src/event.cpp src/console.cpp src/main.cpp)
target_link_libraries(dog skyelib timercpp yaml-cpp)

