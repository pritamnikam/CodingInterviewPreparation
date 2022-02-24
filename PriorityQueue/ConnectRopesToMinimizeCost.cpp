#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

int ConnectRopesToMinimizeCost(vector<int>& nums) {
	priority_queue<int, vector<int>, greater<int>> mh;
	for (int n : nums) {
		mh.push(n);
	}

	int totalCost = 0;
	while (mh.size() > 1) {
		int first = mh.top();
		mh.pop();

		int second = mh.top();
		mh.pop();

		totalCost += (first + second);
		mh.push(first + second);
	}

	return totalCost;
}