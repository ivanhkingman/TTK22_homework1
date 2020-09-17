cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

#Project name
project(hello)

#Where to find the included source files
include_directories("${PROJECT_SOURCE_DIR}")

#List source related with CPP IMC bindings
file(GLOB_RECURSE IMC_SOURCES "${PROJECT_SOURCE_DIR}/IMC/*.cpp")
file(GLOB_RECURSE IMC_HEADERS "${PROJECT_SOURCE_DIR}/IMC/*.hpp")

#List source related with CPP UDP bindings
file(GLOB_RECURSE UDP_SOURCES "${PROJECT_SOURCE_DIR}/UDP/DatagramSocket.cpp")
file(GLOB_RECURSE UDP_HEADERS "${PROJECT_SOURCE_DIR}/UDP/DatagranSocket.hpp")

#Create static library using all of UDP sources/headers
add_library(udp ${UDP_HEADERS} ${UDP_SOURCES})

#Create static (by default) library using all of IMC sources/headers
add_library(imc ${IMC_HEADERS} ${IMC_SOURCES})

add_executable(hello hello.cpp)