#include "AdjForwardList.h"

AdjForwardList::AdjForwardList(size_t size)
{
    n = size;
    adj.resize(n);
}

void AdjForwardList::erase(int vertex)
{
    for (int dest : adj[vertex])
    {
        adj[dest].remove(vertex);
    }
    adj[vertex].clear();
}

void AdjForwardList::insert_edge(int source, int dest)
{
    adj[source].push_front(dest);
    adj[dest].push_front(source);
}

void AdjForwardList::resize(size_t vertices)
{
    n = vertices;
    adj.resize(vertices, std::forward_list<int>(0));
}

int AdjForwardList::vertices()
{
    return n;
}

void AdjForwardList::traverse()
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