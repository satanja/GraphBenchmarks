#include <vector>
#include <set>

#pragma once

class Graph
{
public:
    // Default constructor
    Graph();

    // Copy constructor
    // Test if needed
    // Graph(const Graph& g);

    // Preallocates graph with a size
    Graph(size_t vertices);

    // Erases a vertex and all its incident edges
    void erase(int vertex);

    // Inserts a new edge
    void insert_edge(int source, int dest);

    // Reallocates an empty graph of size s
    void resize(size_t vertices);

    // Gets the number of vertices
    int vertices();

    // Gets the number of edges
    int edges();
private:
    size_t n;
    std::vector<std::set<int>> adj;
};