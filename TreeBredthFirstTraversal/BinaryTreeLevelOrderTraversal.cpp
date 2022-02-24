/*
Binary Tree Level Order Traversal

Problem Statement#
Given a binary tree, populate an array to represent its level-by-level traversal. 
You should populate the values of all nodes of each level from left to right in separate sub-arrays.

Solution#
Since we need to traverse all nodes of each level before moving onto the next level, we can use the Breadth First Search (BFS) technique to solve this problem.

We can use a Queue to efficiently traverse in BFS fashion. Here are the steps of our algorithm:

Start by pushing the root node to the queue.
Keep iterating until the queue is empty.
In each iteration, first count the elements in the queue (let’s call it levelSize). We will have these many nodes in the current level.
Next, remove levelSize nodes from the queue and push their value in an array to represent the current level.
After removing each node from the queue, insert both of its children into the queue.
If the queue is not empty, repeat from step 3 for the next level.

Time complexity#
The time complexity of the above algorithm is O(N)O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity#
The space complexity of the above algorithm will be O(N)O(N) as we need to return a list containing the level order traversal. We will also need O(N)O(N) space for the queue. Since we can have a maximum of N/2N/2 nodes at any level (this could happen only at the lowest level), therefore we will need O(N)O(N) space to store them in the queue.


*/


using namespace std;

#include <iostream>
#include <queue>

class TreeNode {
public:
    int val = 0;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class LevelOrderTraversal {
public:
    static vector<vector<int>> traverse(TreeNode* root) {
        vector<vector<int>> result;
        // TODO: Write your code here

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vt;
            while (size) {
                TreeNode* u = q.front();
                q.pop();

                vt.emplace_back(u->val);

                if (u->left != nullptr) {
                    q.push(u->left);
                }

                if (u->right != nullptr) {
                    q.push(u->right);
                }

                --size;
            } // while-size

            result.emplace_back(vt);
        } // while-q
        return result;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    vector<vector<int>> result = LevelOrderTraversal::traverse(root);
    cout << "Level order traversal: ";
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}