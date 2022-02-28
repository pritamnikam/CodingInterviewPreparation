/*
Convert Binary Tree to Doubly Linked List

Given a binary tree, convert it to a doubly linked list so that the order of the doubly linked list is the same as an in-order traversal of the binary tree.

Description #
Convert a binary tree to a doubly linked list so that the order of the doubly-linked list is the same as an in-order traversal of the binary tree. 

After conversion, the left pointer of the node should be pointing to the previous node in the doubly linked list, and the right pointer should be 
pointing to the next node in the doubly linked list.

We will do the conversion in place, i.e., instead of creating a separate linked list, we will modify the nodes in the binary tree themselves. 
After the conversion, the left and right child pointers of every node will point to its predecessor and successor, respectively, 
in the in-order traversal of the original tree. Then, we will return the head node of the linked list, which should be the first node in the 
in-order traversal of the original binary tree.

Hints #
Use the divide and conquer technique to tackle this problem.
The solution can be implemented using recursion.
Fuse already processed sub-trees.

Solution #
Runtime complexity #
The runtime complexity of this solution is linear, O(n)O(n).

Runtime complexity is based on the number of nodes in the tree.

Memory complexity #
The memory complexity of this solution is linear, O(h)O(h).

The recursive solution has O(h)O(h) memory complexity as it will consume memory on the stack up to the height of binary tree ‘h’. 
It will be O(logn)O(logn) for a balanced tree and, in the worst case, can be O(n)O(n).

In an in-order traversal, first, the left sub-tree is traversed, then the root is visited, and finally, the right subtree is traversed.

One simple way of solving this problem is to start with an empty doubly linked list. 
While doing the in-order traversal of the binary tree, keep inserting each element output into the doubly linked list. 
But, if we look at the question carefully, the interviewer wants us to convert the binary tree to a doubly-linked list in-place 
i.e., we should not create new nodes for the doubly linked list.

This problem can be solved recursively using a divide and conquer approach. 

Below is the algorithm specified in simple words.

Start with the root node and solve left and right sub-trees recursively
At each step, once left and right sub-trees have been processed:
   - fuse output of left subtree with root to make the intermediate result
   - fuse intermediate result (built in the previous step) with output from the right sub-tree to make the final result of the current recursive call

*/

// merge(fuse) two sorted linked lists
BinaryTreeNode* concatenate_lists(BinaryTreeNode* head1, BinaryTreeNode* head2) {

    if (head1 == nullptr) {
        return head2;
    }

    if (head2 == nullptr) {
        return head1;
    }

    // use left for previous.
    // use right for next.
    BinaryTreeNode* tail1 = head1->left;
    BinaryTreeNode* tail2 = head2->left;

    tail1->right = head2;
    head2->left = tail1;

    head1->left = tail2;
    tail2->right = head1;
    return head1;
}

BinaryTreeNode* convert_to_linked_list_rec(BinaryTreeNode* root) {

    if (root == nullptr) {
        return nullptr;
    }

    BinaryTreeNode* list1 = convert_to_linked_list_rec(root->left);
    BinaryTreeNode* list2 = convert_to_linked_list_rec(root->right);

    root->left = root->right = root;
    BinaryTreeNode* result = concatenate_lists(list1, root);
    result = concatenate_lists(result, list2);

    return result;
}

BinaryTreeNode* convert_to_linked_list(BinaryTreeNode* root) {
    BinaryTreeNode* head = convert_to_linked_list_rec(root);
    if (head->left != nullptr) {
        head->left->right = nullptr;
        head->left = nullptr;
    }
    return head;
}

vector<int> get_vector(BinaryTreeNode* head) {
    vector<int> r;
    if (head == nullptr) {
        return r;
    }

    BinaryTreeNode* temp = head;
    do {
        r.push_back(temp->data);
        temp = temp->right;
    } while (temp != nullptr);
    return r;
}

int main() {
    vector<int> orig_data = { 100, 50, 200, 25, 75, 125, 350, 30, 60 };

    BinaryTreeNode* root = create_BST(orig_data);
    BinaryTreeNode* head = convert_to_linked_list(root);
    vector<int> v = get_vector(head);

    for (int x : v) {
        cout << x << " ";
    }
    return 0;
}