#include "Graph.h"

#pragma once

class AdjList : public Graph
{
public:
    AdjList() {};
    AdjList(size_t size);
    void erase(int vertex);
    void insert_edge(int source, int dest);
    void resize(size_t vertices);
    int vertices();
    std::vector<int> edges(int source);
private:
    std::vector<std::vector<int>> adj;
    size_t n;
};