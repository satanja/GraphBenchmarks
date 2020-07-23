cmake_minimum_required(VERSION 3.10)

project(quickdel)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(HEADERS
    include/Graph.h
    include/AdjList.h
    include/AdjMatrix.h
    include/AdjSet.h
)

set(SOURCES
    src/main.cpp
    src/AdjList.cpp
    src/AdjMatrix.cpp
    src/AdjSet.cpp
)

add_executable(quickdel ${SOURCES} ${HEADERS})