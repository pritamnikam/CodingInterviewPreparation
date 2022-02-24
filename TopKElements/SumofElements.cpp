#if 0

Sum of Elements

Problem Statement#
Given an array, find the sum of all numbers between the K1’thand K2’th smallest elements of that array.

Example 1:

Input: [1, 3, 12, 5, 15, 11] , and K1 = 3, K2 = 6
Output : 23
Explanation : The 3rd smallest number is 5 and 6th smallest number 15. The sum of numbers coming
between 5 and 15 is 23 (11 + 12).
Example 2 :

	Input : [3, 5, 8, 7] , and K1 = 1, K2 = 4
	Output : 12
	Explanation : The sum of the numbers between the 1st smallest number(3) and the 4th smallest
	number(8) is 12 (5 + 7).
#endif


	using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class SumOfElements {
public:
	static int findElement(const vector<int>& nums, int k) {
		priority_queue<int> pq;
		for(int n: nums) {
			pq.push(n);
			if (pq.size() > k)
				pq.pop();
		}

		return pq.top();
	}

	static int findSumOfElements(const vector<int>& nums, int k1, int k2) {
		int elementSum = 0;
		// TODO: Write your code here
		int p1 = findElement(nums, k1);
		int p2 = findElement(nums, k2);

		for (int n : nums) {
			if (n > p1 && n < p2)
				elementSum += n;
		}

		return elementSum;
	}
};

int main(int argc, char* argv[]) {
	int result = SumOfElements::findSumOfElements(vector<int>{1, 3, 12, 5, 15, 11}, 3, 6);
	cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;

	result = SumOfElements::findSumOfElements(vector<int>{3, 5, 8, 7}, 1, 4);
	cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;
}

#if 0
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class SumOfElements {
public:
	struct numCompare {
		bool operator()(const int& x, const int& y) { return x > y; }
	};

	static int findSumOfElements(const vector<int>& nums, int k1, int k2) {
		priority_queue<int, vector<int>, numCompare> minHeap;

		// insert all numbers to the min heap
		for (int i = 0; i < nums.size(); i++) {
			minHeap.push(nums[i]);
		}

		// remove k1 small numbers from the min heap
		for (int i = 0; i < k1; i++) {
			minHeap.pop();
		}

		int elementSum = 0;
		// sum next k2-k1-1 numbers
		for (int i = 0; i < k2 - k1 - 1; i++) {
			elementSum += minHeap.top();
			minHeap.pop();
		}

		return elementSum;
	}
};

int main(int argc, char* argv[]) {
	int result = SumOfElements::findSumOfElements(vector<int>{1, 3, 12, 5, 15, 11}, 3, 6);
	cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;

	result = SumOfElements::findSumOfElements(vector<int>{3, 5, 8, 7}, 1, 4);
	cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;
}
#endif