cmake_minimum_required(VERSION 3.16)
project(ticTacToe C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


file(GLOB SRC_FILES src/*.c)
add_executable(ticTacToe ${SRC_FILES})

target_include_directories(ticTacToe PRIVATE include)