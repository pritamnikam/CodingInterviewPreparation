#if 0
Subarrays with Product Less than a Target

Problem Statement#
Given an array with positive numbersand a positive target number, find all of its 
contiguous subarrays whose product is less than the target number.

Example 1:

Input: [2, 5, 3, 10] , target = 30
Output : [2] , [5], [2, 5], [3], [5, 3], [10]
Explanation : There are six contiguous subarrays whose product is less than the target.

Example 2 :
Input : [8, 2, 6, 5] , target = 50
Output : [8] , [2], [8, 2], [6], [2, 6], [5], [6, 5]
Explanation : There are seven contiguous subarrays whose product is less than the target.

Solution#
This problem follows the Sliding Window and the Two Pointers pattern and shares similarities 
with Triplets with Smaller Sum with two differences:
1. In this problem, the input array is not sorted.
2. Instead of finding triplets with sum less than a target, we need to find all subarrays having 
a product less than the target.

The implementation will be quite similar to Triplets with Smaller Sum.


#endif

using namespace std;

#include <deque>
#include <iostream>
#include <vector>

class SubarrayProductLessThanK {
public:
    static vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
        vector<vector<int>> result;
        double product = 1;
        int left = 0;
        for (int right = 0; right < arr.size(); right++) {
            product *= arr[right];
            while (product >= target && left < arr.size()) {
                product /= arr[left++];
            }
            // since the product of all numbers from left to right is less than the target therefore,
            // all subarrays from left to right will have a product less than the target too; to avoid
            // duplicates, we will start with a subarray containing only arr[right] and then extend it
            deque<int> tempList;
            for (int i = right; i >= left; i--) {
                tempList.push_front(arr[i]);
                vector<int> resultVec;
                std::move(std::begin(tempList), 
                          std::end(tempList), 
                          std::back_inserter(resultVec));

                result.push_back(resultVec);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    auto result = SubarrayProductLessThanK::findSubarrays(vector<int>{2, 5, 3, 10}, 30);
    for (auto vec : result) {
        cout << "[";
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << "]";
    }
    cout << endl;

    result = SubarrayProductLessThanK::findSubarrays(vector<int>{8, 2, 6, 5}, 50);
    for (auto vec : result) {
        cout << "[";
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << "]";
    }
}