#include <iostream>

#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;


// Longest Substring Without Repeating Characters
int LongestSubstringWithoutRepeatingCharacters(string& text) {
	int i = 0, j = 0, n = text.length(), maxLength = 0;
	unordered_map<char, int> mp;
	int uniqueChars = 0;

	while (j < n) {
		// calculations:
		char ch = text[j];
		mp[ch]++;
		uniqueChars = mp.size();

		int k = j - i + 1;

		// conditions 1: condition not met (<)
		// if (uniqueChars > k) {
		// 	++j;
		// }

		// condition 2: condition met
		if (uniqueChars == k) {
			// calculations: to get the answer
			maxLength = max(maxLength, k);
			++j;
		}

		// otherwise: condition not met (<)
		else if (uniqueChars < k) {
			// sliding
			while (uniqueChars < k) {
				char ch = text[i];
				mp[ch]--;
				mp.erase(ch);
				uniqueChars = mp.size();

				// slide
				++i;

				k = j - i + 1;
			}

			// calculations: to get the answer
			if (uniqueChars == k) {
				maxLength = max(maxLength, k);
			}

			// slide
			++j;
		}
	}
	return maxLength;
}