# About this project
In FPT kernelization algorithms, graphs are typically reduced vertex by vertex. This project included five generic implementations of graphs:
* an Adjacency Matrix,
* an Adjacency List,
* an Adjacency Matrix List,
* an Adjacency Binary Search Tree,
* and finally an Adjacency Hash Set.

Using the [public vertex cover instances from PACE](https://pacechallenge.org/2019/vc/vc_exact/), this program outputs the time spent on:
* loading the graph,
* traversing the graph from vertex 1 with a BFS,
* deleting the graph using a fixed arbitrary order per graph.

# Notes
* Memory consumption is HIGH. It is recommended to have at least 12 GB free at all times. In particular the Adjacency Matrix List has a very high memory  footprint.
* Relative file paths for windows have been used, i.e. using ``\\``. Change accordingly for building under Linux / MacOS.
