cmake_minimum_required(VERSION 3.10)
project(MyApp C)

set(CMAKE_C_STANDARD 11)

# Add include directory for headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add your source files
add_executable(main
    src/main.c
    src/logic.c
    src/interface.c
)
