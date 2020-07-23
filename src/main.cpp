#include "Graph.h"
#include "AdjHash.h"
#include "AdjList.h"
#include "AdjMatrix.h"
#include "AdjSet.h"

#include <memory>
#include <chrono>

#include <iostream>

void buildGraph(std::shared_ptr<Graph> g)
{
    std::string word;
    std::cin >> word;
    std::cin >> word;
    
    int vertices;
    std::cin >> vertices;
    g->resize(vertices);

    int edges;
    std::cin >> edges;
    
    for (int i = 0; i < edges; i++)
    {
        int source;
        int dest;
        std::cin >> source >> dest;
        g->insert_edge(source - 1, dest - 1);
    }
}

void reduceGraph(std::shared_ptr<Graph> g)
{

}

void traverseGraph(std::shared_ptr<Graph> g)
{

}

int main()
{   
    auto g1 = std::make_shared<AdjHash>();
    buildGraph(g1);
    
    auto g2 = std::make_shared<AdjList>();
    buildGraph(g2);

    auto g3 = std::make_shared<AdjMatrix>();
    buildGraph(g3);

    auto g4 = std::make_shared<AdjSet>();
    buildGraph(g4);

    return 0;
}