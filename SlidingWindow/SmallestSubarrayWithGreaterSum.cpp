using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
public:
	static int findMinSubArray(int S, const vector<int>& arr) {
		// TODO: Write your code here
		const int kINTMAX = 10000000;
		int result = kINTMAX;

		int sum = 0;
		int i = 0;
		int j = 0;
		int k = S;
		int n = arr.size();
		while (j < n) {
			// calculations:
			sum = sum + arr[j];

			// check the window reaching the sum.
			if (sum < k) {
				++j;
			}
			else {
				while (sum >= k) {
					result = min(result, j - i + 1);
					sum -= arr[i];
					++i;
				}

				// slide j
				++j;
			}
		}

		return (kINTMAX == result) ? 0 : result;
	}
};


#if 0
https://www.educative.io/courses/grokking-the-coding-interview/7XMlMEQPnnQ

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
public:
	static int findMinSubArray(int S, const vector<int>& arr) {
		int windowSum = 0, minLength = numeric_limits<int>::max();
		int windowStart = 0;
		for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
			windowSum += arr[windowEnd];  // add the next element
			// shrink the window as small as possible until the 'windowSum' is smaller than 'S'
			while (windowSum >= S) {
				minLength = min(minLength, windowEnd - windowStart + 1);
				windowSum -= arr[windowStart];  // subtract the element going out
				windowStart++;                  // slide the window ahead
			}
		}

		return minLength == numeric_limits<int>::max() ? 0 : minLength;
	}
};

int main(int argc, char* argv[]) {
	int result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
	cout << "Smallest subarray length: " << result << endl;
	result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 8});
	cout << "Smallest subarray length: " << result << endl;
	result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
	cout << "Smallest subarray length: " << result << endl;
}


#endif