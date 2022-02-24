/*
Connect Level Order Siblings

Problem Statement#
Given a binary tree, connect each node with its level order successor. 
The last node of each level should point to a null node.

Solution#
This problem follows the Binary Tree Level Order Traversal pattern. 
We can follow the same BFS approach. 

The only difference is that while traversing a level we will remember the previous node to connect it with the current node.

Time complexity#
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity#
The space complexity of the above algorithm will be O(N), which is required for the queue. Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level), therefore we will need O(N) space to store them in the queue.


*/

using namespace std;

#include <iostream>
#include <queue>

class TreeNode {
public:
    int val = 0;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;

    TreeNode(int x) {
        val = x;
        left = right = next = nullptr;
    }

    // level order traversal using 'next' pointer
    virtual void printLevelOrder() {
        TreeNode* nextLevelRoot = this;
        while (nextLevelRoot != nullptr) {
            TreeNode* current = nextLevelRoot;
            nextLevelRoot = nullptr;
            while (current != nullptr) {
                cout << current->val << " ";
                if (nextLevelRoot == nullptr) {
                    if (current->left != nullptr) {
                        nextLevelRoot = current->left;
                    }
                    else if (current->right != nullptr) {
                        nextLevelRoot = current->right;
                    }
                }
                current = current->next;
            }
            cout << endl;
        }
    }
};

class ConnectLevelOrderSiblings {
public:
    static void connect(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* previousNode = nullptr;
            int levelSize = queue.size();
            // connect all nodes of this level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = queue.front();
                queue.pop();
                if (previousNode != nullptr) {
                    previousNode->next = currentNode;
                }
                previousNode = currentNode;

                // insert the children of current node in the queue
                if (currentNode->left != nullptr) {
                    queue.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    queue.push(currentNode->right);
                }
            }
        }
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(7);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    ConnectLevelOrderSiblings::connect(root);
    cout << "Level order traversal using 'next' pointer: " << endl;
    root->printLevelOrder();
}