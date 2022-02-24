using namespace std;

#include <iostream>
#include <vector>

class ReplacingOnes {
public:
    static int findLength(const vector<int>& arr, int k) {
        int  maxLength = 0;
        // TODO: Write your code here
        int i = 0, j = 0, maxOneCount = 0, n = arr.size();

        for (j = 0; j < n; ++j) {
            if (arr[j] == 1) {
                ++maxOneCount;
            }

            if (j - i + 1 - maxOneCount > k) {
                if (arr[i] == 1) {
                    --maxOneCount;
                }

                ++i;
            }


            maxLength = max(maxLength, j - i + 1);
        }
        return maxLength;
    }
};


#if 0
/*
https://www.educative.io/courses/grokking-the-coding-interview/B6VypRxPolJ

This problem follows the Sliding Window patternand is quite similar to Longest 
Substring with same Letters after Replacement.The only difference is that, in the problem,
we only have two characters(1s and 0s) in the input arrays.

Following a similar approach, we’ll iterate through the array to add one number at a time 
in the window.We’ll also keep track of the maximum number of repeating 1s in the current 
window(let’s call it maxOnesCount).So at any time, we know that we can have a window with 
1s repeating maxOnesCount time, so we should try to replace the remaining 0s.If we have 
more than ‘k’ remaining 0s, we should shrink the window as we are not allowed to replace 
more than ‘k’ 0s.

*/

using namespace std;

#include <iostream>
#include <vector>

class ReplacingOnes {
public:
    static int findLength(const vector<int>& arr, int k) {
        int windowStart = 0, maxLength = 0, maxOnesCount = 0;
        // try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
            if (arr[windowEnd] == 1) {
                maxOnesCount++;
            }

            // current window size is from windowStart to windowEnd, overall we have a maximum of 1s
            // repeating a maximum of 'maxOnesCount' times, this means that we can have a window with
            // 'maxOnesCount' 1s and the remaining are 0s which should replace with 1s.
            // now, if the remaining 0s are more than 'k', it is the time to shrink the window as we
            // are not allowed to replace more than 'k' Os
            if (windowEnd - windowStart + 1 - maxOnesCount > k) {
                if (arr[windowStart] == 1) {
                    maxOnesCount--;
                }
                windowStart++;
            }

            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};

int main(int argc, char* argv[]) {
    cout << ReplacingOnes::findLength(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2) << endl;
    cout << ReplacingOnes::findLength(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3) << endl;
}

#endif
