# Configurazione minimale per CMake
cmake_minimum_required(VERSION 3.16)
project(C02046)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(c02046 src/employee.cpp src/lecturer.cpp src/researcher.cpp src/lecturerresearcher.cpp src/main.cpp)
