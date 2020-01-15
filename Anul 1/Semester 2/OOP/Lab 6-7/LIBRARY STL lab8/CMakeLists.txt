cmake_minimum_required(VERSION 3.13)
project(Library)

set(CMAKE_CXX_STANDARD 14)

add_executable(Library main.cpp console.cpp console.h Book.cpp Book.h bookrepo.cpp bookrepo.h BookStore.cpp BookStore.h validator.cpp validator.h)