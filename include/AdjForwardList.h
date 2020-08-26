#include "Graph.h"
#include <forward_list>

#pragma once

class AdjForwardList : public Graph
{
public:
    AdjForwardList() {};
    AdjForwardList(size_t size);
    void erase(int vertex);
    void insert_edge(int source, int dest);
    void resize(size_t vertices);
    int vertices();
    void traverse();
private:
    std::vector<std::forward_list<int>> adj;
    size_t n;
};