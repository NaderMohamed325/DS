cmake_minimum_required(VERSION 3.26)
project(Queue C)

set(CMAKE_C_STANDARD 23)

add_executable(Queue main.c
        Queue.c
        Queue.h)
