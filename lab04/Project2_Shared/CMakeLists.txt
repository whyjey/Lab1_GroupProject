
cmake_minimum_required(VERSION 3.16)

project(Project2_Shared LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ode SHARED src/ode.cpp)

target_include_directories(ode
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(ode PRIVATE ODE_EXPORTS)