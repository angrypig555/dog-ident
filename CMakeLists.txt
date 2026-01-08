cmake_minimum_required(VERSION 3.10.0)
project(dog-ident VERSION 0.1.0 LANGUAGES C CXX)

add_executable(dog-ident src/main.cpp)

if(MSVC)
    add_compile_options(/permissive-)
endif()