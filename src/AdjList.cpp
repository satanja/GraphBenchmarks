#include "AdjList.h"

AdjList::AdjList(size_t size)
{
    n = size;
    adj.resize(n);
}

void AdjList::erase(int vertex)
{
    for (int dest : adj[vertex])
    {
       auto loc = std::find(adj[dest].begin(), adj[dest].end(), vertex);
       adj[dest].erase(loc);
    }
    adj[vertex].clear();
}

void AdjList::insert_edge(int source, int dest)
{
    adj[source].push_back(dest);
    adj[dest].push_back(source);
}

void AdjList::resize(size_t vertices)
{
    n = vertices;
    adj.resize(vertices, std::list<int>(0));
}

int AdjList::vertices()
{
    return n;
}

void AdjList::traverse()
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