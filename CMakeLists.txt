cmake_minimum_required(VERSION 3.0.0)

project("Tortilla")

add_executable("Tortilla" main.cpp CHIP8.cpp rom.cpp)
