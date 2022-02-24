/*
1161. Maximum Level Sum of a Binary Tree

https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/


Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.



Example 1:
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation:
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

Example 2:
Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
Output: 2

Constraints:
The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105

*/

using namespace std;

#include <iostream>
#include <queue>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int result = 0;
        // TODO: Write your code here

        queue<TreeNode*> q;
        q.push(root);

        int level = 1;
        int maxLevelSum = INT_MIN;
        while (!q.empty()) {
            int levelSize = q.size();
            int currentLevelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* u = q.front();
                q.pop();

                currentLevelSum += u->val;
                if (u->left) q.push(u->left);
                if (u->right) q.push(u->right);
            }

            if (maxLevelSum < currentLevelSum) {
                maxLevelSum = currentLevelSum;
                result = level;
            }
            ++level;
        }

        return result;
    }
};