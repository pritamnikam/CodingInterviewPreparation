/*
Bottom-up Dynamic Programming#
Let’s assume ‘S’ represents the total sum of all the numbers. So, in this problem, we are trying to find a subset whose sum is as close to ‘S/2’ as possible, because if we can partition the given set into two subsets of an equal sum, we get the minimum difference, i.e. zero. This transforms our problem to Subset Sum, where we try to find a subset whose sum is equal to a given number-- ‘S/2’ in our case. If we can’t find such a subset, then we will take the subset which has the sum closest to ‘S/2’. This is easily possible, as we will be calculating all possible sums with every subset.

Essentially, we need to calculate all the possible sums up to ‘S/2’ for all numbers. So how can we populate the array db[TotalNumbers][S/2+1] in the bottom-up fashion?

For every possible sum ‘s’ (where 0 <= s <= S/2), we have two options:

Exclude the number. In this case, we will see if we can get the sum ‘s’ from the subset excluding this number => dp[index-1][s]
Include the number if its value is not more than ‘s’. In this case, we will see if we can find a subset to get the remaining sum => dp[index-1][s-num[index]]
If either of the two above scenarios is true, we can find a subset with a sum equal to ‘s’. We should dig into this before we can learn how to find the closest subset.

Let’s draw this visually, with the example input {1, 2, 3, 9}. Since the total sum is ‘15’, we will try to find a subset whose sum is equal to the half of it, i.e. ‘7’.

The above visualization tells us that it is not possible to find a subset whose sum is equal to ‘7’. So what is the closest subset we can find? We can find the subset if we start moving backwards in the last row from the bottom right corner to find the first ‘T’. The first “T” in the diagram above is the sum ‘6’, which means that we can find a subset whose sum is equal to ‘6’. This means the other set will have a sum of ‘9’ and the minimum difference will be ‘3’.

Time and Space complexity#
The above solution has the time and space complexity of O(N*S)O(N∗S), where ‘N’ represents total numbers and ‘S’ is the total sum of all the numbers.


*/

using namespace std;

#include <iostream>
#include <vector>

class PartitionSet {
public:
    virtual int canPartition(const vector<int>& num) {
        int sum = 0;
        for (int i = 0; i < num.size(); i++) {
            sum += num[i];
        }

        int n = num.size();
        vector<vector<bool>> dp(n, vector<bool>(sum / 2 + 1, false));

        // populate the sum=0 columns, as we can always form '0' sum with an empty set
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // with only one number, we can form a subset only when the sum is equal to that number
        for (int s = 0; s <= sum / 2; s++) {
            dp[0][s] = (num[0] == s ? true : false);
        }

        // process all subsets for all sums
        for (int i = 1; i < num.size(); i++) {
            for (int s = 1; s <= sum / 2; s++) {
                // if we can get the sum 's' without the number at index 'i'
                if (dp[i - 1][s]) {
                    dp[i][s] = dp[i - 1][s];
                }
                else if (s >= num[i]) {
                    // else include the number and see if we can find a subset to get the remaining sum
                    dp[i][s] = dp[i - 1][s - num[i]];
                }
            }
        }

        int sum1 = 0;
        // Find the largest index in the last row which is true
        for (int i = sum / 2; i >= 0; i--) {
            if (dp[n - 1][i] == true) {
                sum1 = i;
                break;
            }
        }

        int sum2 = sum - sum1;
        return abs(sum2 - sum1);
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