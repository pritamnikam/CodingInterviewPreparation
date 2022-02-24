#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
It's a variation of Maximum area of histogram.

we have to convert 2D to 1D and take the maximum area so far.

*/

int MaxAreaOfHistogram(vector<int>& heights);

int MaximumAreaRectangleInBinaryMatrix(vector<vector<int>>& matrix) {
	vector<int> heights;
	int rows = matrix.size();
	int cols = matrix[0].size();

	// 1st row
	for (int j = 0; j < cols; ++j) {
		heights[j] = matrix[0][j];
	}

	int maxArea = MaxAreaOfHistogram(heights);

	// for all remaining rows:
	for (int i = 1; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			// 2d - > 1D
			heights[j] += ((matrix[i][j] == 0) ? 0 : matrix[i][j]);
		}

		int area = MaxAreaOfHistogram(heights);
		maxArea = max(maxArea, area);
	}

	return maxArea;
}