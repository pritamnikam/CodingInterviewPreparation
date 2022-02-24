#include <iostream>

#include <queue>
#include <vector>

using namespace std;

vector<int> FirstNegativeNumber(vector<int>& nums, int k) {
	vector<int> answer;
	queue<int> q;
	int i = 0, j = 0, n = nums.size();

	while (j < n) {
		if (nums[j] < 0)
			q.push(nums[j]);

		if (j - i + 1 < k)
			++j;

		else if (j - i + 1 == k) {
			answer.emplace_back(q.empty() ? 0 : q.front());
		}
		else {
			if (q.front() < 0)
				q.pop();
			++i;
			++j;
		}
	}

	return answer;
}