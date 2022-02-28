/*

Find the Shortest Path between Two Vertices

We've dealt with several graph traversals. Now, we'll find the shortest path traversal between two vertices.

Problem Statement #
Implement the int findMin(Graph g, int source, int destination) function which will take a graph and two vertices, source and destination. The result will be the shortest path from source to destination.

Remember, the shortest path will contain the minimum number of edges.

Note: Shortest distance between the same source and destination vertex will be 0.

Note: Your program should return -1 if either source or destination node does not exist.

Input #
A directed graph, a source vertex, and a destination vertex.

Output #
Returns number of edges in the shortest path between source and destination.


Coding Exercise #
Take a close look and design a step-by-step algorithm first before jumping on to the implementation.

Think back to all the previous exercises. You’ll surely find several hints on how to implement this.

If you get stuck, you can always refer to the solution provided in the next lesson. Good luck!




Once again, Breadth First Search comes to the rescue. The visited array must be familiar to you by now. The crux of this algorithm, however, lies in the distance array. For each node, the indexed value in distance shows the node’s distance from source in terms of the number of edges.

The rest is a simple BFS traversal where the distance is incremented by 1 each time.

We are guaranteed to find the shortest distance to destination because, once it has been visited, it won’t be visited again through the longer path, as it has already been marked.

Time Complexity #
The algorithm will have the same time complexity as BFS: O(V + E)


*/


#include <vector>
#include <list>
#include <queue>

using namespace std;

struct Graph {
	int vertices;
	vector<list<int>>  adjLists;
};

int findMin(Graph g, int source, int destination) {
	if (source == destination)
		return 0;

	vector<bool> visited(g.vertices, false);
	vector<int> distance(g.vertices, 0);
	queue<int> queue;

	queue.push(source);
	visited[source] = true;

	// Traverse while queue is not empty
	while (!queue.empty()) {
		//Dequeue a vertex/node from queue and add it to result
		int u = queue.front();
		queue.pop();

		//Get adjacent vertices to the current_node from the array,
		//and if they are not already visited then enqueue them in the Queue
		//and also update their distance from source by adding 1 in current_nodes's distance
		for (int v : g.adjLists[u]) {
			if (!visited[v]) {
				visited[v] = true;
				queue.push(v);
				distance[v] = distance[u] + 1;
			}

			if (v == destination) {
				return distance[v];
			}
		}
	}

	return -1;
}