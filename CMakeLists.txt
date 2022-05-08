cmake_minimum_required(VERSION 3.21)
project(task_01)

SET(CMAKE_CXX_FLAGS "-O0")
SET(CMAKE_C_FLAGS "-O0")

set(CMAKE_CXX_STANDARD 20)

find_package( PythonInterp REQUIRED )
find_package( PythonLibs REQUIRED )
include_directories ( ${PYTHON_INCLUDE_DIRS} )

add_executable(task_01 main.cpp Utility.h Utility.cpp Sort.h Sort.cpp)
