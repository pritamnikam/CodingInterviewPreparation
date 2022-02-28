/*
Clone a Directed Graph

Given the root node of a directed graph, clone this graph by creating its deep copy so that the cloned graph has the same vertices 
and edges as the original graph.

Description #
Given the root node of a directed graph, clone this graph by creating its deep copy so that the cloned graph has the same vertices and edges as the original graph.

Let’s look at the below graphs as an example. If the input graph is G = (V, E)G=(V,E) where VV is set of vertices and EE is set of edges, then the output graph (cloned graph) G' = (V', E')G
​′
​​ =(V
​′
​​ ,E
​′
​​ ) such that V = V'V=V
​′
​​  and E = E'E=E
​′
​​ .

We are assuming that all vertices are reachable from the root vertex. i.e. we have a connected graph.

Original Graph
0
2
3
4
1
Cloned Graph
0'
2'
3'
4'
1'
Hints #
Use hash tables.
Use depth-first traversal.

Solution #
Runtime complexity #
The runtime complexity of this solution is linear, O(n)O(n).

Memory complexity #
The memory complexity of this solution is linear, O(n)O(n). nn is the number of vertices in the graph.

We can have most n entries in hash table, so the worst-case space complexity is O(n).

We use depth-first traversal and create a copy of each node while traversing the graph. To avoid getting stuck in cycles, we’ll use a hashtable to store each completed node and will not revisit nodes that exist in the hashtable. The hashtable key will be a node in the original graph, and its value will be the corresponding node in cloned graph.

For above graph lets assume root is node 00. We’ll start with the root node i.e. 00.


*/

/* struct Node {
  int data;
  list<Node*> neighbors;
  Node(int d) : data(d) {}
}; */

Node* clone_rec(Node* root, unordered_map<Node*, Node*>& nodes_completed) {

    if (root == nullptr) {
        return nullptr;
    }

    Node* pNew = new Node(root->data);
    nodes_completed[root] = pNew;

    for (Node* p : root->neighbors) {

        auto x = nodes_completed.find(p);

        if (x == nodes_completed.end()) {
            pNew->neighbors.push_back(clone_rec(p, nodes_completed));
        }
        else {
            pNew->neighbors.push_back(x->second /*value*/);
        }
    }

    return pNew;
}

Node* clone(Node* root) {
    unordered_map<Node*, Node*> nodes_completed;
    return clone_rec(root, nodes_completed);
}

int main() {
    vector<Node*> vertices;
    create_test_graph_directed(7, 18, vertices);

    print_graph(vertices[0]);

    Node* cp = clone(vertices[0]);
    cout << endl << "After copy" << endl;
    print_graph(cp);

    return 0;
}