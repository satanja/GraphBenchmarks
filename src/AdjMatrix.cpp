#include "AdjMatrix.h"

AdjMatrix::AdjMatrix(size_t size)
{
    n = size;
    adj.resize(n, std::vector<bool>(n));
}

void AdjMatrix::erase(int vertex)
{
    for (int i = 0; i < n; i++)
    {
        if (adj[vertex][i])
        {
            adj[vertex][i] = false; 
            adj[i][vertex] = false;
        }
    }
}

void AdjMatrix::insert_edge(int source, int dest)
{
    adj[source][dest] = true;
    adj[dest][source] = true;
}

void AdjMatrix::resize(size_t vertices)
{
    n = vertices;
    adj.resize(n, std::vector<bool>(n));
}

int AdjMatrix::vertices()
{
    return n;
}