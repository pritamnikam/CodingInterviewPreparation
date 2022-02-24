using namespace std;


#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubstring {
public:
    static int findLength(const string& str) {
        int maxLength = 0;
        // TODO: Write your code here
        int i = 0, j = 0, count = 0, n = str.length();
        unordered_map<char, int> mp;

        for (j = 0; j < n; ++j) {
            char ch = str[j];

            // new char is already present in map.
            // it's indication that window needs to be shrinked from start
            if (mp.count(ch)) {
                // since the new character is already part of window
                // to continue the quest, reset the start of window to the
                // next to previously stored position of 'ch'
                i = max(i, mp[ch] + 1);
            }

            // update the new position for the ch
            mp[ch] = j;

            // calculate the window size
            maxLength = max(maxLength, j - i + 1);
        }

        return maxLength;
    }
};


#if 0


class NoRepeatSubstring {
public:
    static int findLength(const string& str) {
        int windowStart = 0, maxLength = 0;
        unordered_map<char, int> charIndexMap;
        // try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
            char rightChar = str[windowEnd];
            // if the map already contains the 'rightChar', shrink the window from the beginning so that
            // we have only one occurrence of 'rightChar'
            if (charIndexMap.find(rightChar) != charIndexMap.end()) {
                // this is tricky; in the current window, we will not have any 'rightChar' after its
                // previous index and if 'windowStart' is already ahead of the last index of 'rightChar',
                // we'll keep 'windowStart'
                windowStart = max(windowStart, charIndexMap[rightChar] + 1);
            }
            charIndexMap[rightChar] = windowEnd;  // insert the 'rightChar' into the map
            maxLength =
                max(maxLength, windowEnd - windowStart + 1);  // remember the maximum length so far
        }

        return maxLength;
    }
};

int main(int argc, char* argv[]) {
    cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("aabccbb") << endl;
    cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abbbb") << endl;
    cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abccde") << endl;
}

#endif