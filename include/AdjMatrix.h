#include "Graph.h"

#pragma once

class AdjMatrix : public Graph
{
public:
    AdjMatrix() {};
    AdjMatrix(size_t size);
    void erase(int vertex);
    void insert_edge(int source, int dest);
    void resize(size_t vertices);
    int vertices();
    std::vector<int> edges(int source);
private:
    std::vector<std::vector<bool>> adj;
    size_t n;
};

