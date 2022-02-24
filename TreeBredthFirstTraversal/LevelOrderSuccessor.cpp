/*
Level Order Successor

Problem Statement#
Given a binary tree and a node, find the level order successor of the given node in the tree. 
The level order successor is the node that appears right after the given node in the level order traversal.

Solution#
This problem follows the Binary Tree Level Order Traversal pattern. We can follow the same BFS approach. 

The only difference will be that we will not keep track of all the levels. Instead we will keep inserting child nodes to the queue. 
As soon as we find the given node, we will return the next node from the queue as the level order successor.

Time complexity#
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. 
This is due to the fact that we traverse each node once.

Space complexity#
The space complexity of the above algorithm will be O(N) which is required for the queue. 
Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level), 
therefore we will need O(N)O(N) space to store them in the queue.

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

class LevelOrderSuccessor {
public:
    static TreeNode* findSuccessor(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;

        // TODO: Write your code here

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* u = q.front();
            q.pop();

            if (u->left != nullptr)
                q.push(u->left);

            if (u->right != nullptr)
                q.push(u->right);

            if (u->val == key)
                break;
        }

        return q.front();
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    TreeNode* result = LevelOrderSuccessor::findSuccessor(root, 12);
    if (result != nullptr) {
        cout << result->val << " " << endl;
    }
    result = LevelOrderSuccessor::findSuccessor(root, 9);
    if (result != nullptr) {
        cout << result->val << " " << endl;
    }
}