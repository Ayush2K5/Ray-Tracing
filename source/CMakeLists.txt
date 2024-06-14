cmake_minimum_required(VERSION 3.10)
project(RayTracing)

add_executable(RayTracing src/main.cpp)
target_include_directories(RayTracing PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
