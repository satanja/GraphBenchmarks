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

void AdjSet::traverse()
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
            for (auto const &dest : adj[t])
            {
                if (!discovered[dest])
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