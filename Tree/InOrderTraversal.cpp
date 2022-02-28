/*
Write an In-Order Iterator for a Binary Tree

Implement a class that implements an in-order iterator on a Binary Tree.


Description #
We are given the root node of a binary tree. We have to write an iterator that takes in this root and iterates through the nodes of a binary tree in an in-order way. The expectation is to write two critical methods of any iterator: hasNext() and getNext().

Repeatedly calling hasNext() and getNext() functions on the above binary tree should return nodes in the following sequence: 25, 50, 75, 100, 125, 200, 300.25,50,75,100,125,200,300.

Hints #
How would you perform an in-order traversal iteratively.

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

class InorderIterator {
	stack<TreeNode*> stk;
public:
	InorderIterator(TreeNode* root) {
		generateIterations(root);
	}

	void generateIterations(TreeNode* root) {
		while (root) {
			stk.push(root);
			root = root->left;
		}
	}

	bool hasNext() {
		return !stk.empty();
	}

	TreeNode* getNext() {
		if (!hasNext()) return nullptr;

		TreeNode* top = stk.top();
		stk.pop();

		generateIterations(top->right);
		return top;
	}
};
