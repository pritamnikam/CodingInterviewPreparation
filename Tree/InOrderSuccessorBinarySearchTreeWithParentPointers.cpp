/*
In-order Successor Binary Search Tree With Parent Pointers

The in-order successor of a node in a binary tree is the next node in an in-order traversal. 
Write a method to find an in-order successor of a given binary tree node in a binary search tree given parent pointers.


Solution #
Runtime complexity #
The runtime complexity of this solution is logarithmic, O(logn)O(logn).

Memory complexity #
The memory complexity of this solution is constant, O(1)O(1).

We strongly recommend that you try solving the in-order successor in BST without parent pointers first. Here is the algorithm for finding an in-order successor with parent pointers:

If the given node has a right child, then the left most child in the right child’s subtree will be the in-order successor
If the given node has no right child, then:
Start going up the parent chain. In this chain, keep going until you find a node who is a left child of its parent. This parent node will be the in-order successor
If no such node is found, the in-order successor will be NULL

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

BinaryTreeNode* find_min_in_tree(BinaryTreeNode* root) {
    if (root == nullptr)
        return nullptr;

    while (root->left != nullptr) {
        root = root->left;
    }

    return root;
}

BinaryTreeNode* inorder_successor_bst_parent_pointer(BinaryTreeNode* node) {

    if (node == nullptr) {
        return nullptr;
    }

    if (node->right != nullptr) {
        return find_min_in_tree(node->right);
    }

    while (node->parent != nullptr) {
        if (node->parent->left == node) {
            return node->parent;
        }
        node = node->parent;
    }

    return nullptr;
}

BinaryTreeNode* find_successor(
    BinaryTreeNode* root, int d) {

    while (root != nullptr) {

        if (root->data < d) {
            root = root->right;
        }
        else if (root->data > d) {
            root = root->left;
        }
        else {
            return inorder_successor_bst_parent_pointer(root);
        }
    }

    return nullptr;
}