/*
Additional thoughts #
Another algorithm is to serialize the tree in any two depth-first traversal orders e.g. pre-order and in-order traversal. Remember that we can construct a tree (or deserialize) if two of its depth-first orders are given. For integer data this approach is almost similar to the above algorithm in terms of space and time complexity.

But if the data is of user defined type with relatively large size of each node, storing data twice is not that efficient. For most practical purposes, store extra markers which will be significantly less in size compared to the data nodes.

If we know that our tree is almost a complete binary tree, we can serialize it like a heap data structure. We can use the below two rules to serialize and deserialize data:

children of a node ii are 2 * i2∗i and 2 * i + 12∗i+1.
parent of a node ii is i / 2i/2.
Solution 2 #
Runtime complexity #
The runtime complexity of this solution is linearithmic, O(nlogn)O(nlogn) in case of a balanced tree and can be quadratic, O(n^2)O(n
​2
​​ ) in the worst case.

Memory complexity #
The memory complexity of this solution is logarithmic, O(logn)O(logn).

Serialize the tree in two ways:

pre-order traversal
in-order traversal
1
2
3
4
5
Original Tree
1
2
3
4
5
Preorder Traversal
2
1
4
3
5
Inorder Traversal
For Deserialization Recursive Solution:

The first element in the preorder traversal is root.

Find the root value in the inorder traversal.

Values on the left of the root construct the left subtree.

Values on the right of the root construct the right subtree.

1
2
3
4
5
Preorder Traversal
2
1
4
3
5
Inorder Traversal
Here, 22 constructs the left subtree.

4, 3, 54,3,5 construct the right sub tree.

Here, the number of elements in left subtree = 1=1

The number of elements in right subtree = 3=3

For constructing the left subtree:

Take only next 11 element in preorder traversal (Number of elements in left subtree = 1=1)

Take on left values in in-order traversal Repeat the same process. i.e. find the 22 of preorder traversal in in-order traversal

1
2
3
4
5
Take only next 1 element in preorder traversal (Number of elements in left subtree = 1)
2
1
4
3
5
Take on left values in inorder traversal
For constructing right subtree:

Take only next 33 element in preorder traversal (Number of elements in rightsubtree = 3=3)

Take on right values in in-order traversal Repeat the same process. i.e. find the 33 of preorder traversal in in-order traversal

1
2
3
4
5
Take only next 3 element in preorder traversal (Number of elements in rightsubtree = 3)
2
1
4
3
5
Take on right values in inorder traversal
Let’s run this approach on the above tree.



*/

void serialize_preorder(BinaryTreeNode* node,
    ostream& sstream) {
    if (node == nullptr) {
        return;
    }

    sstream.write((char*)&node->data, sizeof(node->data));
    serialize_preorder(node->left, sstream);
    serialize_preorder(node->right, sstream);
}

void serialize_inorder(BinaryTreeNode* node,
    ostream& sstream) {
    if (node == nullptr) {
        return;
    }

    serialize_inorder(node->left, sstream);
    sstream.write((char*)&node->data, sizeof(node->data));
    serialize_inorder(node->right, sstream);
}

vector<int> deserialize_preorder(istream& sstream) {
    vector<int> v;
    int val;

    while (true) {
        sstream.read((char*)&val, sizeof(val));
        if (sstream.eof())
            break;
        v.push_back(val);
    }

    return v;
}

vector<int> deserialize_inorder(istream& sstream) {
    vector<int> v;
    int val;

    while (true) {
        sstream.read((char*)&val, sizeof(val));
        if (sstream.eof())
            break;
        v.push_back(val);
    }

    return v;
}

BinaryTreeNode* deserialize2(vector<int> preOrder, vector<int> inOrder, int preStart, int inStart, int preEnd, int inEnd) {

    // check if there is no element or one element
    if (preStart > preEnd)
        return NULL;

    else if (preStart == preEnd) {
        BinaryTreeNode* node = new BinaryTreeNode(preOrder[preStart]);
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    // otherwise first element in preOrder array is root, we find that value in inOrder array
    // and determine how many elemnets are in left and right subtrees
    int rootIndexInorder = 0;

    for (int i = inStart; i <= inEnd; i++) {
        if (inOrder[i] == preOrder[preStart]) {
            rootIndexInorder = i; // we find the first value of preOrder in inOrder array.
            break;
        }
    }

    // now we calculate number of elements in right subtree and left subtree
    int leftSubCount = rootIndexInorder - inStart;
    int rightSubCount = inEnd - rootIndexInorder;

    BinaryTreeNode* node = new BinaryTreeNode(preOrder[preStart]);
    node->left = deserialize2(preOrder, inOrder, preStart + 1, inStart, preStart + leftSubCount, inStart + leftSubCount - 1);
    node->right = deserialize2(preOrder, inOrder, preStart + leftSubCount + 1,  inStart + leftSubCount + 1, preEnd, inEnd);
    return node;
}

void test(vector<int>& v, bool display_output = false) {

    BinaryTreeNode* root = create_BST(v);
    if (display_output) {
        display_level_order(root);
    }


    ofstream outfile("pre.class", ios::binary);
    serialize_preorder(root, outfile);
    outfile.close();

    ofstream outfile2("in.class", ios::binary);
    serialize_inorder(root, outfile2);
    outfile2.close();


    ifstream infile("pre.class", ios::binary);
    vector<int> preorder = deserialize_preorder(infile);
    infile.close();

    ifstream infile2("in.class", ios::binary);
    vector<int> inorder = deserialize_inorder(infile2);
    infile2.close();

    BinaryTreeNode* root2 = deserialize2(preorder, inorder, 0,
        0, preorder.size() - 1, inorder.size() - 1);

    if (display_output) {
        cout << "\nResult:\n";
        display_level_order(root2);
        cout << endl << endl;
    }

    assert(are_identical_trees(root, root2));
}

int main() {

    vector<int> orig_data = { 100, 50, 200, 25, 75, 125, 350 };
    test(orig_data, true);

    return 0;
}