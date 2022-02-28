/*
Count of Subset Sum

Count of Subset Sum (hard) #
Given a set of positive numbers, find the total number of subsets whose sum is equal to a given number ‘S’.

Example 1: #
Input: {1, 1, 2, 3}, S=4
Output: 3
The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
Note that we have two similar sets {1, 3}, because we have two '1' in our input.

Example 2: #
Input: {1, 2, 7, 1, 5}, S=9
Output: 3
The given set has '3' subsets whose sum is '9': {2, 7}, {1, 7, 1}, {1, 2, 1, 5}

Basic Solution #
This problem follows the 0/1 Knapsack pattern and is quite similar to Subset Sum. The only difference in this problem is that we need to count the number of subsets, whereas in Subset Sum we only wanted to know if a subset with the given sum existed.

A basic brute-force solution could be to try all subsets of the given numbers to count the subsets that have a sum equal to ‘S’. So our brute-force algorithm will look like:


for each number 'i'
  create a new set which includes number 'i' if it does not exceed 'S', and recursively
      process the remaining numbers and sum
  create a new set without number 'i', and recursively process the remaining numbers
return the count of subsets who has a sum equal to 'S'


Time and Space complexity #
The time complexity of the above algorithm is exponential O(2^n)O(2
​n
​​ ), where ‘n’ represents the total number. The space complexity is O(n)O(n), this memory is used to store the recursion stack.


*/
using namespace std;

#include <iostream>
#include <vector>

// divide and conquer

class SubsetSum {
public:
    virtual int countSubsets(const vector<int>& num, int sum) {
        return this->countSubsetsRecursive(num, sum, 0);
    }

private:
    int countSubsetsRecursive(const vector<int>& num, int sum, int currentIndex) {
        // base checks
        if (sum == 0) {
            return 1;
        }

        if (num.empty() || currentIndex >= num.size()) {
            return 0;
        }

        // recursive call after selecting the number at the currentIndex
        // if the number at currentIndex exceeds the sum, we shouldn't process this
        int sum1 = 0;
        if (num[currentIndex] <= sum) {
            sum1 = countSubsetsRecursive(num, sum - num[currentIndex], currentIndex + 1);
        }

        // recursive call after excluding the number at the currentIndex
        int sum2 = countSubsetsRecursive(num, sum, currentIndex + 1);

        return sum1 + sum2;
    }
};

int main(int argc, char* argv[]) {
    SubsetSum ss;
    vector<int> num = { 1, 1, 2, 3 };
    cout << ss.countSubsets(num, 4) << endl;
    num = vector<int>{ 1, 2, 7, 1, 5 };
    cout << ss.countSubsets(num, 9) << endl;
}