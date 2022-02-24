#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> AbsoluteGreatestToRight(vector<int>& heights) {
	int n = heights.size();
	vector<int> vt;
	vt[0] = heights[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		vt[i] = max(vt[i + 1], heights[i]);
	}

	reverse(begin(vt), end(vt));
	return vt;
}

vector<int> AbsoluteGreatestToLeft(vector<int>& heights) {
	int n = heights.size();
	vector<int> vt;

	vt[0] = heights[0];
	for (int i = 1; i < n; ++i) {
		vt[i] = max(vt[i - 1], heights[i]);
	}

	return vt;
}

int RainWaterTrapping(vector<int>& heights) {
	vector<int> left = AbsoluteGreatestToLeft(heights);
	vector<int> right = AbsoluteGreatestToRight(heights);
	int n = heights.size();

	int totalWaterTrapped = 0;
	for (int i = 0; i < n; ++i) {
		int waterTrapped = min(left[i], right[i]) - heights[i];
		totalWaterTrapped  += waterTrapped;
	}

	return totalWaterTrapped;
}