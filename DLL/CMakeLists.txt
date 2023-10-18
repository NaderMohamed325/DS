cmake_minimum_required(VERSION 3.26)
project(DLL C)

set(CMAKE_C_STANDARD 23)

add_executable(DLL main.c
        DLL.c
        DLL.h)
