#include "Graph.h"

Graph::Graph()
{
    n = 0;
}

Graph::Graph(size_t vertices)
{
    n = vertices;
    adj.resize(vertices);
}

void Graph::erase(int vertex)
{
    if (vertex < 0 || vertex >= n) return;
    
    adj[vertex].clear();
    for (int i = 0; i < n; i++)
    {
        if (i != vertex)
        {
            adj[i].erase(vertex);
        }
    }
}

void Graph::insert_edge(int source, int dest)
{
    if (source < 0 || source >= n) return;
    if (dest < 0 || dest >= n) return;
    adj[source].insert(dest);
    adj[dest].insert(source);
}

void Graph::resize(size_t vertices)
{
    n = vertices;
    adj.resize(vertices);
}

int Graph::vertices()
{
    return n;
}

int Graph::edges()
{
    // TODO implement
    return 0;
}