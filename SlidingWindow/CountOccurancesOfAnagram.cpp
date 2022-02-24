#include <iostream>

#include <unordered_map>
#include <vector>
#include <string>


using namespace std;

int CountAnagrams(string& text, string& pattern) {
	unordered_map<char, int> mp;
	int uniqueChars = 0;

	for (char ch : pattern) {
		mp[ch]++;
		uniqueChars = mp.size();
	}


	int i = 0, j = 0, n = text.length(), count = 0, k = pattern.length();
	while (j < n) {

		// calculations
		{
			char ch = text[j];
			if (mp.count(ch)) {
				mp[ch]--;
				if (mp[ch] == 0)
					--uniqueChars;
			}
		}

		// condition: window size check
		if (j - i + 1 < k) {
			++j;
		}
		else if (j - i + 1 == k) {
			if (uniqueChars == 0)
				++count;
		}
		else {
			// slide the window
			char ch = text[i];
			if (mp.count(ch)) {
				mp[ch]++;
				if (mp[ch] == 1)
					++uniqueChars;
			}

			++i;
			++j;
		}
	}

	return count;
}

#if 0
using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class StringPermutation {
public:
	static bool findPermutation(const string& str, const string& pattern) {
		int windowStart = 0, matched = 0;
		unordered_map<char, int> charFrequencyMap;
		for (auto chr : pattern) {
			charFrequencyMap[chr]++;
		}

		// our goal is to match all the characters from the 'charFrequencyMap' with the current window
		// try to extend the range [windowStart, windowEnd]
		for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
			char rightChar = str[windowEnd];
			if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) {
				// decrement the frequency of the matched character
				charFrequencyMap[rightChar]--;
				if (charFrequencyMap[rightChar] == 0) {  // character is completely matched
					matched++;
				}
			}

			if (matched == (int)charFrequencyMap.size()) {
				return true;
			}

			if (windowEnd >= pattern.length() - 1) {  // shrink the window
				char leftChar = str[windowStart++];
				if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) {
					if (charFrequencyMap[leftChar] == 0) {
						matched--;  // before putting the character back, decrement the matched count
					}
					// put the character back for matching
					charFrequencyMap[leftChar]++;
				}
			}
		}

		return false;
	}
};



int main(int argc, char* argv[]) {
	cout << "Permutation exist: " << StringPermutation::findPermutation("oidbcaf", "abc") << endl;
	cout << "Permutation exist: " << StringPermutation::findPermutation("odicf", "dc") << endl;
	cout << "Permutation exist: " << StringPermutation::findPermutation("bcdxabcdy", "bcdyabcdx") << endl;
	cout << "Permutation exist: " << StringPermutation::findPermutation("aaacb", "abc") << endl;
}



using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class StringAnagrams {
public:
	static vector<int> findStringAnagrams(const string& str, const string& pattern) {
		int windowStart = 0, matched = 0;
		unordered_map<char, int> charFrequencyMap;
		for (auto chr : pattern) {
			charFrequencyMap[chr]++;
		}

		vector<int> resultIndices;
		// our goal is to match all the characters from the map with the current window
		for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
			char rightChar = str[windowEnd];
			// decrement the frequency of the matched character
			if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) {
				charFrequencyMap[rightChar]--;
				if (charFrequencyMap[rightChar] == 0) {
					matched++;
				}
			}

			if (matched == (int)charFrequencyMap.size()) {  // have we found an anagram?
				resultIndices.push_back(windowStart);
			}

			if (windowEnd >= pattern.length() - 1) {  // shrink the window
				char leftChar = str[windowStart++];
				if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) {
					if (charFrequencyMap[leftChar] == 0) {
						matched--;  // before putting the character back, decrement the matched count
					}
					// put the character back
					charFrequencyMap[leftChar]++;
				}
			}
		}

		return resultIndices;
	}
};

int main(int argc, char* argv[]) {
	auto result = StringAnagrams::findStringAnagrams("ppqp", "pq");
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;

	result = StringAnagrams::findStringAnagrams("abbcabc", "abc");
	for (auto num : result) {
		cout << num << " ";
	}
	cout << endl;
}
#endif