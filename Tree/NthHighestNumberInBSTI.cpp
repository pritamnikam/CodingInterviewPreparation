/*
Solution 1 #
Runtime complexity #
The runtime complexity of this solution is linear, O(n)O(n).

Memory complexity #
The memory complexity of this solution is linear, O(h)O(h). hh being the height of the tree.

The recursive solution has O(h)O(h) memory complexity as it will consume memory on the stack up to the height of the binary search tree h. It will be O(logn)O(logn) for a balanced tree and in the worst case can be O(n)O(n).

In-order traversal of BST is always sorted in ascending order. To find the nth highest node, we will need to scan the tree in descending order by doing reverse in-order traversal. The in-order traversal is normally LVR i.e. Left - Visit - Right. Reverse in-order traversal will be RVL i.e. Right - Visit - Left. While doing so, we keep a count of nodes seen so far. Once the count reaches nn, that is the node to return. Let’s run the above example for n = 3n=3.

The first node we see in this traversal is the right most node 350350, and the count is 11.


*/

int current_count = 0;

BinaryTreeNode* find_nth_highest_in_bst(BinaryTreeNode* node, int n) {

    if (node == nullptr) {
        return nullptr;
    }

    BinaryTreeNode* result =
        find_nth_highest_in_bst(node->right, n);

    if (result != nullptr) {
        return result;
    }

    current_count++;
    if (n == current_count) {
        return node;
    }

    result =
        find_nth_highest_in_bst(node->left, n);

    if (result != nullptr) {
        return result;
    }

    return nullptr;
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