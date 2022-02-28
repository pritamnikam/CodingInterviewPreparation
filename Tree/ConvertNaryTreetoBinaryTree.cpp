/*
Convert N-ary Tree to Binary Tree

Convert an N-ary tree to a Binary tree and then reconvert it to its original N-ary tree structure.

Description #
Convert an N-ary tree to a Binary tree and then convert the Binary tree back to its original N-ary tree structure. Consider the following N-ary tree:

1
2
3
4
5
6
N-ary Tree
There are several ways of representing this N-ary tree as a binary tree with and without extra metadata. Look at the below converted binary trees that don’t require any extra metadata storage (see if you get any clues).

1
2
3
4
5
6
1
2
3
5
4
6
Possible Binary Tree Representations

Hints #
Recursion
Traverse N-ary tree and devise a scheme of appending nodes in binary tree

Try it yourself#
The BinaryTreeNode class has members left and right along with the variable data.

Solution #
Runtime complexity #
The runtime complexity of this solution is linear, O(n)O(n).

Memory Complexity #
The memory complexity of this solution is O(h)O(h).

Recursive solution has O(h)O(h) memory complexity as it will consume memory on the stack up to the height of binary tree hh. It will be O(logn)O(logn) for balanced tree and in worst case can be O(n)O(n).

The algorithm we will use to convert N-ary to a Binary Tree is as follows:

Initial Direction = Left
For each node, append its children in a binary tree in given direction (Left/Right).
If any of the nodes in step 2 have further children, then change the direction and do step 2
Following is the running example: For N-ary tree root node 1 we create root node binary tree node 1:

The example below is of a left skewed tree.

1
1
2
3
4
5
6
For the first child of the node 11 (i.e. 22) append to the left of 11 in binary tree:

1
2
1
2
3
4
5
6
For the second child of the node 11 (i.e. 33) append to the left of 22 in binary tree:

1
2
3
1
2
3
4
5
6
Since 33 has further children we change the direction and start processing the children. For the first child of the node 33 (i.e. 55) append to the right of 33.

1
2
3
5
1
2
3
4
5
6
For the second child of the node 33 (i.e. 66) append to the right of 55

1
2
3
5
6
1
2
3
4
5
6
Now we are done with children of node 33 so we can continue processing children of node 11. For the last child of the node 11 (i.e., 44) append to the left of 33

1
2
3
4
5
6
1
2
3
4
5
6
Let’s have a look at the above algorithm step by step with the help of a detailed example.

In the example below, we are assuming the tree to be skewed to the right.


*/

BinaryTreeNode* convert_n_ary_to_binary_rec(TreeNode* node, bool isLeft) {

    if (node == NULL) {
        return NULL;
    }

    BinaryTreeNode* btnode = new BinaryTreeNode(node->data);
    BinaryTreeNode* lastnode = btnode;
    for (int i = 0; i < node->children.size(); i++) {
        if (isLeft) {
            lastnode->left = convert_n_ary_to_binary_rec(
                node->children[i], !isLeft);
            lastnode = lastnode->left;
        }
        else {
            lastnode->right = convert_n_ary_to_binary_rec(
                node->children[i], !isLeft);
            lastnode = lastnode->right;
        }
    }
    return btnode;
}

BinaryTreeNode* convert_n_ary_to_binary(TreeNode* root) {
    return convert_n_ary_to_binary_rec(root, true);
}

TreeNode* convert_binary_to_n_ary_tree_rec(BinaryTreeNode* node, bool isLeft) {

    if (node == NULL) {
        return NULL;
    }

    TreeNode* nnode = new TreeNode(node->data);
    BinaryTreeNode* temp = node;

    if (isLeft) {
        while (temp->left != NULL) {
            TreeNode* child = convert_binary_to_n_ary_tree_rec(
                temp->left, !isLeft);

            nnode->children.push_back(child);
            temp = temp->left;
        }
    }
    else {
        while (temp->right != NULL) {
            TreeNode* child = convert_binary_to_n_ary_tree_rec(
                temp->right, !isLeft);
            nnode->children.push_back(child);
            temp = temp->right;
        }
    }
    return nnode;
}

TreeNode* convert_binary_to_n_ary_tree(BinaryTreeNode* root) {
    return convert_binary_to_n_ary_tree_rec(root, true);
}

int main() {

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    node1->children.push_back(node2);
    node1->children.push_back(node3);
    node1->children.push_back(node4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    node3->children.push_back(node5);
    node3->children.push_back(node6);

    node1->display_level_order();
    BinaryTreeNode* bnode1 = convert_n_ary_to_binary(node1);
    display_level_order(bnode1);

    TreeNode* tnode1 = convert_binary_to_n_ary_tree(bnode1);
    tnode1->display_level_order();
}