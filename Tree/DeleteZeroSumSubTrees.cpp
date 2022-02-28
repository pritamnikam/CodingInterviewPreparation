/*
Delete Zero Sum Sub-Trees

Delete any subtrees whose nodes sum up to zero for a given binary tree.


Description #
Given the root of a binary tree, delete any subtrees whose nodes sum up to zero. 
In the below binary tree, we need to delete the subtree starting at node 55 as it’s sum (5 -3 -2) equals zero.

Solution #
Runtime complexity #
The runtime complexity of this solution is linear, O(n)O(n).

Memory complexity #
The memory complexity of this solution is O(h)O(h).

Recursive solution has O(h)O(h) memory complexity as it will consume memory on the stack up to height of binary tree h. It will be O(logn)O(logn) for balanced tree and in the worst case can be O(n)O(n).

We will do a post order traversal of the binary tree. Before moving forward, lets discuss what post order traversal really is:

Post-order

Traverse the left subtree by recursively calling the post-order function.
Traverse the right subtree by recursively calling the post-order function.
Process the data part of the root element (or current element). 

For every node, if it’s left or right subtree reports zero sum, we will delete that subtree. 
Moreover, if the root node returns zero then we will delete the entire tree.

*/

void delete_tree_rec(BinaryTreeNode* root) {
    if (root != nullptr) {

        if (root->left != nullptr) {
            delete_tree_rec(root->left);
            root->left = nullptr;
        }

        if (root->right != nullptr) {
            delete_tree_rec(root->right);
            root->right = nullptr;
        }

        delete root;
    }
}

void delete_binary_tree(BinaryTreeNode** root) {
    if (root != nullptr && *root != nullptr) {
        delete_tree_rec(*root);
        *root = nullptr;
    }
}

int delete_zero_sum_subtree(BinaryTreeNode* root) {

    if (root == nullptr) {
        return 0;
    }

    int sum_left = delete_zero_sum_subtree(root->left);
    int sum_right = delete_zero_sum_subtree(root->right);

    if (sum_left == 0) {
        delete_binary_tree(&root->left);
    }

    if (sum_right == 0) {
        delete_binary_tree(&root->right);
    }

    return root->data + sum_left + sum_right;
}

void delete_zero_sum_subtree(BinaryTreeNode** root) {
    if (root != nullptr && *root != nullptr) {
        if (delete_zero_sum_subtree(*root) == 0) {
            // delete binary tree deleted the whole tree
            // rooted at 'root' and set root to null.
            delete_binary_tree(root);
        }
    }
}

BinaryTreeNode* create_test_tree1() {

    BinaryTreeNode* head = new BinaryTreeNode(7);
    BinaryTreeNode* curr_head = head;

    BinaryTreeNode* left = new BinaryTreeNode(5);
    BinaryTreeNode* right = new BinaryTreeNode(6);
    curr_head->left = left;
    curr_head->right = right;

    curr_head = head->left;
    left = new BinaryTreeNode(-3);
    right = new BinaryTreeNode(-2);
    curr_head->left = left;
    curr_head->right = right;

    return head;
}

int main() {
    BinaryTreeNode* root = create_test_tree1();
    cout << "Level Order Traversal:" << endl;
    display_level_order(root);
    delete_zero_sum_subtree(&root);
    cout << "Level Order Traversal:" << endl;
    display_level_order(root);
    assert(root->data == 7 && root->left == nullptr && root->right->data == 6);
}

