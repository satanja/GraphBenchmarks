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
private:
    std::vector<std::set<int>> adj;
    int n;
};