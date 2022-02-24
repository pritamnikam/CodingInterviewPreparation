#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> KLargestElements(vector<int>& nums, int k) {
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int n : nums) {
		minHeap.push(n);
		if (minHeap.size() == k)
			minHeap.pop();
	}

	vector<int> answer;
	while (!minHeap.empty()) {
		answer.emplace_back(minHeap.top());
		minHeap.pop();
	}
	return answer;
}