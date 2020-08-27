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

void AdjMatrix::traverse()
{
    int components = 0;
    std::vector<bool> discovered(n);
    for (int i = 0; i < n; i++)
    {
        if (discovered[i]) continue;
        std::queue<int> q;
        int source = i;

        q.push(source);
        discovered[source] = true;

        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if (adj[t][i] && !discovered[i])
                {
                    q.push(i);
                    discovered[i] = true;
                }
            }
        }
        components++;
    }
    std::cout << "connected components: " << components << std::endl;
}