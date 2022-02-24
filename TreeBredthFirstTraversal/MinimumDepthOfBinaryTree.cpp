/*
Minimum Depth of a Binary Tree

Problem Statement#
Find the minimum depth of a binary tree. The minimum depth is the number of nodes along the shortest path from
the root node to the nearest leaf node.

Example 1:

 Minimum Depth:
 2
    1
    2
    3
    4
    5

Example 2:

 Minimum Depth:
    12
    7
    1
    9
    10
    5
    11
 Minimum Depth: 2
 3
    12
    7
    1
    10
    5

*/

using namespace std;

#include <iostream>
#include <queue>
#include <limits>

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

class MinimumBinaryTreeDepth {
public:
    static int findDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int minimumTreeDepth = numeric_limits<int>::max();
        // TODO: Write your code here

        queue<TreeNode*> q;
        q.push(root);

        int curLevel = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            ++curLevel;

            while (levelSize) {
                TreeNode* u = q.front();
                q.pop();

                --levelSize;
                if (u->left == nullptr && u->right == nullptr) {
                    minimumTreeDepth = min(minimumTreeDepth, curLevel);
                }

                if (u->left != nullptr) q.push(u->left);
                if (u->right != nullptr) q.push(u->right);
            }
        }

        return minimumTreeDepth;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
    root->left->left = new TreeNode(9);
    root->right->left->left = new TreeNode(11);
    cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
}