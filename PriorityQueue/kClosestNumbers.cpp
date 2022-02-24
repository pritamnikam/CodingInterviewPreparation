#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> kClosestNumber(vector<int>& nums, int k, int x) {
	vector<int> result;
	priority_queue<pair<int, int>> mh;   // key - abs(diff), val - number  -> max heap
	for (int n : nums) {
		mh.push({ abs(n - x), n });
		if (mh.size() == k) {
			result.emplace_back(mh.top());
			mh.pop();
		}
	}

	while (result.size() < k && !mh.empty()) {
		result.emplace_back(mh.top());
		mh.pop();
	}

	return result;
}