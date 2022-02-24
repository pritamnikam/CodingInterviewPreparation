/*
Sum of Path Numbers

Problem Statement#
Given a binary tree where each node can only have a digit (0-9) value, each root-to-leaf path will represent a number. 
Find the total sum of all the numbers represented by all paths.

Example 1:
Output: 408 
Explanation: The sum of all path numbers: 17 + 192 + 199

Example 2:
Output: 332 
Explanation: The sum of all path numbers: 101 + 116 + 115

Solution#
This problem follows the Binary Tree Path Sum pattern. We can follow the same DFS approach. 
The additional thing we need to do is to keep track of the number representing the current path.

How do we calculate the path number for a node? Taking the first example mentioned above, say we are at node ‘7’. 
As we know, the path number for this node is ‘17’, which was calculated by: 1 * 10 + 7 => 17. 
We will follow the same approach to calculate the path number of each node.

Time complexity#
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. 
This is due to the fact that we traverse each node once.

Space complexity#
The space complexity of the above algorithm will be O(N) in the worst case. 
This space will be used to store the recursion stack. 

The worst case will happen when the given tree is a linked list (i.e., every node has only one child).

*/

using namespace std;

#include <iostream>
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

class SumOfPathNumbers {
    static int findSumOfPathNumbersHelper(TreeNode* root, int pathSum) {
        if (root == nullptr)
            return 0;

        pathSum = pathSum * 10 + root->val;

        // reached the leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return pathSum;
        }

        findSumOfPathNumbersHelper(root->left, pathSum);
        findSumOfPathNumbersHelper(root->right, pathSum);
    }

public:
    static int findSumOfPathNumbers(TreeNode* root) {
        int totalPathsSum = 0;
        // TODO: Write your code here
        return findSumOfPathNumbersHelper(root, totalPathsSum);
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}