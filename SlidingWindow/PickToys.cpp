#include <iostream>

#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;


int PickToys(vector<char>& toys, int k) {
	unordered_map<char, int> mp;
	int i = 0, j = 0, n = toys.size(), ans = 0, count = 0;

	while (j < n) {
		char ch = toys[j];
		mp[ch]++;
		count = mp.size();


		if (count < k) {
			++j;
		}

		else if (count == k) {
			ans = max(ans, j - i + 1);
			++j;
		}

		else {
			while (count > k) {
				char ch = toys[i];
				mp[ch]--;
				if (mp[ch] == 0)
					mp.erase(ch);
				count = mp.size();

				++i;
			}

			++j;
		}
	}

	return ans;
}