cmake_minimum_required(VERSION 3.10)

project(quickdel)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(HEADERS
    include/Graph.h    
)

set(SOURCES
    src/main.cpp
    src/Graph.cpp
)

add_executable(quickdel ${SOURCES} ${HEADERS})