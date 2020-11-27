cmake_minimum_required(VERSION 3.10.2)
project(projet-git-esgi C)

set(CMAKE_C_STANDARD 99)

# Add an executable compiled from hello.c
add_executable(projet-git-esgi main.c readXml.c readXml.h generate.c generate.h)