cmake_minimum_required (VERSION 2.6)
include_directories ("skyelib")
add_subdirectory (skyelib)

project (dog)
add_executable(dog dog.cpp)
target_link_libraries(dog skyelib)

