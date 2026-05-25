cmake_minimum_required(VERSION 4.2)
project(CoreC C)

set(CMAKE_C_STANDARD 99)

add_executable(CoreC main.c
        RemoveACharFromString/RemoveACharFromString.h
        RemoveACharFromString/RemoveACharFromString.c
        SplitOnce/split_once.h
        SplitOnce/split_once.c)
