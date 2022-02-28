/*
0/1 Knapsack

Introduction#
Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack with a capacity ‘C.’ The goal is to get the maximum profit out of the knapsack items. Each item can only be selected once, as we don’t have multiple quantities of any item.

Let’s take Merry’s example, who wants to carry some fruits in the knapsack to get maximum profit. Here are the weights and profits of the fruits:

Items: { Apple, Orange, Banana, Melon }
Weights: { 2, 3, 1, 4 }
Profits: { 4, 5, 3, 7 }
Knapsack capacity: 5

Let’s try to put various combinations of fruits in the knapsack, such that their total weight is not more than 5:

Apple + Orange (total weight 5) => 9 profit
Apple + Banana (total weight 3) => 7 profit
Orange + Banana (total weight 4) => 8 profit
Banana + Melon (total weight 5) => 10 profit

This shows that Banana + Melon is the best combination as it gives us the maximum profit, and the total weight does not exceed the capacity.

Problem Statement#
Given two integer arrays to represent weights and profits of ‘N’ items, we need to find a subset of these items which will give us maximum profit such that their cumulative weight is not more than a given number ‘C.’ Each item can only be selected once, which means either we put an item in the knapsack or we skip it.




*/
using namespace std;

#include <iostream>
#include <vector>

class Knapsack {
public:
    int solveKnapsack(const vector<int>& profits, vector<int>& weights, int capacity) {
        return this->knapsackRecursive(profits, weights, capacity, 0);
    }

private:
    int knapsackRecursive(const vector<int>& profits, vector<int>& weights, int capacity,
        int currentIndex) {
        // base checks
        if (capacity <= 0 || currentIndex >= profits.size()) {
            return 0;
        }

        // recursive call after choosing the element at the currentIndex
        // if the weight of the element at currentIndex exceeds the capacity, we shouldn't process this
        int profit1 = 0;
        if (weights[currentIndex] <= capacity) {
            profit1 =
                profits[currentIndex] +
                knapsackRecursive(profits, weights, capacity - weights[currentIndex], currentIndex + 1);
        }

        // recursive call after excluding the element at the currentIndex
        int profit2 = knapsackRecursive(profits, weights, capacity, currentIndex + 1);

        return max(profit1, profit2);
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