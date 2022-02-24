#if 0
137. Single Number II

Given an integer array nums where every element appears three times except for one, which appears exactly once.Find the single elementand return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.



Example 1:

Input: nums = [2, 2, 3, 2]
Output : 3
Example 2 :

    Input : nums = [0, 1, 0, 1, 0, 1, 99]
    Output : 99


    Constraints :

    1 <= nums.length <= 3 * 104
    - 231 <= nums[i] <= 231 - 1
    Each element in nums appears exactly three times except for one element which appears once.

#endif


    /*
    [C++] Simplest Solution | Bit Manipulation | O(n)

    Given an array in which each number repeats thrice, except for one, we need to find and return it using O(n) time & constant space.

    APPROACH :

    Since all the elements in the array are positive integers, we can traverse all the 32 bits & check if the number of elements this bit is set in is a multiple of 3.
    If not, then that bit is set in the single number too.
    So we OR the answer with the bit.

    How to get a single bit set in all 32 bits : 1<<i (Left shift operator to set only the ith bit)
    How to check if that bit is set in any element n of nums : Do n & (1<<i) (Since AND results in zero for any combination except 1&1, we get 1 if that bit is set and 0 otherwise).
    How to add that bit to the ans (the final single number we're going to return) : Just OR (1<<i) with the answer ( The OR operation can set any single bit in a number).

    Time Complexity : O(32n) == O(n)
    Space Complexity : O(1)

    */
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int check, count, ans = 0;
        // check all bits in 32-bit integers
        for (int i = 0; i <= 31; i++) {

            // start with first bit from 
            check = 1 << i;
            count = 0;

            // if the bit is set increment the count
            for (auto n : nums)
                if (n & check) 
                    count++;

            // If the count is not multiple of 3
            // we ge the answer by OR
            if (count % 3)
                ans |= check;
        }

        return ans;
    }
};