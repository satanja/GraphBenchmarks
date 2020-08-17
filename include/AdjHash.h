#include "Graph.h"

#pragma once

class AdjHash : public Graph
{
public:
    AdjHash() {};
    AdjHash(size_t size);
    void erase(int vertex);
    void insert_edge(int source, int dest);
    void resize(size_t vertices);
    int vertices();
    std::vector<int> edges(int source);
private:
    std::vector<std::unordered_set<int>> adj;
    size_t n;
};