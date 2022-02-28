/*
Detect Cycle in Graph

The solution might look confusing at first, but the logic behind it is pretty straight forward.

For each node, we start a recursive call with detectCycleRec. The function maintains a stack (not to be confused with the stack data structure) of nodes called recNodes along with a visited array.

The vertices that have been traversed in the current recursion are added to recNodes and visited keeps a record of all the nodes that have been traversed regardless of the recursive call.

For a cycle to occur, we must reach a node that was already present in the recursion stack. If the recursion ends and no such node is found, the stack is reset again and the next iteration of detectCycle starts.

Time Complexity #
O(V+E), which we already know is the complexity of traversing the adjacency list that represents our graph.


*/


#include <vector>
#include <list>

using namespace std;

struct Graph {
    int vertices;
    vector<list<int>>  adjLists;
};

bool detectCycle(Graph& g, int u, vector<bool>& visited, vector<bool>& recStack) {
    if (!visited[u]) {
        visited[u] = true;
        recStack[u] = true;

        for (int v : g.adjLists[u]) {
            if (!visited[v] && detectCycle(g, v, visited, recStack)) {
                return true;
            }
            else if (recStack[v]) {
                return true;
            }
        }
    }

    recStack[u] = false;
    return false;
}

bool detectCycle(Graph g) {

    vector<bool> visited(g.vertices, false);
    vector<bool> recStack(g.vertices, false);
    for (int i = 0; i < g.vertices; ++i) {
        if (detectCycle(g, i, visited, recStack))
            return true;
    }
    return false;
}