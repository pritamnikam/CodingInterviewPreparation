/*

Subsets

Given a set with distinct elements, find all of its distinct subsets.

Example 1:

Input: [1, 3]
Output: [], [1], [3], [1,3]
Example 2:

Input: [1, 5, 3]
Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]

Solution#
To generate all subsets of the given set, we can use the Breadth First Search (BFS) approach. 
We can start with an empty set, iterate through all numbers one-by-one, and add them to existing sets to create new subsets.

Let’s take the example-2 mentioned above to go through each step of our algorithm:

Given set: [1, 5, 3]

Start with an empty set: [[]]
Add the first number (1) to all the existing subsets to create new subsets: [[], [1]];
Add the second number (5) to all the existing subsets: [[], [1], [5], [1,5]];
Add the third number (3) to all the existing subsets: [[], [1], [5], [1,5], [3], [1,3], [5,3], [1,5,3]].


Time complexity#
Since, in each step, the number of subsets doubles as we add each element to all the existing subsets, 
therefore, we will have a total of O(2^N) subsets, where ‘N’ is the total number of elements in the input set. 
And since we construct a new subset from an existing set, therefore, the time complexity of the above algorithm will be O(N*2^N).

Space complexity#
All the additional space used by our algorithm is for the output list. Since we will have a total of O(2^N)
subsets, and each subset can take up to O(N) space, therefore, the space complexity of our algorithm will be O(N*2^N).


*/

using namespace std;

#include <iostream>
#include <vector>

class Subsets {

public:
    static vector<vector<int>> findSubsets(const vector<int>& nums) {
        vector<vector<int>> subsets;
        // TODO: Write your code here
        // start by adding the empty subset
        subsets.push_back(vector<int>());
        for (auto currentNumber : nums) {
            // we will take all existing subsets and insert the current number in them to create new
            // subsets
            int n = subsets.size();
            for (int i = 0; i < n; i++) {
                // create a new subset from the existing subset and insert the current element to it
                vector<int> set(subsets[i]);
                set.push_back(currentNumber);
                subsets.push_back(set);
            }
        }
        return subsets;
    }

    // backtrack: add to set - recurrsively call function - remove from set
    static void findSubsets(const vector<int>& nums, 
                            vector<vector<int>>& subset, 
                            int index, 
                            vector<int>& currentSet) {
        subset.push_back(currentSet);
        for (int i = index; i < nums.size(); ++i) {
            currentSet.push_back(nums[i]);
            findSubsets(nums, subset, index + 1, currentSet);
            currentSet.pop_back();
        }
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> result = Subsets::findSubsets(vector<int>{1, 3});
    cout << "Here is the list of subsets: " << endl;
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    result = Subsets::findSubsets(vector<int>{1, 5, 3});
    cout << "Here is the list of subsets: " << endl;
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}

