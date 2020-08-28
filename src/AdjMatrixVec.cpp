#include "AdjMatrixVec.h"

AdjMatrixVec::AdjMatrixVec(size_t size)
{
    n = size;
    adj.resize(n, std::vector<bool>(n));
    adj_edges.resize(n, std::vector<int>());
}

void AdjMatrixVec::erase(int vertex)
{
    for (auto dest : adj_edges[vertex])
    {
        adj[dest][vertex] = false;
        adj[vertex][dest] = false;
    }
}

void AdjMatrixVec::insert_edge(int source, int dest)
{
    adj[source][dest] = true;
    adj_edges[source].push_back(dest);

    adj[dest][source] = true;
    adj_edges[dest].push_back(source);
}

void AdjMatrixVec::resize(size_t vertices)
{
    n = vertices;
    adj.resize(n, std::vector<bool>(n));
    adj_edges.resize(n, std::vector<int>());
}

int AdjMatrixVec::vertices()
{
    return n;
}

void AdjMatrixVec::traverse()
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
            for (auto const& dest : adj_edges[t])
            {
                if (adj[t][dest] && !discovered[dest])
                {
                    q.push(dest);
                    discovered[dest] = true;
                }
            }
        }
        components++;
    }
    std::cout << "connected components: " << components << std::endl;
}