/*

Solution 1 #
Runtime complexity #
The runtime complexity of this solution is linear, O(n)O(n).

Memory complexity #
The memory complexity of this solution is Logarithmic, O(logn)O(logn).

The recursive solution has O(h)O(h) memory complexity as it will consume memory on the stack up to the height of the binary tree h. It will be O(logn)O(logn) for a balanced tree and in the worst case can be O(n)O(n).

There can be multiple approaches to serialize and deserialize the tree. One approach is to perform a depth-first traversal and serialize individual nodes to the stream. We’ll use a pre-order traversal here. We’ll also serialize some marker to represent a null pointer to help deserialize the tree. Consider the below binary tree as an example. Markers (M*)(M∗) have been added in this tree to represent null nodes. The number with each marker i.e. 11 in M1M1, 22 in M2M2, merely represents the relative position of a marker in the stream.

100
50
200
25
75
M1
M2
M3
M4
M5
350
M6
M7
The serialized tree (pre-order traversal) from the above example would look like the below list.

100
50
25
M1
M2
75
M3
M4
200
M5
350
M6
M7
When deserializing the tree we’ll again use the pre-order traversal and create a new node for every non-marker node. Encountering a marker indicates that it was a null node.

Let’s run this approach on the above tree.


*/

const int MARKER = numeric_limits<int>::min();

void serialize(BinaryTreeNode* node, ostream& sstream) {

    if (node == nullptr) {
        sstream.write((char*)&MARKER, sizeof(MARKER));
        return;
    }

    sstream.write((char*)&node->data, sizeof(node->data));
    serialize(node->left, sstream);
    serialize(node->right, sstream);
}

BinaryTreeNode* deserialize(istream& sstream) {
    if (sstream.eof()) {
        return nullptr;
    }
    int val;
    sstream.read((char*)&val, sizeof(val));
    if (val == MARKER) {
        return nullptr;
    }

    BinaryTreeNode* pNode = new BinaryTreeNode(val);
    pNode->left = deserialize(sstream);
    pNode->right = deserialize(sstream);

    return pNode;
}

void test(vector<int>& v, bool display_output = false) {
    BinaryTreeNode* root = create_BST(v);
    if (display_output) {
        display_level_order(root);
    }


    ofstream outfile("temp.class", ios::binary);
    serialize(root, outfile);
    outfile.close();


    ifstream infile("temp.class", ios::binary);
    BinaryTreeNode* root2 = deserialize(infile);
    infile.close();

    if (display_output) {
        cout << "\nResult:\n";
        display_level_order(root2);
        cout << endl << endl;
    }
}

int main() {
    vector<int> orig_data = { 100, 50, 200, 25, 75, 125, 350 };

    BinaryTreeNode* root = create_BST(orig_data);
    display_level_order(root);
    ofstream outfile("temp.class", ios::binary);
    serialize(root, outfile);
    outfile.close();


    ifstream infile("temp.class", ios::binary);
    BinaryTreeNode* root2 = deserialize(infile);
    infile.close();


    cout << "\nResult:\n";
    display_level_order(root2);
    return 0;
}