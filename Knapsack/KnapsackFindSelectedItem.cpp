/*
How can we find the selected items?#
As we know, the final profit is at the bottom-right corner. Therefore, we will start from there to find the items that will be going into the knapsack.

As you remember, at every step, we had two options: include an item or skip it. If we skip an item, we take the profit from the remaining items (i.e., from the cell right above it); if we include the item, then we jump to the remaining profit to find more items.

‘22’ did not come from the top cell (which is 17); hence we must include the item at index ‘3’ (which is item ‘D’).
Subtract the profit of item ‘D’ from ‘22’ to get the remaining profit ‘6’. We then jump to profit ‘6’ on the same row.
‘6’ came from the top cell, so we jump to row ‘2’.
Again, ‘6’ came from the top cell, so we jump to row ‘1’.
‘6’ is different from the top cell, so we must include this item (which is item ‘B’).
Subtract the profit of ‘B’ from ‘6’ to get profit ‘0’. We then jump to profit ‘0’ on the same row. As soon as we hit zero remaining profit, we can finish our item search.
Thus, the items going into the knapsack are {B, D}.

*/

using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
public:
    virtual int solveKnapsack(const vector<int>& profits, vector<int>& weights, int capacity) {
        // base checks
        if (capacity <= 0 || profits.empty() || weights.size() != profits.size()) {
            return 0;
        }

        int n = profits.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1));

        // populate the capacity=0 columns, with '0' capacity we have '0' profit
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }

        // if we have only one weight, we will take it if it is not more than the
        // capacity
        for (int c = 0; c <= capacity; c++) {
            if (weights[0] <= c) {
                dp[0][c] = profits[0];
            }
        }

        // process all sub-arrays for all the capacities
        for (int i = 1; i < n; i++) {
            for (int c = 1; c <= capacity; c++) {
                int profit1 = 0, profit2 = 0;
                // include the item, if it is not more than the capacity
                if (weights[i] <= c) {
                    profit1 = profits[i] + dp[i - 1][c - weights[i]];
                }
                // exclude the item
                profit2 = dp[i - 1][c];
                // take maximum
                dp[i][c] = max(profit1, profit2);
            }
        }

        printSelectedElements(dp, weights, profits, capacity);
        // maximum profit will be at the bottom-right corner.
        return dp[n - 1][capacity];
    }

private:
    void printSelectedElements(vector<vector<int>>& dp, const vector<int>& weights,
        const vector<int>& profits, int capacity) {
        cout << "Selected weights:";
        int totalProfit = dp[weights.size() - 1][capacity];
        for (int i = weights.size() - 1; i > 0; i--) {
            if (totalProfit != dp[i - 1][capacity]) {
                cout << " " << weights[i];
                capacity -= weights[i];
                totalProfit -= profits[i];
            }
        }

        if (totalProfit != 0) {
            cout << " " << weights[0];
        }
        cout << "" << endl;
    }
};

int main(int argc, char* argv[]) {
    Knapsack ks;
    vector<int> profits = { 1, 6, 10, 16 };
    vector<int> weights = { 1, 2, 3, 5 };
    int maxProfit = ks.solveKnapsack(profits, weights, 7);
    cout << "Total knapsack profit ---> " << maxProfit << endl;
    maxProfit = ks.solveKnapsack(profits, weights, 6);
    cout << "Total knapsack profit ---> " << maxProfit << endl;
}