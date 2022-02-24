#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// O(nlogk)
vector<int> SortNearlySortedArray(vector<int>& nums, int k) {
	vector<int> result;
	priority_queue<int> mh;
	for (int n : nums) {
		mh.push(n);
		if (mh.size() == k) {
			result.emplace_back(mh.top());
			mh.pop();
		}
	}

	while (!mh.empty()) {
		result.emplace_back(mh.top());
		mh.pop();
	}

	return result;
}