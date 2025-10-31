cmake_minimum_required(VERSION 3.16)
project(ticTacToe C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


file(GLOB SRC_FILES src/*.c)
add_executable(main ${SRC_FILES})

target_include_directories(main PRIVATE include)