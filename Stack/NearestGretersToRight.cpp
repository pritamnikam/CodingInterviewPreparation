#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> NearestGreaterToRight(vector<int>& nums) {
	vector<int> vt;
	stack<int> st;
	int n = nums.size();
	for (int i = n - 1; i >= 0; --i) {
		if (st.empty())
			vt.emplace_back(-1);
		else if (st.top() > nums[i])
			vt.emplace_back(st.top());
		else {
			while (!st.empty() && st.top() <= nums[i])
				st.pop();

			vt.emplace_back(st.empty() ? -1 : st.top());
		}

		st.push(nums[i]);
	}

	reverse(begin(vt), end(vt));
	return vt;
}