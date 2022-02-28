/*
Count of Structurally Unique Binary Search Trees

Given a number ‘n’, write a function to return the count of structurally unique Binary Search Trees 
(BST) that can store values 1 to ‘n’.

Example 1:

Input: 2
Output: 2
Explanation: As we saw in the previous problem, there are 2 unique BSTs storing numbers from 1-2.
Example 2:

Input: 3
Output: 5
Explanation: There will be 5 unique BSTs that can store numbers from 1 to 3.


Solution#
This problem is similar to Structurally Unique Binary Search Trees. 
Following a similar approach, we can iterate from 1 to ‘n’ and consider each number as the root of a 
tree and make two recursive calls to count the number of left and right sub-trees.


*/
using namespace std;

#include <iostream>
#include <unordered_map>

class TreeNode {
public:
    int val = 0;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) { val = x; }
};

class CountUniqueTrees {
public:
    unordered_map<int, int> map = unordered_map<int, int>();

    virtual int countTrees(int n) {
        if (map.find(n) != map.end()) {
            return map[n];
        }

        if (n <= 1) {
            return 1;
        }

        int count = 0;
        for (int i = 1; i <= n; i++) {
            // making 'i' root of the tree
            int countOfLeftSubtrees = countTrees(i - 1);
            int countOfRightSubtrees = countTrees(n - i);
            count += (countOfLeftSubtrees * countOfRightSubtrees);
        }
        map[n] = count;
        return count;
    }
};

int main(int argc, char* argv[]) {
    CountUniqueTrees ct;
    int count = ct.countTrees(3);
    cout << "Total trees: " << count;
}