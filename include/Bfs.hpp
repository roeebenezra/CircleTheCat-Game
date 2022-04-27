#include<iostream>
#include <list>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s); // prints BFS traversal from a given source s

private:
    int m_V;    // No. of vertices
    // Pointer to an array containing adjacency
    list<int>* m_adj; // lists
};

