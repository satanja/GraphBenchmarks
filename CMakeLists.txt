cmake_minimum_required(VERSION 3.10)

project(quickdel)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

set(HEADERS
    include/Graph.h
    include/AdjDeque.h
    include/AdjForwardList.h
    include/AdjHash.h
    include/AdjList.h
    include/AdjVec.h
    include/AdjMatrix.h
    include/AdjMatrixVec.h
    include/AdjSet.h
)

set(SOURCES
    src/main.cpp
    src/AdjDeque.cpp
    src/AdjForwardList.cpp
    src/AdjHash.cpp
    src/AdjList.cpp
    src/AdjVec.cpp
    src/AdjMatrix.cpp
    src/AdjMatrixVec.cpp
    src/AdjSet.cpp
)

add_executable(quickdel ${SOURCES} ${HEADERS})
add_executable(minibench src/extra.cpp)