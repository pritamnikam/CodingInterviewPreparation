#if 0
Triplet Sum to Zero(medium)


Problem Statement #
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Example 1:

Input: [-3, 0, 1, 2, -1, 1, -2]
Output : [-3, 1, 2] , [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation : There are four unique triplets whose sum is equal to zero.
Example 2 :

	Input : [-5, 2, -1, -2, 3]
	Output : [[-5, 2, 3], [-2, -1, 3]]
	Explanation : There are two unique triplets whose sum is equal to zero.



#endif

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

#if 0

class TripletSumToZero {
    static void searchPairWithTargetSum(vector<int>& arr, int index, vector<vector<int>>& triplets) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            if (left == index) { ++left; }
            else if (right == index) { --right; }
            else if (arr[left] + arr[right] == -arr[index]) {
                vector<int> vt({ arr[index], arr[left], arr[right] });
                sort(vt.begin(), vt.end());
                triplets.emplace_back(vt);
                ++left; --right;
            }
            else if (arr[left] + arr[right] < -arr[index]) {
                ++left;
            }
            else {
                --right;
            }
        }
    }

    static void RemoveDuplicates(vector<vector<int>>& triplets) {
        sort(triplets.begin(), triplets.end());
        auto it = unique(triplets.begin(), triplets.end());
        triplets.resize(std::distance(triplets.begin(), it));
    }

public:
    static vector<vector<int>> searchTriplets(vector<int>& arr) {
        vector<vector<int>> triplets;
        // TODO: Write your code here
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i) {
            searchPairWithTargetSum(arr, i, triplets);
        }

        // Remove duplicates
        RemoveDuplicates(triplets);
        return triplets;
    }
};
#endif

#if 0
Solution #
This problem follows the Two Pointers patternand shares similarities with Pair with Target Sum.A couple of differences are that the input array is not sorted and instead of a pair we need to find triplets with a target sum of zero.

To follow a similar approach, first, we will sort the arrayand then iterate through it taking one number at a time.Let’s say during our iteration we are at number ‘X’, so we need to find ‘Y’and ‘Z’ such that X + Y + Z == 0X + Y + Z == 0. At this stage, our problem translates into finding a pair whose sum is equal to “ - X−X”(as from the above equation Y + Z == -XY + Z == −X).

Another difference from Pair with Target Sum is that we need to find all the unique triplets.To handle this, we have to skip any duplicate number.Since we will be sorting the array, so all the duplicate numbers will be next to each otherand are easier to skip.

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
public:
    static vector<vector<int>> searchTriplets(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> triplets;
        for (int i = 0; i < arr.size() - 2; i++) {
            if (i > 0 && arr[i] == arr[i - 1]) { // skip same element to avoid duplicate triplets
                continue;
            }
            searchPair(arr, -arr[i], i + 1, triplets);
        }

        return triplets;
    }

private:
    static void searchPair(const vector<int>& arr, int targetSum, int left,
        vector<vector<int>>& triplets) {
        int right = arr.size() - 1;
        while (left < right) {
            int currentSum = arr[left] + arr[right];
            if (currentSum == targetSum) { // found the pair
                triplets.push_back({ -targetSum, arr[left], arr[right] });
                left++;
                right--;
                while (left < right && arr[left] == arr[left - 1]) {
                    left++; // skip same element to avoid duplicate triplets
                }
                while (left < right && arr[right] == arr[right + 1]) {
                    right--; // skip same element to avoid duplicate triplets
                }
            }
            else if (targetSum > currentSum) {
                left++; // we need a pair with a bigger sum
            }
            else {
                right--; // we need a pair with a smaller sum
            }
        }
    }
};

int main(int argc, char* argv[]) {
    vector<int> vec = { -3, 0, 1, 2, -1, 1, -2 };
    auto result = TripletSumToZero::searchTriplets(vec);
    for (auto vec : result) {
        cout << "[";
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << "]";
    }
    cout << endl;

    vec = { -5, 2, -1, -2, 3 };
    result = TripletSumToZero::searchTriplets(vec);
    for (auto vec : result) {
        cout << "[";
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << "]";
    }
}
#endif

class TripletSumToZero {
    static void SortAndRemoveDuplicates(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        // auto it = unique(arr.begin(), arr.end());
        // arr.resize(distance(arr.begin(), it));
    }

    static void TwoSum(vector<int>& arr, int index, vector<vector<int>>& triplets) {
        int left = index + 1, right = arr.size() - 1;
        while (left < right) {
            if (arr[left] + arr[right] == -arr[index]) {
                vector<int> vt({ arr[index], arr[left], arr[right] });
                triplets.emplace_back(vt);
                ++left;
                --right;

                while (left < right && arr[left] == arr[left - 1]) {
                    left++; // skip same element to avoid duplicate triplets
                }

                while (left < right && arr[right] == arr[right + 1]) {
                    right--; // skip same element to avoid duplicate triplets
                }
            }
            else if (arr[left] + arr[right] < -arr[index]) {
                ++left;
            }
            else {
                --right;
            }
        }
    }
public:

    static vector<vector<int>> searchTriplets(vector<int>& arr) {
        SortAndRemoveDuplicates(arr);

        vector<vector<int>> triplets;
        for (int i = 0; i < arr.size() - 2; ++i) {
            if (i > 0 && arr[i] == arr[i - 1]) { // skip same element to avoid duplicate triplets
                continue;
            }

            TwoSum(arr, i, triplets);
        }

        return triplets;
    }
};