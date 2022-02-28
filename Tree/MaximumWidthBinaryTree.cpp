/*
https://leetcode.com/problems/maximum-width-of-binary-tree/

662. Maximum Width of Binary Tree


Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.



Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,null,5,3]
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).


Constraints:

The number of nodes in the tree is in the range [1, 3000].
-100 <= Node.val <= 100

*/


#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;


//  Definition for a binary tree node.
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        int res = 1;
        queue<pair<TreeNode*, int>> q;

        // I am using intialising list
        q.push({ root, 0 });      // also can use make_pair

        while (!q.empty())
        {
            int cnt = q.size();
            // start is the index of root node for first level
            int start = q.front().second;
            int end = q.back().second;

            res = max(res, end - start + 1);

            for (int i = 0; i < cnt; ++i)
            {
                pair<TreeNode*, int> p = q.front();
                // we will use it while inserting it children
                // left child will be 2 * idx + 1;
                // right chils will be 2 * idx + 2;
                int idx = p.second - start;

                q.pop();

                // if  left child exist
                if (p.first->left != NULL)
                    q.push({ p.first->left, (long long)2 * idx + 1 });

                // if right child exist
                if (p.first->right != NULL)
                    q.push({ p.first->right, (long long)2 * idx + 2 });
            }
        }

        return res;
    }
};