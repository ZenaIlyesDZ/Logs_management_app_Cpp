# *@file : CMakeList.txt
#* @brief summary of the role : File of configuration of the CMake project.
#* @author : Ilyes
#* @date : 17/01/2026 
# * @details : File of configuration of the CMake project for compiling and linking the log management program in C++.

cmake_minimum_required(VERSION 3.10)

project(Gestion_logs VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#1/3- Add the source files of your project
set(SRCS
    Gestion_logs.cpp
    Menu/Menu.cpp
    Logs/log.cpp
)
#2/3- Add the header files of your project
set(HEADERS
    Menu/Menu.h
    Logs/log.h
)
#3/3-Add the include directories for your project
include_directories(Menu)
include_directories(Logs)

add_executable(Gestion_logs ${SRCS} ${HEADERS})
