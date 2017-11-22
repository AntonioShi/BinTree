cmake_minimum_required(VERSION 3.8)
project(BinTree)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c bintree.h LQueue.h)
add_executable(BinTree ${SOURCE_FILES} bintree.h LQueue.h)