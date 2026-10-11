
cmake_minimum_required(VERSION 3.16)

project(Project4_Implicit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Project4_Implicit main.cpp)

target_include_directories(Project4_Implicit PRIVATE
    ../Project2_Shared/sdk/include
    ../StudentB_SDK/include
)

target_link_libraries(Project4_Implicit PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/../Project2_Shared/sdk/lib/libode.dll.a"
    "${CMAKE_CURRENT_SOURCE_DIR}/../StudentB_SDK/lib/libStudentBLib.dll.a"
)

add_custom_command(TARGET Project4_Implicit POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/../Project2_Shared/sdk/bin/libode.dll"
        "$<TARGET_FILE_DIR:Project4_Implicit>/libode.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/../StudentB_SDK/bin/libStudentBLib.dll"
        "$<TARGET_FILE_DIR:Project4_Implicit>/libStudentBLib.dll"
)
