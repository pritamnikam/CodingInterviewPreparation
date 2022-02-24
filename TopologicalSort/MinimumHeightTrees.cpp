/*
Minimum Height Trees (hard)#

We are given an undirected graph that has characteristics of a k-ary tree. In such a graph, we can 
choose any node as the root to make a k-ary tree. 

The root (or the tree) with the minimum height will be called Minimum Height Tree (MHT). 
There can be multiple MHTs for a graph. 

In this problem, we need to find all those roots which give us MHTs. Write a method to find all MHTs of
the given graph and return a list of their roots.

Example 1:

Input: vertices: 5, Edges: [[0, 1], [1, 2], [1, 3], [2, 4]]
Output:[1, 2]
Explanation: Choosing '1' or '2' as roots give us MHTs. In the below diagram, we can see that the
height of the trees with roots '1' or '2' is three which is minimum.

Example 2:

Input: vertices: 4, Edges: [[0, 1], [0, 2], [2, 3]]
Output:[0, 2]
Explanation: Choosing '0' or '2' as roots give us MHTs. In the below diagram, we can see that the
height of the trees with roots '0' or '2' is three which is minimum.


Example 3:

Input: vertices: 4, Edges: [[0, 1], [1, 2], [1, 3]]
Output:[1]

Solution#
From the above-mentioned examples, we can clearly see that any leaf node (i.e., node with only one edge) can never give us an MHT because its adjacent non-leaf nodes will always give an MHT with a smaller height. All the adjacent non-leaf nodes will consider the leaf node as a subtree. Let’s understand this with another example. Suppose we have a tree with root ‘M’ and height ‘5’. Now, if we take another node, say ‘P’, and make the ‘M’ tree as its subtree, then the height of the overall tree with root ‘P’ will be ‘6’ (=5+1). Now, this whole tree can be considered a graph, where ‘P’ is a leaf as it has only one edge (connection with ‘M’). This clearly shows that the leaf node (‘P’) gives us a tree of height ‘6’ whereas its adjacent non-leaf node (‘M’) gives us a tree with smaller height ‘5’ - since ‘P’ will be a child of ‘M’.

This gives us a strategy to find MHTs. Since leaves can’t give us MHT, we can remove them from the graph and remove their edges too. Once we remove the leaves, we will have new leaves. Since these new leaves can’t give us MHT, we will repeat the process and remove them from the graph too. We will prune the leaves until we are left with one or two nodes which will be our answer and the roots for MHTs.

We can implement the above process using the topological sort. Any node with only one edge (i.e., a leaf) can be our source and, in a stepwise fashion, we can remove all sources from the graph to find new sources. We will repeat this process until we are left with one or two nodes in the graph, which will be our answer.


*/

using namespace std;

#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class MinimumHeightTrees {
public:
    static vector<int> findTrees(int nodes, vector<vector<int>>& edges) {
        vector<int> minHeightTrees;
        if (nodes <= 0) {
            return minHeightTrees;
        }

        // with only one node, since its in-degree will be 0, therefore, we need to handle it separately
        if (nodes == 1) {
            minHeightTrees.push_back(0);
            return minHeightTrees;
        }

        // a. Initialize the graph
        unordered_map<int, int> inDegree;       // count of incoming edges for every vertex
        unordered_map<int, vector<int>> graph;  // adjacency list graph
        for (int i = 0; i < nodes; i++) {
            inDegree[i] = 0;
            graph[i] = vector<int>();
        }

        // b. Build the graph
        for (int i = 0; i < edges.size(); i++) {
            int n1 = edges[i][0], n2 = edges[i][1];
            // since this is an undirected graph, therefore, add a link for both the nodes
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
            // increment the in-degrees of both the nodes
            inDegree[n1]++;
            inDegree[n2]++;
        }

        // c. Find all leaves i.e., all nodes with only 1 in-degree
        deque<int> leaves;
        for (auto entry : inDegree) {
            if (entry.second == 1) {
                leaves.push_back(entry.first);
            }
        }

        // d. Remove leaves level by level and subtract each leave's children's in-degrees.
        // Repeat this until we are left with 1 or 2 nodes, which will be our answer.
        // Any node that has already been a leaf cannot be the root of a minimum height tree, because
        // its adjacent non-leaf node will always be a better candidate.
        int totalNodes = nodes;
        while (totalNodes > 2) {
            int leavesSize = leaves.size();
            totalNodes -= leavesSize;
            for (int i = 0; i < leavesSize; i++) {
                int vertex = leaves.front();
                leaves.pop_front();
                vector<int> children = graph[vertex];
                for (auto child : children) {
                    inDegree[child]--;
                    if (inDegree[child] == 1) {  // if the child has become a leaf
                        leaves.push_back(child);
                    }
                }
            }
        }

        std::move(std::begin(leaves), std::end(leaves), std::back_inserter(minHeightTrees));
        return minHeightTrees;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> vec = { {0, 1}, {1, 2}, {1, 3}, {2, 4} };
    vector<int> result = MinimumHeightTrees::findTrees(5, vec);
    cout << "Roots of MHTs: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    vec = { {0, 1}, {0, 2}, {2, 3} };
    result = MinimumHeightTrees::findTrees(4, vec);
    cout << "Roots of MHTs: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    vec = { {0, 1}, {1, 2}, {1, 3} };
    result = MinimumHeightTrees::findTrees(4, vec);
    cout << "Roots of MHTs: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
}