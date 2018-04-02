cmake_minimum_required(VERSION 3.8)
project(ahalai)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp)
add_executable(ahalai ${SOURCE_FILES})
target_link_libraries(ahalai gtest gtest_main)