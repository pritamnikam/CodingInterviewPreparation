/*
Reverse Level Order Traversal

Problem Statement#
Given a binary tree, populate an array to represent its level-by-level traversal in reverse order, i.e., the lowest level comes first. 
You should populate the values of all nodes in each level from left to right in separate sub-arrays.

Solution#
This problem follows the Binary Tree Level Order Traversal pattern. We can follow the same BFS approach. 
The only difference will be that instead of appending the current level at the end, we will append the current level at 
the beginning of the result list.

Time complexity#
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. 
This is due to the fact that we traverse each node once.

Space complexity#
The space complexity of the above algorithm will be O(N) as we need to return a list containing the level order traversal.
We will also need O(N) space for the queue. 

Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level), 
therefore we will need O(N) space to store them in the queue.

*/

using namespace std;

#include <deque>
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

class ReverseLevelOrderTraversal {
public:
    static deque<vector<int>> traverse(TreeNode* root) {
        deque<vector<int>> result = deque<vector<int>>();
        // TODO: Write your code here
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            while (levelSize) {
                TreeNode* u = q.front();
                q.pop();

                currentLevel.emplace_back(u->val);
                if (u->left != nullptr)
                    q.push(u->left);
                if (u->right != nullptr)
                    q.push(u->right);

                --levelSize;
            }
            // append the current level at the beginning
            result.push_front(currentLevel);
        }
        return result;
    }
};
int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    auto result = ReverseLevelOrderTraversal::traverse(root);

    cout << "Reverse level order traversal: ";
    for (auto que : result) {
        for (auto num : que) {
            cout << num << " ";
        }
        cout << endl;
    }
}