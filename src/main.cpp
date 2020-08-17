#include "Graph.h"
#include "AdjHash.h"
#include "AdjList.h"
#include "AdjMatrix.h"
#include "AdjMatrixList.h"
#include "AdjSet.h"

#include <memory>
#include <chrono>

#include <iostream>

#include <cstdlib>

void buildDeleteOrder(int vertices, std::vector<int>& del_order)
{
    std::srand(1); // fixed seed
    std::vector<int> queue;
    queue.resize(vertices);
    del_order.resize(vertices);
    for (int i = 0; i < vertices; i++)
    {
        queue[i] = i;
    }
    
    int i = 0;
    while (!queue.empty())
    {
        int index = std::rand() % queue.size();
        int vertex = *(queue.begin() + index);
        queue.erase(queue.begin() + index);
        del_order[i] = vertex;
        i++;
    }
}

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

void reduceGraph(std::shared_ptr<Graph> g, std::vector<int> del_order)
{
    for (int i = 0; i < del_order.size(); i++)
    {
        g->erase(del_order[i]);
    }
}

// BFS from vertex 0 to vertex n - 1
void traverseGraph(std::shared_ptr<Graph> g)
{

}

int main()
{   
    auto build_start = std::chrono::high_resolution_clock::now();
    auto g1 = std::make_shared<AdjMatrixList>();
    buildGraph(g1);
    auto build_end = std::chrono::high_resolution_clock::now();
    
    std::vector<int> del_order;
    buildDeleteOrder(g1->vertices(), del_order);

    auto del_start = std::chrono::high_resolution_clock::now();
    reduceGraph(g1, del_order);
    auto del_end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> build_diff = build_end - build_start;
    std::chrono::duration<double> del_diff = del_end - del_start;
    
    std::cout << "building graph: " << build_diff.count() << " s\n";
    std::cout << "deleting graph: " << del_diff.count() << " s\n";

    return 0;
}