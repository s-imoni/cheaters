cmake_minimum_required(VERSION 3.15)
project(lab3_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(lab3_2
        stack_arr.h
        driver.c
        stack_arr.c)
