#include "AdjMatrixVec.h"

AdjMatrixVec::AdjMatrixVec(size_t size)
{
    n = size;
    adj.resize(n, std::pair(std::vector<int>(n), std::vector<int>()));
}

void AdjMatrixVec::erase(int vertex)
{
    for (auto dest : adj[vertex].second)
    {
        adj[dest].first[vertex] = 0;
        adj[vertex].first[dest] = 0;
    }
}

void AdjMatrixVec::insert_edge(int source, int dest)
{
    adj[source].first[dest] = true;
    adj[source].second.push_back(dest);

    adj[dest].first[source] = true;
    adj[dest].second.push_back(source);
}

void AdjMatrixVec::resize(size_t vertices)
{
    n = vertices;
    adj.resize(n, std::pair(std::vector<int>(n), std::vector<int>())); 
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
            for (auto const& dest : adj[t].second)
            {
                if (adj[t].first[dest] && !discovered[dest])
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