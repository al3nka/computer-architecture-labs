cmake_minimum_required(VERSION 3.8)

project(lab2)

set(SOURCE_EXE interface.cpp )

set(SOURCE_LIB calculator.cpp)

add_library(calculator STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main calculator)