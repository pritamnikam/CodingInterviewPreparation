/*
Is a Binary Search Tree Valid?

Given a binary tree, figure out whether it's a BST.


Description #
Given a Binary Tree, figure out whether it’s a Binary Search Tree. In a binary search tree, each node’s key value is smaller than the key value of all nodes in the right subtree, and are greater than the key values of all nodes in the left subtree i.e. L < N < RL<N<R.

The binary tree given below is a valid BST.

Hints #
Use recursion.
You can implement the solution using in-order traversal.

Try it yourself#
The BinaryTreeNode class has members left and right along with the variable data.

Solution 1 #
Runtime complexity #
The runtime complexity of this solution is linear, O(n)O(n).

Memory complexity #
The memory complexity of this solution is linear, O(n)O(n).

Recursive solution has O(h)O(h) memory complexity as it will consume memory on the stack up to the height of binary tree h. It will be O(log n)O(logn) for a balanced tree and in the worst case can be O(n)O(n).

There are several ways of solving this problem. A basic algorithm would be to check on each node where the maximum value of its left sub-tree is less than the node’s data and the minimum value of its right sub-tree is greater than the node’s data. This is highly inefficient as for each node, both of its left and right sub-trees are explored.

Another approach would be to do a regular in-order traversal and in each recursive call, pass maximum and minimum bounds to check whether the current node’s value is within the given bounds. This approach is efficient compared to the one above.


*/


using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

bool is_bst_rec(BinaryTreeNode* root, int min_value, int max_value) {

    if (root == nullptr) {
        return true;
    }

    if (root->data < min_value ||
        root->data > max_value) {
        return false;
    }

    return is_bst_rec(root->left, min_value, root->data) &&
        is_bst_rec(root->right, root->data, max_value);
}

bool is_bst(BinaryTreeNode* root) {
    return is_bst_rec(root, numeric_limits<int>::min(), numeric_limits<int>::max());
}

int main() {
    BinaryTreeNode* root = new BinaryTreeNode(100);
    insert_bst(root, 50);
    insert_bst(root, 200);
    insert_bst(root, 25);
    // Add a node at an incorrect position
    insert_inorder_binary_tree(root, 125);
    insert_bst(root, 150);
    insert_bst(root, 350);
    display_inorder(root);
    if (is_bst(root)) {
        cout << "\nTrue\n";
    }
    else {
        cout << "\nFalse\n";
    }
}