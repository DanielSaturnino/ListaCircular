cmake_minimum_required(VERSION 2.8.9)
project(ListaCircular)

include_directories(include)

set(SOURCES src/Nodo.cpp src/main.cpp src/ListaCircular.cpp)

add_executable(ListaCircular ${SOURCES})