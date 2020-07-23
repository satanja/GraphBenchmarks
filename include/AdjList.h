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
private:
    std::vector<std::vector<int>> adj;
    int n;
};