/*
Bottom-up Dynamic Programming #
We will try to find if we can make all possible sums with every subset to populate the array db[TotalNumbers][S+1].

So, at every step we have two options:

Exclude the number. Count all the subsets without the given number up to the given sum => dp[index-1][sum]
Include the number if its value is not more than the ‘sum’. In this case, we will count all the subsets to get the remaining sum => dp[index-1][sum-num[index]]
To find the total sets, we will add both of the above two values:

    dp[index][sum] = dp[index-1][sum] + dp[index-1][sum-num[index]])
Let’s start with our base case of size zero:

Time and Space complexity #
The above solution has the time and space complexity of O(N*S)O(N∗S), where ‘N’ represents total numbers and ‘S’ is the desired sum.


*/

using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
    virtual int countSubsets(const vector<int>& num, int sum) {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        // populate the sum=0 columns, as we will always have an empty set for zero sum
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        // with only one number, we can form a subset only when the required sum is
        // equal to its value
        for (int s = 1; s <= sum; s++) {
            dp[0][s] = (num[0] == s ? 1 : 0);
        }

        // process all subsets for all sums
        for (int i = 1; i < num.size(); i++) {
            for (int s = 1; s <= sum; s++) {
                // exclude the number
                dp[i][s] = dp[i - 1][s];
                // include the number, if it does not exceed the sum
                if (s >= num[i]) {
                    dp[i][s] += dp[i - 1][s - num[i]];
                }
            }
        }

        // the bottom-right corner will have our answer.
        return dp[num.size() - 1][sum];
    }
};

int main(int argc, char* argv[]) {
    SubsetSum ss;
    vector<int> num = { 1, 1, 2, 3 };
    cout << ss.countSubsets(num, 4) << endl;
    num = vector<int>{ 1, 2, 7, 1, 5 };
    cout << ss.countSubsets(num, 9) << endl;
}

/*

Challenge #
Can we improve our bottom-up DP solution even further? Can you find an algorithm that has O(S)O(S) space complexity?


*/

using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
    static int countSubsets(const vector<int>& num, int sum) {
        int n = num.size();
        vector<int> dp(sum + 1);
        dp[0] = 1;

        // with only one number, we can form a subset only when the required sum is
        // equal to its value
        for (int s = 1; s <= sum; s++) {
            dp[s] = (num[0] == s ? 1 : 0);
        }

        // process all subsets for all sums
        for (int i = 1; i < num.size(); i++) {
            for (int s = sum; s >= 0; s--) {
                if (s >= num[i]) {
                    dp[s] += dp[s - num[i]];
                }
            }
        }

        return dp[sum];
    }
};

int main(int argc, char* argv[]) {
    SubsetSum ss;
    vector<int> num = { 1, 1, 2, 3 };
    cout << ss.countSubsets(num, 4) << endl;
    num = vector<int>{ 1, 2, 7, 1, 5 };
    cout << ss.countSubsets(num, 9) << endl;
}