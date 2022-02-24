/*
373. Find K Pairs with Smallest Sums

https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.



Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]


Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in ascending order.
1 <= k <= 104


Time complexity#
Since, at most, we’ll be going through all the elements of both arrays and we will add/remove one element in the heap in each step, the time complexity of the above algorithm will be O(N*M*logK)O(N∗M∗logK) where ‘N’ and ‘M’ are the total number of elements in both arrays, respectively.

If we assume that both arrays have at least ‘K’ elements then the time complexity can be simplified to O(K^2logK)O(K
​2
​​ logK), because we are not iterating more than ‘K’ elements in both arrays.

Space complexity#
The space complexity will be O(K)O(K) because, at any time, our Min Heap will be storing ‘K’ largest pairs.


*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

typedef pair<int, int> pi;

struct Compare {
    bool operator()(const pi& x, const pi& y) {
        return x.first + x.second < y.first + y.second;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        // TODO: Write your code here
        priority_queue<pi, vector<pi>, Compare> maxHeap;
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            for (int j = 0; j < nums2.size() && j < k; ++j) {
                if (maxHeap.size() < k) {
                    maxHeap.push({ nums1[i], nums2[j] });
                }
                else {
                    // if the sum of the two numbers from the two arrays is greater than the smallest (top)
                    // element of the heap, we can 'break' here. Since the arrays are sorted in the ascending
                    // order, we'll not be able to find a pair with a smaller sum moving forward.
                    if (nums1[i] + nums2[j] > maxHeap.top().first + maxHeap.top().second) {
                        break;
                    }
                    else {
                        // else: we have a pair with a smaller sum, remove top and insert this pair in the heap
                        maxHeap.pop();
                        maxHeap.push({ nums1[i], nums2[j] });
                    }
                }
            }
        }

        while (!maxHeap.empty()) {
            vector<int> vt({ maxHeap.top().first, maxHeap.top().second });
            result.emplace_back(vt);
            maxHeap.pop();
        }

        return result;
    }
};