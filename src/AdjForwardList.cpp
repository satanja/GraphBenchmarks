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