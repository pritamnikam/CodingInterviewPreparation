#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> FrequencySort(vector<int>& nums) {
	vector<int> vt;
	priority_queue<pair<int, int>> mh; // key-freq, val-number -> max head
	unordered_map<int, int> mp;        // key-number, val-freq

	for (int n : nums) {
		mp[n]++;
	}

	for (auto it : mp) {
		mh.push({ it.second, it.first });
	}

	while (!mh.empty()) {
		vt.emplace_back(mh.top());
		mh.pop();
	}

	return vt;
}