#include "Graph.h"

#pragma once

class AdjVec : public Graph
{
public:
    AdjVec() {};
    AdjVec(size_t size);
    void erase(int vertex);
    void insert_edge(int source, int dest);
    void resize(size_t vertices);
    int vertices();
    void traverse();
private:
    std::vector<std::vector<int>> adj;
    size_t n;
};