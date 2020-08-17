#include "AdjMatrixList.h"

AdjMatrixList::AdjMatrixList(size_t size)
{
    n = size;
    adj.resize(n, std::pair(std::vector<int>(n), std::vector<int>()));
}

void AdjMatrixList::erase(int vertex)
{
    for (auto dest : adj[vertex].second)
    {
        adj[dest].first[vertex] = 0;
        adj[vertex].first[dest] = 0;
    }
}

void AdjMatrixList::insert_edge(int source, int dest)
{
    adj[source].first[dest] = true;
    adj[source].second.push_back(dest);

    adj[dest].first[source] = true;
    adj[dest].second.push_back(source);
}

void AdjMatrixList::resize(size_t vertices)
{
    n = vertices;
    adj.resize(n, std::pair(std::vector<int>(n), std::vector<int>())); 
}

int AdjMatrixList::vertices()
{
    return n;
}

std::vector<int> AdjMatrixList::edges(int source)
{
    std::vector<int> edges;
    for (auto dest : adj[source].second)
    {
        if (adj[source].first[dest])
        {
            edges.push_back(dest);
        }
    }
    return edges;
}