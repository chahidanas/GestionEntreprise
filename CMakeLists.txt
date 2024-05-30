cmake_minimum_required(VERSION 3.28)
project(GestionEntreprise)

set(CMAKE_CXX_STANDARD 14)

add_executable(GestionEntreprise main.cpp
        classes.cpp
        classes.h
        introLoad.cpp
        introLoad.h)
