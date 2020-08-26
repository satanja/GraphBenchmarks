#include "AdjVec.h"

AdjVec::AdjVec(size_t size)
{
    n = size;
    adj.resize(n);
}

void AdjVec::erase(int vertex)
{
    for (int dest : adj[vertex])
    {
       auto loc = std::find(adj[dest].begin(), adj[dest].end(), vertex);
       adj[dest].erase(loc);
    }
    adj[vertex].clear();
}

void AdjVec::insert_edge(int source, int dest)
{
    adj[source].push_back(dest);
    adj[dest].push_back(source);
}

void AdjVec::resize(size_t vertices)
{
    n = vertices;
    adj.resize(vertices, std::vector<int>(0));
}

int AdjVec::vertices()
{
    return n;
}

void AdjVec::traverse()
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
        for (auto const &dest : adj[t])
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