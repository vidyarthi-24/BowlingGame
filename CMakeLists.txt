cmake_minimum_required (VERSION 2.8...3.10)

set(This BowlingGame)

project(${This} CXX)

set(CMake_C_STANDARD 99)
set(CMake_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    BowlingGame.h
)
set(Sources
    BowlingGame.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
add_subdirectory(tests)
