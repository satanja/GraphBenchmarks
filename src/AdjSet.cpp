#include "AdjSet.h"

AdjSet::AdjSet(size_t size)
{
    n = size;
    adj.resize(n);
}

void AdjSet::erase(int vertex)
{
    for (auto dest : adj[vertex])
    {
        adj[dest].erase(vertex);
    }
    adj[vertex].clear();
}

void AdjSet::insert_edge(int source, int dest)
{
    adj[source].insert(dest);
    adj[dest].insert(source);
}

void AdjSet::resize(size_t vertices)
{
    n = vertices;
    adj.resize(n);
}

int AdjSet::vertices()
{
    return n;
}