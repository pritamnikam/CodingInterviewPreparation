/*
Count the number of Edges in an Undirected Graph

In this lesson, we will figure out if it's possible to count the total number of edges in a graph.

Problem Statement #
You have to implement the int numEdges(Graph g) function which takes an undirected graph and computes the total number of bidirectional edges. An illustration is also provided for your understanding.

Input #
An undirected graph.

Output #
Returns the total number of edges in the graph.

Nothing too tricky going on here. We simply traverse through the complete adjacency list and count the size of each linked list. In an undirected graph, the number of edges is always even as the edges are bidirectional. Hence, to get the number of unique edges, we half the total sum.

Time complexity #
O(V + E)


*/



#include <vector>
#include <list>

using namespace std;

struct Graph {
    int vertices;
    vector<list<int>>  adjLists;
};



// For undirected graph, just sum up the size of
// all the adjacency lists for each vertex and then divide it by 2.
// It will give us total number of edges in the graph.
int numEdges(Graph g) {
    int count = 0;
    for (int i = 0; i < g.vertices; ++i) {
        count += g.adjLists[i].size();
    }
    return count / 2;
}