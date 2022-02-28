/*
Bottom-up Dynamic Programming#
We’ll try to find if we can make all possible sums with every subset to populate the array dp[TotalNumbers][S+1].

For every possible sum ‘s’ (where 0 <= s <= S), we have two options:

Exclude the number. In this case, we will see if we can get the sum ‘s’ from the subset excluding this number => dp[index-1][s]
Include the number if its value is not more than ‘s’. In this case, we will see if we can find a subset to get the remaining sum => dp[index-1][s-num[index]]
If either of the above two scenarios returns true, we can find a subset with a sum equal to ‘s’.

Let’s draw this visually, with the example input {1, 2, 3, 7}, and start with our base case of size zero:

Time and Space complexity#
The above solution has the time and space complexity of O(N*S)O(N∗S), where ‘N’ represents total numbers and ‘S’ is the required sum.


*/

using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
    virtual bool canPartition(const vector<int>& num, int sum) {
        int n = num.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1));

        // populate the sum=0 columns, as we can always form '0' sum with an empty set
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // with only one number, we can form a subset only when the required sum is equal to its value
        for (int s = 1; s <= sum; s++) {
            dp[0][s] = (num[0] == s ? true : false);
        }

        // process all subsets for all sums
        for (int i = 1; i < num.size(); i++) {
            for (int s = 1; s <= sum; s++) {
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

        // the bottom-right corner will have our answer.
        return dp[num.size() - 1][sum];
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

/*
* 
* 
Challenge#
Can we improve our bottom-up DP solution even further? Can you find an algorithm that has O(S)O(S) space complexity?


using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
public:
  bool canPartition(const vector<int> &num, int sum) {
    int n = num.size();
    vector<bool> dp(sum + 1);

    // handle sum=0, as we can always have '0' sum with an empty set
    dp[0] = true;

    // with only one number, we can have a subset only when the required sum is equal to its value
    for (int s = 1; s <= sum; s++) {
      dp[s] = (num[0] == s ? true : false);
    }

    // process all subsets for all sums
    for (int i = 1; i < n; i++) {
      for (int s = sum; s >= 0; s--) {
        // if dp[s]==true, this means we can get the sum 's' without num[i], hence we can move on to
        // the next number else we can include num[i] and see if we can find a subset to get the
        // remaining sum
        if (!dp[s] && s >= num[i]) {
          dp[s] = dp[s - num[i]];
        }
      }
    }

    return dp[sum];
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 2, 3, 7};
  cout << ss.canPartition(num, 6) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.canPartition(num, 10) << endl;
  num = vector<int>{1, 3, 4, 8};
  cout << ss.canPartition(num, 6) << endl;
}
*/