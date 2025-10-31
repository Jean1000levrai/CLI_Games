cmake_minimum_required(VERSION 3.16)
project(mastermind C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(main 
    src/main.c src/logic.c src/interface.c)

target_include_directories(main PRIVATE include)