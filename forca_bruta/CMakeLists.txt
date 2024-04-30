cmake_minimum_required(VERSION 3.28.3)

project(tsp_FB)

add_executable(tsp_FB
    src/main.cpp
    src/Buscador.cpp)

target_include_directories(tsp_FB PRIVATE include)