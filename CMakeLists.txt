cmake_minimum_required(VERSION 3.10.0)
project(dog-ident VERSION 0.1.0 LANGUAGES C CXX)

if(MSVC)
    add_compile_options(/Zc:twoPhase- /permissive- /experimental:preprocessor)
    add_compile_options(/reference:header-unit=std.core) 
endif()

if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
endif()

add_executable(dog-ident src/main.cpp)

