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
    int source = 0;

    std::queue<int> q;
    std::vector<bool> discovered(n);

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

    int count = 0;
    for (int i = 0; i < discovered.size(); i++)
    {
        count += 1 * discovered[i];
    }

    std::cout << "vertices reachable: " << count << std::endl;
}