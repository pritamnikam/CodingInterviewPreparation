/*
Check if an Undirected Graph is Tree or not

Problem Statement #
The next section will tackle the tree data structure. For now, here’s the basic difference between a graph and a tree. A graph can only be a tree under two conditions:

There are no cycles.
The graph is connected.
A graph is connected when there is a path between every pair of vertices. In a connected graph, there are no unreachable vertices. Each vertex must be able to reach every other vertex through either a direct edge or through a graph traversal.

You have to implement bool isTree(Graph g) function which will take a graph as input and find out if it is a tree.

Input #
An undirected graph.

Output #
Returns true if the given graph is a tree. Otherwise, it returns false.

Coding Exercise #
Take a close look and design a step-by-step algorithm first before jumping on to the implementation.

The point of this exercise is to understand the difference between a tree and a graph. Other than that, the task is fairly easy.

If you get stuck, you can always refer to the solution provided in the solution section.

Good luck!

Note: Here we have given you the implementation of the undirected graph.


To check whether an undirected graph is a tree or not, we’ll check the following :
- There is no cycle in the graph.
- The graph is connected.

For an undirected graph, we can either use BFS or DFS to detect the above two conditions.

So we start from the source and visit every adjacent vertex using recursive calls if, during the recursion, 
we come across any vertex that has already been visited and is not the parent of the current vertex, then there is a cycle. 

If we do not find such an adjacent for any vertex, we say that there is no cycle.

Then we check for connectivity and traverse all the vertices on the graph to check if they have been visited in the recursive calls from the source. 
If we find any vertex that is not visited, we conclude that vertex is not reachable from the source. 

Therefore, the graph is not connected and, hence, is not a tree.

Time Complexity #
The graph is traversed in both functions. Hence, the time complexity is O(V + E).
*/



#include <vector>
#include <list>

using namespace std;

struct Graph {
	int vertices;
	vector<list<int>>  adjLists;
};


bool hasCycle(Graph& g, int u, vector<bool>& visited, int parent) {
	visited[u] = true;

	for (int v : g.adjLists[u]) {
		// If an adjacent is not visited, then make recursive call on the adjacent
		if (!visited[v]) {
			if (hasCycle(g, v, visited, u))
				return true;
		}

		//^ If an adjacent is visited and not parent of current
		// vertex, then there is a cycle.
		else if (v != parent) {
			return true;
		}
	}
	return false;
}


bool isTree(Graph g) {
	vector<bool> visited(g.vertices, false);

	for (int i = 0; i < g.vertices; ++i) {
		if (hasCycle(g, i, visited, -1)) {
			return false;
		}
	}

	for (int i = 0; i < g.vertices; ++i) {
		if (!visited[i])
			return false;
	}

	return true;
}