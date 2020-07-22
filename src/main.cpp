#include "Graph.h"

int main()
{   
    Graph g(4);
    g.insert_edge(0, 1);
    g.insert_edge(1, 2);
    g.insert_edge(2, 3);
    g.insert_edge(3, 0);
    g.erase(1);
    return 0;
}