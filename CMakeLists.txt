cmake_minimum_required(VERSION 3.5)
project (dog LANGUAGES CXX VERSION 0.2.2)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
SET(CXX,"g++")
include_directories ("skyelib")
include_directories ("include")
add_subdirectory (skyelib)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

add_library(doglib STATIC src/dog.cpp src/command.cpp src/event.cpp src/console.cpp )
target_link_libraries(doglib skyelib)
add_executable(dog src/main.cpp)
target_link_libraries(dog doglib)
add_executable(tests test/test.cpp)
target_link_libraries(tests doglib)
install(TARGETS dog doglib
	RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)
enable_testing()
add_test(NAME mainTest COMMAND tests)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_FILE_NAME, "dog")
SET(CPACK_DEBIAN_PACKAGE_DESCRIPTION,"The program that lets you play with dogs on the command line!")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "skyenet") #required
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
include (CPack)

