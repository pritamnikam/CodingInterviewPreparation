/*
Top-down Dynamic Programming with Memoization

We can use memoization to overcome the overlapping sub-problems.

We will be using a two-dimensional array to store the results of the solved sub-problems. 
We can uniquely identify a sub-problem from ‘currentIndex’ and ‘Sum1’ as ‘Sum2’ will always be the sum of the remaining numbers.


*/

using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
public:
    int canPartition(const vector<int>& num) {
        int sum = 0;
        for (int i = 0; i < num.size(); i++) {
            sum += num[i];
        }

        vector<vector<int>> dp(num.size(), vector<int>(sum + 1, -1));
        return this->canPartitionRecursive(dp, num, 0, 0, 0);
    }

private:
    int canPartitionRecursive(vector<vector<int>>& dp, const vector<int>& num, int currentIndex,
        int sum1, int sum2) {
        // base check
        if (currentIndex == num.size()) {
            return abs(sum1 - sum2);
        }

        // check if we have not already processed similar problem
        if (dp[currentIndex][sum1] == -1) {
            // recursive call after including the number at the currentIndex in the first set
            int diff1 = canPartitionRecursive(dp, num, currentIndex + 1, sum1 + num[currentIndex], sum2);

            // recursive call after including the number at the currentIndex in the second set
            int diff2 = canPartitionRecursive(dp, num, currentIndex + 1, sum1, sum2 + num[currentIndex]);

            dp[currentIndex][sum1] = min(diff1, diff2);
        }

        return dp[currentIndex][sum1];
    }
};

int main(int argc, char* argv[]) {
    PartitionSet ps;
    vector<int> num = { 1, 2, 3, 9 };
    cout << ps.canPartition(num) << endl;
    num = vector<int>{ 1, 2, 7, 1, 5 };
    cout << ps.canPartition(num) << endl;
    num = vector<int>{ 1, 3, 100, 4 };
    cout << ps.canPartition(num) << endl;
}