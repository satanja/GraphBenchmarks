#include "Graph.h"
#include <utility>

#pragma once

class AdjMatrixList : public Graph
{
public:
    AdjMatrixList() {};
    AdjMatrixList(size_t size);
    void erase(int vertex);
    void insert_edge(int source, int dest);
    void resize(size_t vertices);
    int vertices();
    std::vector<int> edges(int source);
private:
    std::vector<std::pair<std::vector<int>, std::vector<int>>> adj;
    size_t n;
};

