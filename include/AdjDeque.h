#include "Graph.h"
#include <deque>

#pragma once

class AdjDeque : public Graph
{
public:
    AdjDeque() {};
    AdjDeque(size_t size);
    void erase(int vertex);
    void insert_edge(int source, int dest);
    void resize(size_t vertices);
    int vertices();
    void traverse();
private:
    std::vector<std::deque<int>> adj;
    size_t n;
};