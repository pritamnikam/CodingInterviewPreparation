/*
Path With Given Sequence

Problem Statement#
Given a binary tree and a number sequence, find if the sequence is present as a root-to-leaf path in the given tree.

Solution#
This problem follows the Binary Tree Path Sum pattern. We can follow the same DFS approach and additionally, 
track the element of the given sequence that we should match with the current node. Also, we can return false 
as soon as we find a mismatch between the sequence and the node value.

Time complexity#
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. 
This is due to the fact that we traverse each node once.

Space complexity#
The space complexity of the above algorithm will be O(N) in the worst case. 
This space will be used to store the recursion stack. 
The worst case will happen when the given tree is a linked list (i.e., every node has only one child).


*/
#include <iostream>
#include <vector>

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

class PathWithGivenSequence {
public:
    static bool findPath(TreeNode* root, const vector<int>& sequence) {
        if (root == nullptr) {
            return sequence.empty();
        }

        return findPathRecursive(root, sequence, 0);
    }

private:
    static bool findPathRecursive(TreeNode* currentNode, const vector<int>& sequence,
        int sequenceIndex) {
        if (currentNode == nullptr) {
            return false;
        }

        if (sequenceIndex >= sequence.size() || currentNode->val != sequence[sequenceIndex]) {
            return false;
        }

        // if the current node is a leaf, add it is the end of the sequence, we have found a path!
        if (currentNode->left == nullptr && currentNode->right == nullptr &&
            sequenceIndex == sequence.size() - 1) {
            return true;
        }

        // recursively call to traverse the left and right sub-tree
        // return true if any of the two recursive call return true
        return findPathRecursive(currentNode->left, sequence, sequenceIndex + 1) ||
            findPathRecursive(currentNode->right, sequence, sequenceIndex + 1);
    }
};

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);

    cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 7})
        << endl;
    cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 6})
        << endl;
}