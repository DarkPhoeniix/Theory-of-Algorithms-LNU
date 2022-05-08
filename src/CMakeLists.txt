include_directories(.)

add_executable(task_01
        main.cpp
        Utility.h
        Sort.h
        Utility.cpp
        Sort.cpp)

find_package (Python REQUIRED
        COMPONENTS Interpreter Development)

target_include_directories(${PROJECT_NAME} PRIVATE ${Python_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${Python_LIBRARY_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Python_LIBRARIES})
