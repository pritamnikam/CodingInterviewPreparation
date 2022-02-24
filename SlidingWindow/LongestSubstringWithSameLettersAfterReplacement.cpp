using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
public:
    static int findLength(const string& str, int k) {
        int maxLength = 0;
        // TODO: Write your code here
        int i = 0, j = 0, maxRepeatingCount = 0, n = str.length();
        unordered_map<char, int> mp;

        for (j = 0; j < n; ++j) {
            char ch = str[j];
            mp[ch]++;
            maxRepeatingCount = max(maxRepeatingCount, mp[ch]);

            // window size is greater than k, we have more than k other characters
            // that can be replaced
            if (j - i + 1 - maxRepeatingCount > k) {
                char ch = str[i];
                mp[ch]--;
                ++i;
            }

            // update the window size
            maxLength = max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};



#if 0

// https://www.educative.io/courses/grokking-the-coding-interview/R8DVgjq78yR

/*
We can use a HashMap to count the frequency of each letter.

We will iterate through the string to add one letter at a time in the window.
We will also keep track of the count of the maximum repeating letter in any window (let’s call it maxRepeatLetterCount).
So, at any time, we know that we do have a window with one letter repeating maxRepeatLetterCount times; this means we should try to replace the remaining letters.
If the remaining letters are less than or equal to k, we can replace them all.

If we have more than k remaining letters, we should shrink the window as we cannot replace more than k letters.

While shrinking the window, we don’t need to update maxRepeatLetterCount (hence, it represents the maximum repeating count of ANY letter for ANY window). Why don’t we need to update this count when we shrink the window? Since we have to replace all the remaining letters to get the longest substring having the same letter in any window, we can’t get a better answer from any other window even though all occurrences of the letter with frequency maxRepeatLetterCount is not in the current window.


*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class CharacterReplacement {
public:
    static int findLength(const string& str, int k) {
        int windowStart = 0, maxLength = 0, maxRepeatLetterCount = 0;
        unordered_map<char, int> letterFrequencyMap;
        // try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            char rightChar = str[windowEnd];
            letterFrequencyMap[rightChar]++;
            maxRepeatLetterCount = max(maxRepeatLetterCount, letterFrequencyMap[rightChar]);

            // current window size is from windowStart to windowEnd, overall we have a letter which is
            // repeating 'maxRepeatLetterCount' times, this means we can have a window which has one
            // letter repeating 'maxRepeatLetterCount' times and the remaining letters we should replace.
            // if the remaining letters are more than 'k', it is the time to shrink the window as we
            // are not allowed to replace more than 'k' letters
            if (windowEnd - windowStart + 1 - maxRepeatLetterCount > k) {
                char leftChar = str[windowStart];
                letterFrequencyMap[leftChar]--;
                windowStart++;
            }

            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};

int main(int argc, char* argv[]) {
    cout << CharacterReplacement::findLength("aabccbb", 2) << endl;
    cout << CharacterReplacement::findLength("abbcb", 1) << endl;
    cout << CharacterReplacement::findLength("abccde", 1) << endl;
}
#endif