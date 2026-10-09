
cmake_minimum_required(VERSION 3.16)

project(Project1_Static LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ode STATIC ode.cpp)

target_include_directories(ode PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(Project1 main.cpp)

target_link_libraries(Project1 PRIVATE ode)