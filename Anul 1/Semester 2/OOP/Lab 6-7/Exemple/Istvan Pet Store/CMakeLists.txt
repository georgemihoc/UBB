cmake_minimum_required(VERSION 3.13)
project(Library)

set(CMAKE_CXX_STANDARD 14)

add_executable(Library main.cpp console.cpp console.h Pet.cpp Pet.h petrepo.cpp petrepo.h PetStore.cpp PetStore.h validator.cpp validator.h)