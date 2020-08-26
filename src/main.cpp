#include "Graph.h"
#include "AdjDeque.h"
#include "AdjForwardList.h"
#include "AdjHash.h"
#include "AdjList.h"
#include "AdjVec.h"
#include "AdjMatrix.h"
#include "AdjMatrixVec.h"
#include "AdjSet.h"

#include <memory>
#include <chrono>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>

#include <cstdlib>

#include <queue>

void buildDeleteOrder(int vertices, std::vector<int> &del_order)
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

void buildGraph(std::shared_ptr<Graph> g, std::string &path)
{
    std::ifstream file{path};

    std::string word;
    file >> word;
    file >> word;

    int vertices;
    file >> vertices;
    g->resize(vertices);

    int edges;
    file >> edges;

    for (int i = 0; i < edges; i++)
    {
        int source;
        int dest;
        file >> source >> dest;
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

void traverseGraph(std::shared_ptr<Graph> g)
{
    g->traverse();
}

int main()
{
    for (int i = 1; i <= 8; i++)
    {
        std::ofstream output;
        std::ostringstream oss;
        oss << "out\\graph" << i << ".csv";
        std::string path = oss.str();
        output.open(path);
        output << "graph,loading,traversing,deleting\n";

        std::shared_ptr<Graph> g;
        for (int j = 1; j <= 200; j++)
        {
            // BAD ALLOC...
            if (i == 4 && (j == 110 || j == 161))
            {
                output << "-,-,-,-\n";
                continue;
            }
            switch (i)
            {
            case 1:
                g = std::make_shared<AdjHash>();
                break;
            case 2:
                g = std::make_shared<AdjVec>();
                break;
            case 3:
                g = std::make_shared<AdjMatrix>();
                break;
            case 4:
                g = std::make_shared<AdjMatrixVec>();
                break;
            case 5:
                g = std::make_shared<AdjSet>();
                break;
            case 6:
                g = std::make_shared<AdjForwardList>();
                break;
            case 7:
                g = std::make_shared<AdjDeque>();
                break;
            case 8:
                g = std::make_shared<AdjList>();
                break;
            }

            std::ostringstream inFile;

            inFile << "graphs\\vc-exact_";
            inFile << std::setfill('0') << std::setw(3) << j;
            inFile << ".gr";
            std::string path = inFile.str();
            std::cout << path << "\n";

            auto build_start = std::chrono::high_resolution_clock::now();
            buildGraph(g, path);
            auto build_end = std::chrono::high_resolution_clock::now();

            auto traverse_start = std::chrono::high_resolution_clock::now();
            traverseGraph(g);
            auto traverse_end = std::chrono::high_resolution_clock::now();

            std::vector<int> del_order;
            buildDeleteOrder(g->vertices(), del_order);

            auto del_start = std::chrono::high_resolution_clock::now();
            reduceGraph(g, del_order);
            auto del_end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> build_diff = build_end - build_start;
            std::chrono::duration<double> traverse_diff = traverse_end - traverse_start;
            std::chrono::duration<double> del_diff = del_end - del_start;

            output << j << ",";
            output << build_diff.count() << ",";
            output << traverse_diff.count() << ",";
            output << del_diff.count() << "\n";
            output.flush();
        }
        output.close();
    }
    
    return 0;
}