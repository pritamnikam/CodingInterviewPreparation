/*
Iterative In-Order Traversal of Binary Tree

Write an in-order traversal of a binary tree iteratively.

Description #
Given a binary tree, write an iterative algorithm to traverse the tree in-order. Let’s look at the tree below as an example.

In-order traversal of the above tree should visit the nodes in the following order: 25, 35, 50, 75, 100, 20025,35,50,75,100,200.

Hints#
You can use a stack data structure for the solution.
Your output should return the nodes values singly spaced in the appropriate data structure for the language of your choice.

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
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<int> inorder_iterative(TreeNode* root) {
	// TODO: Write - Your - Code
	vector<int> result;

	stack<TreeNode*> stk;
	while (!stk.empty() || root) {

		// keep push the left to stack until we reach the leaft
		if (root) {
			stk.push(root);
			root = root->left;
			continue;
		}

		// keep poping the element from stack
		TreeNode* top = stk.top();
		stk.pop();

		result.push_back(top->val);
		root = top->right;
	}
	return result;
}
