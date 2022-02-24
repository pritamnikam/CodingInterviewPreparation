/*
Right View of a Binary Tree

Given a binary tree, return an array containing nodes in its right view. 
The right view of a binary tree is the set of nodes visible when the tree is seen from the right side.


Solution#
This problem follows the Binary Tree Level Order Traversal pattern. 
We can follow the same BFS approach. 

The only additional thing we will be doing is to append the last node of each level to the result array.

Time complexity#
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. 
This is due to the fact that we traverse each node once.

Space complexity#
The space complexity of the above algorithm will be O(N) needed for the return list. 
We will also need O(N) space for the queue. 

Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level), 
therefore we will need O(N) space to store them in the queue.


Similar Questions#
Problem 1: Given a binary tree, return an array containing nodes in its left view. 
The left view of a binary tree is the set of nodes visible when the tree is seen from the left side.

Solution: We will be following a similar approach, but instead of appending the last element of each level, 
we will be appending the first element of each level to the output array.


*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

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

class RightViewTree {
public:
    static vector<TreeNode*> traverse(TreeNode* root) {
        vector<TreeNode*> result;
        // TODO: Write your code here

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left) {
                    q.push(current->left);
                }

                if (current->right) {
                    q.push(current->right);
                }

                if (i == levelSize - 1) {
                    result.emplace_back(current);
                }
            }
        }
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
    root->left->left->left = new TreeNode(3);
    vector<TreeNode*> result = RightViewTree::traverse(root);
    for (auto node : result) {
        cout << node->val << " ";
    }
}