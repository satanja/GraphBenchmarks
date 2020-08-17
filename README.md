# About this project
In FPT kernelization algorithms, graphs are typically reduced vertex by vertex. This project included four generic implementations of graphs:
* an Adjacency Matrix,
* an Adjacency List,
* an Adjacency Binary Search Tree,
* and finally an Adjacency Hash Set.

Using the [public vertex cover instances from PACE](https://pacechallenge.org/2019/vc/vc_exact/), this program outputs the time spent on:
* loading the graph,
* traversing the graph from vertex 1 with a BFS,
* deleting the graph using a fixed arbitrary order per graph.

# Notes
This project is built using CMake, and relative paths inside the code are windows specific