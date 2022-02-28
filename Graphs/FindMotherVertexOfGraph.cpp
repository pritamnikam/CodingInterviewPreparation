/*
Find a "Mother Vertex" in a Graph

Problem Statement #
You have to implement the int findMotherVertex(Graph g) function which will take a graph as input and find out a mother vertex in the graph.

By definition, the mother vertex is one from which all other vertices are reachable.

Input #
A directed graph

Output #
Returns the value of the mother vertex if it exists. Otherwise, it returns -1.

Coding Exercise #
Take a close look and design a step-by-step algorithm first before jumping to the implementation.

Remember, the mother vertex is not directly connected to every vertex, but can reach it through a path traversal. Hence, there can be multiple mother vertices, but you need to find any one mother vertex for this challenge.

If you get stuck, you can always refer to the solution provided in the solution section. Good Luck!

Solution 1:
This is the brute force approach for solving this problem. We run a DFS on each vertex using DFS and keep track of the number of vertices visited in the search. If it is equal to g.vertices, then that vertex can reach all the vertices and is, hence, a mother vertex.

The algorithm would also work with a BFS using a queue.

Time Complexity #
Since we run a DFS on each node, the time complexity is O(V(V + E))


*/



#include <vector>
#include <list>

using namespace std;

struct Graph {
    int vertices;
    vector<list<int>>  adjLists;
};

int DFS(Graph& g, int u, vector<bool>& visited) {
    int count = 0;
    if (!visited[u]) {
        visited[u] = true;
        for (int v : g.adjLists[u]) {
            if (!visited[v])
                count += DFS(g, v, visited);
        }

        ++count;
    }

    return count;
}


int DFS(Graph& g, int u) {
    vector<bool> visited(g.vertices, false);
    return DFS(g, u, visited);
}

//Traverse the Graph Array and perform DFS operation on each vertex
//The vertex whose DFS Traversal results is equal to the total number
//of vertices in graph is a mother vertex
int findMotherVertex(Graph& g) {
    for (int i = 0; i < g.vertices; ++i) {
        if (DFS(g, i) == g.vertices)
            return i;
    }
    return -1;
}


/*
This solution is based in Kosaraju’s Strongly Connected Component Algorithm. Initially, we run the DFS on the whole graph in a loop (line 11). The DFS ensures that all the nodes in the graph are visited. If the graph is disconnected, the visited array will still have some vertices which haven’t been set to true.

The theory is that the last vertex visited in the recursive DFS will be the mother vertex. This is because, at the last vertex, all slots in visited would be true (DFS only stops when all nodes are visited). Hence, we keep track of this last vertex using lastV.

Then, we reset the visited array and run the DFS only on lastV. If it visits all nodes, it is a mother vertex. Otherwise, a mother vertex does not exist. The only limitation in this algorithm is that it can only detect one mother vertex, even if others exist.

Time Complexity #
The DFS of the whole graph works in O(V + E)O(V+E). If a mother vertex exists, the second DFS takes O(V + E)O(V+E) as well. Therefore, the complete time complexity for this algorithm is O(V + E)O(V+E).
*/