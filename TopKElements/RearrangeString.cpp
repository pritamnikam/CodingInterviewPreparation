#if 0
Rearrange String

Problem Statement#
Given a string, find if its letters can be rearranged in such a way that no two same characters come next to each other.

Example 1:

Input: "aappp"
Output : "papap"
Explanation : In "papap", none of the repeating characters come next to each other.
Example 2 :

Input : "Programming"
Output : "rgmrgmPiano" or "gmringmrPoa" or "gmrPagimnor", etc.
Explanation : None of the repeating characters come next to each other.
Example 3 :

Input : "aapa"
Output : ""
Explanation : In all arrangements of "aapa", atleast two 'a' will come together e.g., "apaa", "paaa".
	
#endif

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeString {
public:
    static string rearrangeString(const string& str) {
        // TODO: Write your code here
        
        unordered_map<char, int> freqMap;
        for (char ch : str)
            freqMap[ch]++;

        priority_queue<pair<int, char>> pq;
        for (auto it : freqMap) {
            pq.push({ it.second, it.first });
        }

        string result;
        pair<int, char> previousEntry;
        while (!pq.empty()) {
            auto currentEntry = pq.top();
            pq.pop();

            if (previousEntry.first > 0)
                pq.push(previousEntry);

            result += currentEntry.second;
            previousEntry.first = currentEntry.first - 1;
            previousEntry.second = currentEntry.second;
        }


        return (result.length() == str.length()) ? result : "";
    }
};

int main(int argc, char* argv[]) {
    cout << "Rearranged string: " << RearrangeString::rearrangeString("aappp") << endl;
    cout << "Rearranged string: " << RearrangeString::rearrangeString("Programming") << endl;
    cout << "Rearranged string: " << RearrangeString::rearrangeString("aapa") << endl;
}

#if 0

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class RearrangeString {
public:
    struct valueCompare {
        char operator()(const pair<int, int>& x, const pair<int, int>& y) {
            return y.second > x.second;
        }
    };

    static string rearrangeString(const string& str) {
        unordered_map<char, int> charFrequencyMap;
        for (char chr : str) {
            charFrequencyMap[chr]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

        // add all characters to the max heap
        for (auto entry : charFrequencyMap) {
            maxHeap.push(entry);
        }

        pair<char, int> previousEntry(-1, -1);
        string resultString = "";
        while (!maxHeap.empty()) {
            pair<char, int> currentEntry = maxHeap.top();
            maxHeap.pop();
            // add the previous entry back in the heap if its frequency is greater than zero
            if (previousEntry.second > 0) {
                maxHeap.push(previousEntry);
            }
            // append the current character to the result string and decrement its count
            resultString += currentEntry.first;
            currentEntry.second--;
            previousEntry = currentEntry;
        }

        // if we were successful in appending all the characters to the result string, return it
        return resultString.length() == str.length() ? resultString : "";
    }
};

int main(int argc, char* argv[]) {
    cout << "Rearranged string: " << RearrangeString::rearrangeString("aappp") << endl;
    cout << "Rearranged string: " << RearrangeString::rearrangeString("Programming") << endl;
    cout << "Rearranged string: " << RearrangeString::rearrangeString("aapa") << endl;
}
#endif