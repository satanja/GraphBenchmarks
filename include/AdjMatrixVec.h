#include "Graph.h"
#include <utility>

#pragma once

class AdjMatrixVec : public Graph
{
public:
    AdjMatrixVec() {};
    AdjMatrixVec(size_t size);
    void erase(int vertex);
    void insert_edge(int source, int dest);
    void resize(size_t vertices);
    int vertices();
    void traverse();
private:
    std::vector<std::vector<bool>> adj;
    std::vector<std::vector<int>> adj_edges;
    size_t n;
};

