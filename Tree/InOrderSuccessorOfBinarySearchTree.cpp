/*
In-order Successor of Binary Search Tree

This lesson will contain a challenge to find the in-order successor.


Description #
The in-order successor of a node in a binary Search Tree (BST) is the next node in in-order traversal.
Write a method to find the in-order successor of a given value “d” in a BST.

In the above tree:

In-order successor of 2525 is 5050
In-order successor of 5050 is 7575
In-order successor of 7575 is 100100
In-order successor of 100100 is 125125
In-order successor of 125125 is 200200
In-order successor of 200200 is 350350
In-order successor of 350350 is NULL since it is the last node

Hints #
Guess where the in-order successor of a node can be placed in a BST.


Try it yourself#
The BinaryTreeNode class has members left and right along with the variable data.

Runtime complexity#
The runtime complexity of this solution is logarithmic, O(logn)O(logn).

Memory complexity #
The memory complexity of this solution is constant, O(1)O(1).

A naive solution of this problem would be doing an in-order traversal of the BST. Once dd is found, it returns the next node in the traversal. The runtime of this approach is linear. We can do better than linear in this problem if we closely look at the possible locations of the in-order successor. Let’s define some rules around that:

Find the value dd in BST.

If dd has a right child then the left most child in right child’s subtree will be the in-order successor of dd. This would also be the child with the minimum value in that subtree.

If dd has no right child then:

in-order successor is NULL if dd is right most node in the BST i.e. last node in the in-order traversal.
in-order successor is the node with minimum value higher than dd in the parent chain of d.

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
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode() : data(0), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    BinaryTreeNode(int x, BinaryTreeNode* left, BinaryTreeNode* right) : data(x), left(left), right(right) {}
};


BinaryTreeNode* FindMinimum(BinaryTreeNode* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) root = root->left;
    return root;
}


// if 'd' is found in tree
// if 'd' has right child, successor is the left-most node in right-subtree
// if 'd' has not right child
//  - successor is null if 'd' is the right-most node in tree
//  - successor is the node with minimum value higher than d in the parent chain of d.
BinaryTreeNode* inorder_successor_bst(BinaryTreeNode* root, int d) {
    BinaryTreeNode* successor = nullptr;

    // BST to search 'd'
    while (root) {
        if (root->data < d) {
            root = root->right;
        }
        else if (root->data > d) {
            successor = root;
            root = root->left;
        }
        else /* if (root->data == d) */ {
            if (root->right != nullptr) {
                successor = FindMinimum(root->right);
            }
            break;
        }
    }
    return successor;
}
