cmake_minimum_required(VERSION 3.13)
project(TravelAgencyApplication C)

set(CMAKE_C_STANDARD 99)

add_executable(TravelAgencyApplication Repository.c Repository.h Main.c COnsole.c Console.h Validator.c Validator.h Service.c Service.h Vector.c Vector.h Package.c Package.h TestPackage.c TestPackage.h TestVector.c TestVector.h TestRepository.c TestRepository.h TestService.c TestService.h TestValidator.c TestValidator.h)