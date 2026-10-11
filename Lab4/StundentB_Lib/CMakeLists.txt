cmake_minimum_required(VERSION 3.20)
project(StudentBLibProject LANGUAGES CXX)

add_library(StudentBLib SHARED src/polynomials.cpp)

target_compile_definitions(StudentBLib PRIVATE STUDENTB_EXPORTS)

target_include_directories(StudentBLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(StudentBLib PUBLIC cxx_std_20)