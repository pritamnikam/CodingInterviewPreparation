/*
Equal Subset Sum Partition

Problem Statement#
Given a set of positive numbers, find if we can partition it into two subsets such that the sum of elements in both subsets is equal.

Example 1:

Input: {1, 2, 3, 4}
Output: True
Explanation: The given set can be partitioned into two subsets with equal sum: {1, 4} & {2, 3}
Example 2:

Input: {1, 1, 3, 4, 7}
Output: True
Explanation: The given set can be partitioned into two subsets with equal sum: {1, 3, 4} & {1, 7}
Example 3:

Input: {2, 3, 4, 6}
Output: False
Explanation: The given set cannot be partitioned into two subsets with equal sum.

Basic Solution#
This problem follows the 0/1 Knapsack pattern. A basic brute-force solution could be to try all combinations of partitioning the given numbers into two sets to see if any pair of sets has an equal sum.

Assume that S represents the total sum of all the given numbers. Then the two equal subsets must have a sum equal to S/2. This essentially transforms our problem to: "Find a subset of the given numbers that has a total sum of S/2".


Time and Space complexity#
The time complexity of the above algorithm is exponential O(2^n)O(2
​n
​​ ), where ‘n’ represents the total number. The space complexity is O(n)O(n), which will be used to store the recursion stack.

*/

using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
public:
    bool canPartition(const vector<int>& num) {
        //TODO: Write - Your - Code
        if (num.size() < 2)
            return false;

        int sum = 0;
        for (int n : num)
            sum += n;

        if (sum % 2)
            return false;

        return canPartitionRecursive(num, sum / 2, 0);
    }

    bool canPartitionRecursive(const vector<int>& num, int sum, int currentIndex) {
        // base cases:
        if (sum == 0)
            return true;

        // corner cases:
        if (num.empty() || currentIndex >= num.size())
            return false;

        // recursive call after choosing the number at the currentIndex
        // if the number at currentIndex exceeds the sum, we shouldn't process this
        if (num[currentIndex] <= sum) {
            if (canPartitionRecursive(num, sum - num[currentIndex], currentIndex + 1)) {
                return true;
            }
        }

        // recursive call after excluding the number at the currentIndex
        return canPartitionRecursive(num, sum, currentIndex + 1);
    }
};

int main(int argc, char* argv[]) {
    PartitionSet ps;
    vector<int> num = { 1, 2, 3, 4 };
    cout << ps.canPartition(num) << endl;
    num = vector<int>{ 1, 1, 3, 4, 7 };
    cout << ps.canPartition(num) << endl;
    num = vector<int>{ 2, 3, 4, 6 };
    cout << ps.canPartition(num) << endl;
}