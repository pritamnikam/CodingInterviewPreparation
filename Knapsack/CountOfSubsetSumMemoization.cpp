/*
Top-down Dynamic Programming with Memoization #
We can use memoization to overcome the overlapping sub-problems. We will be using a two-dimensional array to store the results of solved sub-problems. As mentioned above, we need to store results for every subset and for every possible sum.


*/

using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
    virtual int countSubsets(const vector<int>& num, int sum) {
        vector<vector<int>> dp(num.size(), vector<int>(sum + 1, -1));
        return this->countSubsetsRecursive(dp, num, sum, 0);
    }

private:
    int countSubsetsRecursive(vector<vector<int>>& dp, const vector<int>& num, int sum,
        int currentIndex) {
        // base checks
        if (sum == 0) {
            return 1;
        }

        if (num.empty() || currentIndex >= num.size()) {
            return 0;
        }

        // check if we have not already processed a similar problem
        if (dp[currentIndex][sum] == -1) {
            // recursive call after choosing the number at the currentIndex
            // if the number at currentIndex exceeds the sum, we shouldn't process this
            int sum1 = 0;
            if (num[currentIndex] <= sum) {
                sum1 = countSubsetsRecursive(dp, num, sum - num[currentIndex], currentIndex + 1);
            }

            // recursive call after excluding the number at the currentIndex
            int sum2 = countSubsetsRecursive(dp, num, sum, currentIndex + 1);

            dp[currentIndex][sum] = sum1 + sum2;
        }

        return dp[currentIndex][sum];
    }
};

int main(int argc, char* argv[]) {
    SubsetSum ss;
    vector<int> num = { 1, 1, 2, 3 };
    cout << ss.countSubsets(num, 4) << endl;
    num = vector<int>{ 1, 2, 7, 1, 5 };
    cout << ss.countSubsets(num, 9) << endl;
}