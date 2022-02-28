/*
Check if a Path Exists Between Two Vertices

Given a graph and two vertices, can you write a code to check if a path exists between the two vertices?

Problem Statement #
You have to implement the bool checkPath(Graph g, int source, int destination) function. 
It takes a source, and a destination and tells us whether or not a path exists between the two (from the source to the destination).

If there is no repeated sequence of edges and vertices between the source and the destination vertex then the path exists between these two vertices.

Note: Path will always exist if the source and destination nodes are the same.

Input #
A graph, a source value and a destination value.

Output #
Returns true if a path exists from the source to the destination.

Coding Exercise #
Take a close look and design a step-by-step algorithm first before jumping to the implementation. This problem is designed for your practice, so try to solve it on your own first.

If you get stuck, you can always refer to the solution provided in the solution section. We will discuss the solution in the next lesson.

Good Luck!

This problem can be solved by both DFS and BFS. All we need is a simple traversal from source to see if we can reach destination. If the destination value is found, we return True.

Note that we only use the values in the vertices, not the vertices or the linked list objects themselves. This makes syntax easier.

Time Complexity #
It has the same time complexity as the BFS or DFS algorithm: O(V + E).


*/



#include <vector>
#include <list>

using namespace std;

struct Graph {
    int vertices;
    vector<list<int>>  adjLists;
};

bool checkPath(Graph& g, int source, int destination, vector<bool>& visited) {
    if (source == destination) return true;

    visited[source] = true;
    for (int v : g.adjLists[source]) {
        if (!visited[v] && checkPath(g, v, destination, visited))
            return true;
    }
    return false;
}

bool checkPath(Graph g, int source, int destination) {
    vector<bool> visited(g.vertices, false);
    return checkPath(g, source, destination, visited);
}