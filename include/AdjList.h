#include "Graph.h"
#include <list>

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
    void traverse();
private:
    std::vector<std::list<int>> adj;
    size_t n;
};