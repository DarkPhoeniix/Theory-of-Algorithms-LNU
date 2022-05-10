include_directories(.)

add_executable(task_01
        main.cpp
        Utility.h
        Sort.h
        Utility.cpp
        Sort.cpp
        Application.cpp
        Application.h)

find_package (Python REQUIRED
        COMPONENTS Interpreter Development)

find_package(pybind11 CONFIG REQUIRED)

set(PYBIND11_CPP_STANDARD -std=c++20)
set(PYBIND11_PYTHON_VERION 3.10 CHACHE STRING "")

target_link_libraries(task_01 PRIVATE Python::Python)
target_link_libraries(task_01 PRIVATE pybind11::embed)
