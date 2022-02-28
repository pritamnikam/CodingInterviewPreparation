/*
Permutations

Problem Statement#
Given a set of distinct numbers, find all of its permutations.

Permutation is defined as the re-arranging of the elements of the set. For example, {1, 2, 3} has the following six permutations:

{1, 2, 3}
{1, 3, 2}
{2, 1, 3}
{2, 3, 1}
{3, 1, 2}
{3, 2, 1}
If a set has ‘n’ distinct elements it will have n!n! permutations.

Example 1:

Input: [1,3,5]
Output: [1,3,5], [1,5,3], [3,1,5], [3,5,1], [5,1,3], [5,3,1]

*/
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Permutations {
public:
    static vector<vector<int>> findPermutations(const vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> arr(nums.begin(), nums.end());
        result = findPermutationsHelper(arr);
        return result;
    }

    static vector<vector<int>> findPermutationsHelper(vector<int>& nums) {
        // base case:
        if (nums.size() <= 1) {
            return { nums };
        }


        vector<vector<int>> result;

        // for every number in array
        for (int i = 0; i < nums.size(); ++i) {
            // erase the number from ith location
            vector<int> arr(nums.begin(), nums.end());
            arr.erase(i + arr.begin());

            // get the permutations of remaining array
            auto permutations = findPermutationsHelper(arr);

            // for every permutations:
            for (int j = 0; j < permutations.size(); ++j) {
                // insert the number back to it's original position
                vector<int> permutation = permutations[j];
                permutation.insert(permutation.begin(), nums[i]);

                // add the permutation to final result
                result.emplace_back(permutation);
            }
        }

        // return result
        return result;
    }

    // alternative solution
    static void generatePermutationsRecursive(const vector<int>& nums, int index,
        vector<int>& currentPermutation, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(currentPermutation);
        }
        else {
            // create a new permutation by adding the current number at every position
            for (int i = 0; i <= currentPermutation.size(); i++) {
                vector<int> newPermutation(currentPermutation);
                newPermutation.insert(newPermutation.begin() + i, nums[index]);
                generatePermutationsRecursive(nums, index + 1, newPermutation, result);
            }
        }
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> result = Permutations::findPermutations(vector<int>{1, 3, 5});
    cout << "Here are all the permutations: " << endl;
    for (auto vec : result) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}