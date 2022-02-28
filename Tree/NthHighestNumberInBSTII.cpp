/*
Solution 2 #
Runtime complexity #
The runtime complexity of this solution is linear, O(n)O(n).

It will be O(logn)O(logn) for a balanced tree and in worst can be O(n)O(n).

Memory complexity #
The memory complexity of this solution is linear, O(h)O(h). hh being the height of the tree.

The recursive solution has O(h)O(h) memory complexity as it will consume memory on the stack up to the height of binary search tree h. It will be O(logn)O(logn) for a balanced tree and in worst can be O(n)O(n).

If each node in the BST has a count of total nodes in its left and right subtrees, then we can find the nthnth highest in a non-linear way. Here is the same BST used in the above example with counts populated.

100, Count=7
50, Count=3
200, Count=3
25, Count=1
75, Count=1
125, Count=1
350, Count=1
The basic algorithm to find the nthnth highest number with counts populated in BST is as follows:

We start with the root node.

k = current node total count - count of current's left node (i.e. number of nodes in right subtree + 1)

if k equals n then
    node is the nth highest
if k is greater than n then
    nth highest node exists in right subtree so find nth node in right subtree
if k is less than n then
    nth highest node exists in left subtree so deduce k from n and
    find (n - k)th node in the left subtree

*/

int current_count = 0;
BinaryTreeNode* find_nth_highest_in_bst(BinaryTreeNode* node, int n) {

    if (node == nullptr) {
        return nullptr;
    }

    int left_count = 0;

    if (node->left != nullptr) {
        left_count = node->left->count;
    }

    int k = node->count - left_count;

    if (k == n) {
        return node;
    }
    else if (k > n) {
        return
            find_nth_highest_in_bst(
                node->right,
                n);
    }
    else
    {
        return
            find_nth_highest_in_bst(
                node->left,
                n - k);
    }
}

int main() {
    BinaryTreeNode* root = new BinaryTreeNode(100);
    root->count = 7;

    insert_bst(root, 50);
    BinaryTreeNode* node12 = find_in_bst(root, 50);
    node12->count = 3;

    insert_bst(root, 200);
    BinaryTreeNode* node3 = find_in_bst(root, 200);
    node3->count = 3;

    insert_bst(root, 25);
    BinaryTreeNode* node4 = find_in_bst(root, 25);
    node4->count = 1;

    insert_bst(root, 75);
    BinaryTreeNode* node8 = find_in_bst(root, 75);
    node8->count = 1;

    insert_bst(root, 125);
    BinaryTreeNode* node18 = find_in_bst(root, 125);
    node18->count = 1;

    insert_bst(root, 350);
    BinaryTreeNode* node16 = find_in_bst(root, 350);
    node16->count = 1;


    display_level_order(root);

    int n = 2;
    current_count = 0;
    BinaryTreeNode* nth_highest_node = find_nth_highest_in_bst(root, n);
    cout << nth_highest_node->data;

    n = 1;
    current_count = 0;
    nth_highest_node = find_nth_highest_in_bst(root, n);
    cout << endl << nth_highest_node->data;

    n = 5;
    current_count = 0;
    nth_highest_node = find_nth_highest_in_bst(root, n);
    cout << endl << nth_highest_node->data;

    n = 30;
    current_count = 0;
    nth_highest_node = find_nth_highest_in_bst(root, n);
    string val = nth_highest_node == nullptr ? "null" : to_string(nth_highest_node->data);
    cout << endl << val;
}