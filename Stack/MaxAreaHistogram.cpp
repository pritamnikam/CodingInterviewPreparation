#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> NearestSmallerToRightIndices(vector<int>& nums) {
	vector<int> vt;
	stack<pair<int, int>> st;
	int n = nums.size();

	for (int i = n - 1; i >= 0; --i) {
		if (st.empty()) {
			vt.emplace_back(n);
		}
		else if (st.top().first > nums[i]) {
			vt.emplace_back(st.top().second);
		}
		else {
			while (!st.empty() && st.top().first <= nums[i])
				st.pop();

			vt.emplace_back(st.empty() ? -1 : st.top().second);
		}

		st.push({ nums[i], i });
	}

	reverse(begin(vt), end(vt));
	return vt;
}

vector<int> NearestSmallerToLeftIndices(vector<int>& nums) {
	vector<int> vt;
	stack<pair<int, int>> st;
	int n = nums.size();

	for (int i = 0; i < n; ++i) {
		if (st.empty()) {
			vt.push_back(-1);
		}
		else if (st.top().first < nums[i]) {
			vt.push_back(st.top().second);
		}
		else {
			while (!st.empty() && st.top().first >= nums[i])
				st.pop();

			vt.push_back(st.empty() ? - 1: st.top().second);
		}

		st.push({ nums[i], i });
	}

	return vt;
}

int MaxAreaOfHistogram(vector<int>& heights) {
	// Get the NearestSmallerToRight indices & NearestSmallerToLeft indices
	vector<int> right = NearestSmallerToRightIndices(heights);
	vector<int> left = NearestSmallerToLeftIndices(heights);
	int n = heights.size();
	int answer = 0;
	for (int i = 0; i < n; ++i) {
		int width = right[i] - left[i] - 1;
		int area = width * heights[i];
		answer = max(answer, area);
	}

	return answer;
}
