cmake_minimum_required(VERSION 3.26)
project(ProjetC C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetC main.c
        bib.h
        bib.c)
