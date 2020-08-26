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
    int source = 0;

    std::queue<int> q;
    std::vector<bool> discovered(n);

    q.push(source);
    discovered[source] = true;

    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        for (auto const& dest : adj[t])
        {
            if (!discovered[dest])
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