#if 0
Maximum Distinct Elements

Problem Statement#
Given an array of numbersand a number ‘K’, we need to remove ‘K’ numbers from the array such that we are left with maximum distinct numbers.

Example 1:

Input: [7, 3, 5, 8, 5, 3, 3] , and K = 2
Output : 3
Explanation : We can remove two occurrences of 3 to be left with 3 distinct numbers[7, 3, 8], we have to skip 5 because it is not distinct and appeared twice.

Another solution could be to remove one instance of '5' and '3' each to be left with three distinct numbers[7, 5, 8], in this case, we have to skip 3 because it appeared twice.
Example 2:

Input: [3, 5, 12, 11, 12] , and K = 3
Output : 2
Explanation : We can remove one occurrence of 12, after which all numbers will become distinct.Then we can delete any two numbers which will leave us 2 distinct numbers in the result.

Example 3 :

Input : [1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5] , and K = 2
Output : 3
Explanation : We can remove one occurrence of '4' to get three distinct numbers.


Solution#
This problem follows the Top ‘K’ Numbers pattern, and shares similarities with Top ‘K’ Frequent Numbers.

We can following a similar approach as discussed in Top ‘K’ Frequent Numbers problem :

First, we will find the frequencies of all the numbers.
Then, push all numbers that are not distinct(i.e., have a frequency higher than one) in a Min Heap based on their frequencies.At the same time, we will keep a running count of all the distinct numbers.
Following a greedy approach, in a stepwise fashion, we will remove the least frequent number from the heap(i.e., the top element of the min - heap), and try to make it distinct.We will see if we can remove all occurrences of a number except one.If we can, we will increment our running count of distinct numbers.We have to also keep a count of how many removals we have done.
If after removing elements from the heap, we are still left with some deletions, we have to remove some distinct elements.


#endif

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class MaximumDistinctElements {
public:
    struct valueCompare {
        bool operator()(const pair<int, int>& x, const pair<int, int>& y) {
            return x.second > y.second;
        }
    };

    static int findMaximumDistinctElements(const vector<int>& nums, int k) {
        int distinctElementsCount = 0;
        if (nums.size() <= k) {
            return distinctElementsCount;
        }

        // find the frequency of each number
        unordered_map<int, int> numFrequencyMap;
        for (auto i : nums) {
            numFrequencyMap[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, valueCompare> minHeap;

        // insert all numbers with frequency greater than '1' into the min-heap
        for (auto entry : numFrequencyMap) {
            if (entry.second == 1) {
                distinctElementsCount++;
            }
            else {
                minHeap.push(entry);
            }
        }

        // following a greedy approach, try removing the least frequent numbers first from the min-heap
        while (k > 0 && !minHeap.empty()) {
            auto entry = minHeap.top();
            minHeap.pop();
            // to make an element distinct, we need to remove all of its occurrences except one
            k -= entry.second - 1;
            if (k >= 0) {
                distinctElementsCount++;
            }
        }

        // if k > 0, this means we have to remove some distinct numbers
        if (k > 0) {
            distinctElementsCount -= k;
        }

        return distinctElementsCount;
    }
};

int main(int argc, char* argv[]) {
    int result =
        MaximumDistinctElements::findMaximumDistinctElements(vector<int>{7, 3, 5, 8, 5, 3, 3}, 2);
    cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

    result = MaximumDistinctElements::findMaximumDistinctElements(vector<int>{3, 5, 12, 11, 12}, 3);
    cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

    result = MaximumDistinctElements::findMaximumDistinctElements(
        vector<int>{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2);
    cout << "Maximum distinct numbers after removing K numbers: " << result << endl;
}