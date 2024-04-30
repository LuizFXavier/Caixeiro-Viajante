cmake_minimum_required(VERSION 3.28.3)

project(tsp)

add_executable(tsp
    src/main.cpp
    src/Cidade.cpp
    src/Visitas.cpp)

target_include_directories(tsp PRIVATE include)