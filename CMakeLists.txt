cmake_minimum_required(VERSION 3.10.0)
project(dog-ident VERSION 0.1.0 LANGUAGES C CXX)

if(MSVC)
    add_compile_options(/Zc:twoPhase- /permissive- /experimental:preprocessor)
    # This specifically enables 'and', 'or', 'not'
    add_compile_options(/reference:header-unit=std.core) 
endif()

add_executable(dog-ident src/main.cpp)

