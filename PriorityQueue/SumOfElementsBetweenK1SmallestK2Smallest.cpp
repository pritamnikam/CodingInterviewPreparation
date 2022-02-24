#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;


int KthSmallest(vector<int>& nums, int k) {
	priority_queue<int> mh;
	for (int n : nums) {
		mh.push(n);
		if (mh.size() == k) {
			mh.pop();
		}
	}

	return mh.top();
}

int SumOfElementsBetween2Smallets(vector<int>& nums, int k1, int k2) {
	int n1 = KthSmallest(nums, k1);
	int n2 = KthSmallest(nums, k2);

	int sum = 0;
	for (int n : nums) {
		if (n > n1 && n < n2)
			sum += n;
	}

	return sum;
}