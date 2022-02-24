#include <iostream>

#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int LargestSubarrayOfSumK(vector<int>& nums, int k) {
	int i = 0, j = 0, n = nums.size(), maxCount = 0, sum = 0;
	while (j < n) {
		sum += nums[j];

		if (sum < k) {
			++j;
		}
		else if (sum == k) {
			maxCount = max(maxCount, j - i + 1);
			++j;
		}
		else {
			while (sum > k) {
				sum -= nums[i];
				++i;
			}

			// check one more time before we proceed
			if (sum == k) {
				maxCount = max(maxCount, j - i + 1);
			}

			++j;
		}
	}

	return maxCount;
}