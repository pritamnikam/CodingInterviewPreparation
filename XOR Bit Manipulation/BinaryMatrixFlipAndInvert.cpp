/*
Problem Statement(hard)#
Given a binary matrix representing an image, we want to flip the image horizontally, then invert it.

To flip an image horizontally means that each row of the image is reversed.For example, flipping[0, 1, 1] horizontally results in[1, 1, 0].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting[1, 1, 0] results in[0, 0, 1].

Example 1:

Input: [
[1, 0, 1],
[1, 1, 1],
[0, 1, 1]
]
Output : [
	[0, 1, 0],
		[0, 0, 0],
		[0, 0, 1]
]
Explanation : First reverse each row : [[1, 0, 1], [1, 1, 1], [1, 1, 0]] .Then, invert the image : [[0, 1, 0], [0, 0, 0], [0, 0, 1]]

Example 2 :

	Input : [
		[1, 1, 0, 0],
			[1, 0, 0, 1],
			[0, 1, 1, 1],
			[1, 0, 1, 0]
	]
	Output : [
		[1, 1, 0, 0],
			[0, 1, 1, 0],
			[0, 0, 0, 1],
			[1, 0, 1, 0]
	]
		Explanation : First reverse each row : [[0, 0, 1, 1], [1, 0, 0, 1], [1, 1, 1, 0], [0, 1, 0, 1]] .Then invert the image : [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 0, 1], [1, 0, 1, 0]]



Solution
Flip: We can flip the image in place by replacing ith element from left with the ith element from the right.
Invert: We can take XOR of each element with 1. If it is 1 then it will become 0 and if it is 0 then it will become 1.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int>> flipAndInvertImage(vector<vector<int>> arr) {
        int rows = arr.size();
        int cols = arr[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < (cols+1)/2; ++j) {
                int temp = arr[i][j] ^ 1;
                arr[i][j] = arr[i][cols - 1 - j] ^ 1;
                arr[i][cols - 1 - j] = temp;
            }
        }
        return arr;
    }

    static void print(const vector<vector<int>> arr) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> arr = vector<vector<int>>{ {1, 0, 1}, {1, 1, 1}, {0, 1, 1} };
    Solution::print(Solution::flipAndInvertImage(arr));
    cout << "\n";

    vector<vector<int>> arr2 = vector<vector<int>>{ {1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0} };
    Solution::print(Solution::flipAndInvertImage(arr2));
}