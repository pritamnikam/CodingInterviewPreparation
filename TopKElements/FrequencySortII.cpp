#if 0
Frequency Sort

Problem Statement#
Given a string, sort it based on the decreasing frequency of its characters.

Example 1:

Input: "Programming"
Output : "rrggmmPiano"
Explanation : 'r', 'g', and 'm' appeared twice, so they need to appear before any other character.
Example 2 :

Input : "abcbab"
Output : "bbbaac"
Explanation : 'b' appeared three times, 'a' appeared twice, and 'c' appeared only once.
	


#endif

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencySort {
public:
    static string sortCharacterByFrequency(const string& str) {
        string sortedString = "";
        // TODO: Write your code here
        unordered_map<char, int> freqMap;
        priority_queue<pair<int, char>> pq;

        for (char ch : str) {
            freqMap[ch]++;
        }

        for (auto& it : freqMap)
            pq.push({ it.second, it.first });

        while (!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            for (int i = 0; i < freq; ++i)
                sortedString += ch;
        }

        return sortedString;
    }
};

int main(int argc, char* argv[]) {
    string result = FrequencySort::sortCharacterByFrequency("Programming");
    cout << "Here is the given string after sorting characters by frequency: " << result << endl;

    result = FrequencySort::sortCharacterByFrequency("abcbab");
    cout << "Here is the given string after sorting characters by frequency: " << result << endl;
}