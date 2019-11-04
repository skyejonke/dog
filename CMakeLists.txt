cmake_minimum_required (VERSION 2.6)
include_directories ("skyelib")
include_directories ("timercpp")
add_subdirectory (skyelib)
add_subdirectory (timercpp)

project (dog)
add_executable(dog dog.cpp)
target_link_libraries(dog skyelib timercpp)

