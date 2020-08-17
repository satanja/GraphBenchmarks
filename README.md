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
* Memory consumption is HIGH. It is recommended to have at least 12 GB free at all times. The Adjacency Matrix and Adjacency Matrix List have an obvious large memory footprint...
* Relative file paths for windows have been used, i.e. using ``\\``. Change accordingly for building under Linux / MacOS.

# Results
The most efficient data structure is the Adjancecy List. While it is obviously the fastest data structure for insertion and traversal, deletion also proved to be the fastest given the inputs, disregarding the Adjacency Matrix (variant). To delete vertices, we obviously need to search the vertex in the appropriate destination, for which `std::find` was used. This function proved to be faster than a manual linear search, and outperforms even a search in a BST or Hash Set. 

The Adjacency Matrix (variant) require too much memory and are therefore too impracticle for large graphs. The normal Adjancecy Matrix is less efficient than the Adjacency Matrix List in terms of traversal and deletion, since we check all O(|V|) vertices, while the latter only requires O(N), where N is the number of original neighbours. The Adjacency Matrix List did have insanely fast deletions, but is in the whole picture not the most efficient.
