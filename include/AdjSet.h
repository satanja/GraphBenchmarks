#include "Graph.h"

#pragma once

class AdjSet : public Graph
{
public:
    AdjSet() {};
    AdjSet(size_t size);
    void erase(int vertex);
    void insert_edge(int source, int dest);
    void resize(size_t vertices);
    int vertices();
    std::vector<int> edges(int source);
private:
    std::vector<std::set<int>> adj;
    size_t n;
};