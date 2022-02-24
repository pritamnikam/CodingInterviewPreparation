/*
Path with Maximum Sum

Find the path with the maximum sum in a given binary tree. Write a function that returns the maximum sum.

A path can be defined as a sequence of nodes between any two nodes and doesn’t necessarily pass through the root. 
The path must contain at least one node.

Solution#
This problem follows the Binary Tree Path Sum pattern and shares the algorithmic logic with Tree Diameter. 
We can follow the same DFS approach. The only difference will be to ignore the paths with negative sums. 
Since we need to find the overall maximum sum, we should ignore any path which has an overall negative sum.

Time complexity#
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. 
This is due to the fact that we traverse each node once.

Space complexity#
The space complexity of the above algorithm will be O(N) in the worst case. 
This space will be used to store the recursion stack. 

The worst case will happen when the given tree is a linked list (i.e., every node has only one child).


*/
#include <iostream>
#include <limits>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

class MaximumPathSum {
public:
    static int findMaximumPathSum(TreeNode* root) {
        int globalMaximumSum = numeric_limits<int>::min();
        findMaximumPathSumRecursive(root, globalMaximumSum);
        return globalMaximumSum;
    }

private:
    static int findMaximumPathSumRecursive(TreeNode* currentNode, int& globalMaximumSum) {
        if (currentNode == nullptr) {
            return 0;
        }

        int maxPathSumFromLeft = findMaximumPathSumRecursive(currentNode->left, globalMaximumSum);
        int maxPathSumFromRight = findMaximumPathSumRecursive(currentNode->right, globalMaximumSum);

        // ignore paths with negative sums, since we need to find the maximum sum we should
        // ignore any path which has an overall negative sum.
        maxPathSumFromLeft = max(maxPathSumFromLeft, 0);
        maxPathSumFromRight = max(maxPathSumFromRight, 0);

        // maximum path sum at the current node will be equal to the sum from the left subtree +
        // the sum from right subtree + val of current node
        int localMaximumSum = maxPathSumFromLeft + maxPathSumFromRight + currentNode->val;

        // update the global maximum sum
        globalMaximumSum = max(globalMaximumSum, localMaximumSum);

        // maximum sum of any path from the current node will be equal to the maximum of
        // the sums from left or right subtrees plus the value of the current node
        return max(maxPathSumFromLeft, maxPathSumFromRight) + currentNode->val;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;

    root = new TreeNode(-1);
    root->left = new TreeNode(-3);
    cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
}