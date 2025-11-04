cmake_minimum_required(VERSION 3.16)
project(main)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add your source files
add_executable(main
    src/interface.c
    src/main.c
    src/logic.c
)

target_include_directories(main PRIVATE include)