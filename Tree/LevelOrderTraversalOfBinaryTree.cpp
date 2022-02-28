/*

Level Order Traversal of Binary Tree

Given the root of a binary tree, display the node values at each level.

Description #
Given the root of a binary tree, display the node values at each level. 
Node values for all levels should be displayed on separate lines. 

Hints #
You can use Breadth-first traversal.
Try it yourself#
The BinaryTreeNode class has members left and right along with the variable data.

	

*/




using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

//  Definition for a binary tree node.
struct BinaryTreeNode {
    int data;
    BinaryTreeNode* parent;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode() : data(0), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int x, BinaryTreeNode* left, BinaryTreeNode* right) : data(x), left(left), right(right) {}
};

string level_order_traversal(BinaryTreeNode* root) {
	string result = "";
    queue<BinaryTreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        int size = queue.size();

        for (int i = 0; i < size; ++i) {
            BinaryTreeNode* front = queue.front();
            queue.pop();

            if (front->left != nullptr) {
                queue.push(front->left);
            }

            if (front->right != nullptr) {
                queue.push(front->right);
            }

            result += front->data;
        }
    }

	return result;
}