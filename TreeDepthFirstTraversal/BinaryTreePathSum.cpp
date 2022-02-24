/*
Binary Tree Path Sum

Problem Statement#
Given a binary tree and a number ‘S’, find if the tree has a path from root-to-leaf such that the sum of all the node 
values of that path equals ‘S’.


Solution#
As we are trying to search for a root-to-leaf path, we can use the Depth First Search (DFS) technique to solve this problem.

To recursively traverse a binary tree in a DFS fashion, we can start from the root and at every step, make two recursive 
calls one for the left and one for the right child.

Here are the steps for our Binary Tree Path Sum problem:

Start DFS with the root of the tree.
If the current node is not a leaf node, do two things:
1. Subtract the value of the current node from the given number to get a new sum => S = S - node.value
2. Make two recursive calls for both the children of the current node with the new number calculated in the previous step.
3. At every step, see if the current node being visited is a leaf node and if its value is equal to the given number ‘S’. 
    If both these conditions are true, we have found the required root-to-leaf path, therefore return true.
4. If the current node is a leaf but its value is not equal to the given number ‘S’, return false.

\Time complexity#
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. 
This is due to the fact that we traverse each node once.

Space complexity#
The space complexity of the above algorithm will be O(N) in the worst case. 
This space will be used to store the recursion stack. 

The worst case will happen when the given tree is a linked list (i.e., every node has only one child).


*/

using namespace std;

#include <iostream>

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

class TreePathSum {
public:
    static bool hasPath(TreeNode* root, int sum) {
        if (root == nullptr)
            return false;

        // root-to-leaf path
        if (root->val == sum &&
            root->left == nullptr &&
            root->right == nullptr) {
            return true;
        }
        
        // either left or right sub-tree has remaining sum
        return hasPath(root->left, sum - root->val) ||
               hasPath(root->right, sum - root->val);
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    cout << "Tree has path: " << TreePathSum::hasPath(root, 23) << endl;
    cout << "Tree has path: " << TreePathSum::hasPath(root, 16) << endl;
}