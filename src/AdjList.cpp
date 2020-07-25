#include "AdjList.h"

AdjList::AdjList(size_t size)
{
    n = size;
    adj.resize(n);
}

void AdjList::erase(int vertex)
{
    for (int dest : adj[vertex])
    {
       auto loc = std::find(adj[dest].begin(), adj[dest].end(), vertex);
       adj[dest].erase(loc);
    }
    adj[vertex].clear();
}

void AdjList::insert_edge(int source, int dest)
{
    adj[source].push_back(dest);
    adj[dest].push_back(source);
}

void AdjList::resize(size_t vertices)
{
    n = vertices;
    adj.resize(vertices, std::vector<int>(0));
}

int AdjList::vertices()
{
    return n;
}