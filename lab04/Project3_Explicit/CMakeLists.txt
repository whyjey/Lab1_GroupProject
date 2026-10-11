
cmake_minimum_required(VERSION 3.16)

project(Project3_Explicit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Project3_Explicit main.cpp)

target_link_libraries(Project3_Explicit PRIVATE ${CMAKE_DL_LIBS})

add_custom_command(TARGET Project3_Explicit POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/../Project2_Shared/sdk/bin/libode.dll"
        "$<TARGET_FILE_DIR:Project3_Explicit>/libode.dll"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/../StudentB_SDK/bin/libStudentBLib.dll"
        "$<TARGET_FILE_DIR:Project3_Explicit>/libStudentBLib.dll"
)
