/*
Level Averages in a Binary Tree

Problem Statement#
Given a binary tree, populate an array to represent the averages of all of its levels.

Example 1: 
 Level Averages:[1, 2.5, 5.5]

Example 2:
 Level Averages: [12.0, 4.0, 6.5]

 Solution#
This problem follows the Binary Tree Level Order Traversal pattern. We can follow the same BFS approach. The only difference will be that instead of keeping track of all nodes of a level, we will only track the running sum of the values of all nodes in each level. In the end, we will append the average of the current level to the result array.

Time complexity#
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. 
This is due to the fact that we traverse each node once.

Space complexity#
The space complexity of the above algorithm will be O(N) which is required for the queue. 
Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level), 
therefore we will need O(N) space to store them in the queue.

*/
using namespace std;

#include <iostream>
#include <queue>

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

class LevelAverage {
public:
    static vector<double> findLevelAverages(TreeNode* root) {
        if (root == nullptr)
            return vector<double>();

        vector<double> result;
        // TODO: Write your code here

        queue< TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            double currentLevelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* u = q.front();
                q.pop();

                currentLevelSum += u->val;
                if (u->left) q.push(u->left);
                if (u->right) q.push(u->right);
            }

            result.emplace_back(currentLevelSum / levelSize);
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    vector<double> result = LevelAverage::findLevelAverages(root);
    cout << "Level averages are: ";
    for (auto num : result) {
        cout << num << " ";
    }
}