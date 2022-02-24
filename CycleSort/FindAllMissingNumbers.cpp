/*
Find all Missing Numbers

Problem Statement#
We are given an unsorted array containing numbers taken from the range 1 to �n�. The array can have duplicates, which means some numbers will be missing. Find all those missing numbers.

Example 1:

Input: [2, 3, 1, 8, 2, 3, 5, 1]
Output: 4, 6, 7
Explanation: The array should have all numbers from 1 to 8, due to duplicates 4, 6, and 7 are missing.
Example 2:

Input: [2, 4, 1, 2]
Output: 3
Example 3:

Input: [2, 3, 2, 1]
Output: 4

Solution#
This problem follows the Cyclic Sort pattern and shares similarities with Find the Missing Number with one difference. In this problem, there can be many duplicates whereas in �Find the Missing Number� there were no duplicates and the range was greater than the length of the array.

However, we will follow a similar approach though as discussed in Find the Missing Number to place the numbers on their correct indices. Once we are done with the cyclic sort we will iterate the array to find all indices that are missing the correct numbers.

Time complexity#
The time complexity of the above algorithm is O(n)O(n).

Space complexity#
Ignoring the space required for the output array, the algorithm runs in constant space O(1)O(1).


*/

using namespace std;

#include <iostream>
#include <vector>

class AllMissingNumbers {
    static void swap(vector<int>& nums, int i, int j) {
        int k = nums[i];
        nums[i] = nums[j];
        nums[j] = k;
    }
public:
    static vector<int> findNumbers(vector<int>& nums) {
        vector<int> missingNumbers;
        // TODO: Write your code here
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            }
            else {
                i++;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                missingNumbers.emplace_back(i + 1);
            }
        }

        return missingNumbers;
    }
};