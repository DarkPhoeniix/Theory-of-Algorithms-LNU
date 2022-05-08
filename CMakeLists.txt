cmake_minimum_required(VERSION 3.21)
project(task_01)

SET(CMAKE_CXX_FLAGS "-O0")
SET(CMAKE_C_FLAGS "-O0")

set(CMAKE_CXX_STANDARD 20)

find_package (Python REQUIRED
        COMPONENTS Interpreter Development)

add_subdirectory(src)
