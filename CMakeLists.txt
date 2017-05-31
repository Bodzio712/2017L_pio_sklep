cmake_minimum_required(VERSION 3.6)
project(2017L_pio_sklep)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c paragon.c wyplata.c obsluga.c test.c menu.c )
add_executable(2017L_pio_sklep ${SOURCE_FILES})