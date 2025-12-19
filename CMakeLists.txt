cmake_minimum_required(VERSION 3.10)

project(route_planner_cp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(route_planner_cp
    src/main.cpp
    src/graph.cpp
    src/pathfinder.cpp
)

target_include_directories(route_planner_cp PRIVATE src)
