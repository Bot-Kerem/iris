cmake_minimum_required(VERSION 3.23)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(iris VERSION 0.1 LANGUAGES CXX)

# Check third party libraries
find_package(glfw3)

add_library(iris STATIC source/window.cpp)

target_include_directories(iris PUBLIC include)

