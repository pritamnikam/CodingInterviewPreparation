using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
public:
    static int findLength(const vector<char>& arr) {
        int maxLength = 0;
        // TODO: Write your code here
        int i = 0, j = 0, count = 0, n = arr.size(), k = 2;
        unordered_map<char, int> mp;
        while (j < n) {
            char ch = arr[j];
            mp[ch]++;
            count = mp.size();

            if (count < k) {
                ++j;
            }

            else if (count == k) {
                maxLength = max(maxLength, j - i + 1);
                ++j;
            }

            else {
                while (count > k) {
                    char ch = arr[i];
                    mp[ch]--;
                    if (mp[ch] == 0)
                        mp.erase(ch);
                    count = mp.size();
                    ++i;
                }

                if (count == k) {
                    maxLength = max(maxLength, j - i + 1);
                }

                ++j;

            }
        }
        return maxLength;
    }
};


#if 0

/*
https://www.educative.io/courses/grokking-the-coding-interview/Bn2KLlOR0lQ

This problem follows the Sliding Window pattern and is quite similar to Longest Substring with K Distinct Characters. 
In this problem, we need to find the length of the longest subarray with no more than two distinct characters 
(or fruit types!). This transforms the current problem into Longest Substring with K Distinct Characters where K=2.

*/

using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
public:
    static int findLength(const vector<char>& arr) {
        int windowStart = 0, maxLength = 0;
        unordered_map<char, int> fruitFrequencyMap;
        // try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
            fruitFrequencyMap[arr[windowEnd]]++;
            // shrink the sliding window, until we are left with '2' fruits in the frequency map
            while ((int)fruitFrequencyMap.size() > 2) {
                fruitFrequencyMap[arr[windowStart]]--;
                if (fruitFrequencyMap[arr[windowStart]] == 0) {
                    fruitFrequencyMap.erase(arr[windowStart]);
                }
                windowStart++;  // shrink the window
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};

int main(int argc, char* argv[]) {
    cout << "Maximum number of fruits: "
        << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'A', 'C'}) << endl;
    cout << "Maximum number of fruits: "
        << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'}) << endl;
}

#endif