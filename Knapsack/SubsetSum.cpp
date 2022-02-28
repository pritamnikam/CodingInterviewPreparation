/*
Subset Sum

Problem Statement#
Given a set of positive numbers, determine if a subset exists whose sum is equal to a given number ‘S’.

Example 1:#
Input: {1, 2, 3, 7}, S=6
Output: True
The given set has a subset whose sum is '6': {1, 2, 3}

Example 2:#
Input: {1, 2, 7, 1, 5}, S=10
Output: True
The given set has a subset whose sum is '10': {1, 2, 7}

Example 3:#
Input: {1, 3, 4, 8}, S=6
Output: False
The given set does not have any subset whose sum is equal to '6'.


Basic Solution#
This problem follows the 0/1 Knapsack pattern and is quite similar to Equal Subset Sum Partition. A basic brute-force solution could be to try all subsets of the given numbers to see if any set has a sum equal to ‘S’.

So our brute-force algorithm will look like:

for each number 'i'
  create a new set which INCLUDES number 'i' if it does not exceed 'S', and recursively
     process the remaining numbers
  create a new set WITHOUT number 'i', and recursively process the remaining numbers
return true if any of the above two sets has a sum equal to 'S', otherwise return false

Since this problem is quite similar to Equal Subset Sum Partition, let’s jump directly to the bottom-up dynamic programming solution.


*/

using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
    virtual bool canPartition(const vector<int>& num, int sum) {
        // TODO: Write your code here
        return canPartition(num, sum, 0);
    }

    bool canPartition(const vector<int>& num, int sum, int currentIndex) {
        if (sum == 0) return true;

        if (num.empty() || currentIndex >= num.size())
            return false;

       
        if (sum >= num[currentIndex] && canPartition(num, sum - num[currentIndex], currentIndex + 1))
            return true;

        return canPartition(num, sum, currentIndex + 1);
    }
};

int main(int argc, char* argv[]) {
    SubsetSum ss;
    vector<int> num = { 1, 2, 3, 7 };
    cout << ss.canPartition(num, 6) << endl;
    num = vector<int>{ 1, 2, 7, 1, 5 };
    cout << ss.canPartition(num, 10) << endl;
    num = vector<int>{ 1, 3, 4, 8 };
    cout << ss.canPartition(num, 6) << endl;
}