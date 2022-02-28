/*
Mirror Binary Tree Nodes

Description #
Given the root node of a binary tree, swap the ‘left’ and ‘right’ children for each node. The below example shows how the mirrored binary tree should look like.

Hints #
You can use depth-first traversal to solve this challenge.
You can use the Bottom up mirroring approach.

Try it yourself#
The BinaryTreeNode class has members left and right along with the variable data.

Solution #
Runtime complexity #
The runtime complexity of this solution is linear, O(n)O(n).

Every sub-tree needs to be mirrored so we visit every node once and mirror the sub-tree starting there. Hence run time complexity is O(n).

Memory complexity #
The memory complexity of this solution is linear, O(n)O(n).

The recursive solution has O(h)O(h) memory complexity, for a balanced tree, as it will consume memory on the stack up to the height of the binary tree. For a skewed tree, it can be O(n)O(n).

Here, we will do a post order traversal of the binary tree. For every node, we will swap it’s left child with its right child. The original nodes are shown in green color while the nodes that have been swapped are shown in grey. The node at the top of the stack (current node) is shown in light blue. Note that we are doing DFS on the tree i.e. before returning from a node all its children have been visited (and mirrored).



*/

// post-order travelsal
void mirror_tree(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // We will do a post-order traversal of the binary tree.

    if (root->left != nullptr) {
        mirror_tree(root->left);
    }

    if (root->right != nullptr) {
        mirror_tree(root->right);
    }

    // Let's swap the left and right nodes at current level.

    BinaryTreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main() {
    BinaryTreeNode* root = new BinaryTreeNode(20);
    insert_bst(root, 50);
    insert_bst(root, 200);
    insert_bst(root, 75);
    insert_bst(root, 25);
    insert_bst(root, 300);
    display_level_order(root);
    mirror_tree(root);
    cout << "Mirrored tree:" << endl;
    display_level_order(root);
}