#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
* Variation of Nearest Greter to the Left (NGL)
1. Find NGL index for all i, stack will hold pair<arr[i], i>
2. if st.empty() -> -1
3. if et.top().first > arr[i] then answer: (i - st.top().second)
4. otherwise, pop stack until we find top greater that arr[i]
*/

vector<int> StockSpan(vector<int>& nums) {
	vector<int> vt;
	stack<pair<int,int>> st;
	int n = nums.size();
	
	// NRL index
	for (int i = 0; i < n; ++i) {
		if (st.empty())
			vt.emplace_back(-1);
		if (st.top().first > nums[i]) {
			vt.emplace_back(i - st.top().second);
		}
		else {
			while (!st.empty() && st.top().first <= nums[i]) {
				st.pop();
			}

			vt.emplace_back(st.empty() ? -1 : i - st.top().second);
		}

		st.push({ nums[i], i });
	}
	return vt;
}
