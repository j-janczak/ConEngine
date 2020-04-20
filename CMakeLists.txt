cmake_minimum_required(VERSION 3.10)
project(ConEngine)

file(GLOB_RECURSE ALL_CLASSES Game/*.cpp)
add_executable(program Main.cpp ${ALL_CLASSES})