cmake_minimum_required(VERSION 3.13)
project(Lab2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab2 main.c repository.c repository.h controllers.c controllers.h UI.c UI.h Materie.c Materie.h Validator.c Validator.h Teste.c Teste.h)