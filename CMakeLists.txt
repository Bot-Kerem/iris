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
find_package(spdlog)

add_subdirectory(third_party/glad)


add_library(iris STATIC
	source/window.cpp
	source/application.cpp
	source/scene.cpp
	source/vertex_array.cpp
	source/vertex_buffer.cpp
	source/shader.cpp
	)

target_link_libraries(iris glfw spdlog::spdlog glad)
target_include_directories(iris PUBLIC include PRIVATE source)

