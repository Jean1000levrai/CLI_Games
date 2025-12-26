cmake_minimum_required(VERSION 3.16)
project(hangman)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add your source files
add_executable(hangman
    src/interface.c
    src/main.c
    src/logic.c
    src/hangman.c
)

target_include_directories(hangman PRIVATE include)