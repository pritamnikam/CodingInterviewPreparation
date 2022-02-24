#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int KthSmallestElement(vector<int>& nums, int k) {
	priority_queue<int> maxHeap;
	for (int n : nums) {
		maxHeap.push(n);
		if (maxHeap.size() == k)
			maxHeap.pop();
	}

	return maxHeap.top();
}
