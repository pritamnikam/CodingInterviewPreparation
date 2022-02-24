#if 0
'K' Closest Numbers

Problem Statement #
Given a sorted number arrayand two integers ‘K’and ‘X’, find ‘K’ closest numbers to ‘X’ in the array.Return the numbers in the sorted order.‘X’ is not necessarily present in the array.

Example 1:

Input: [5, 6, 7, 8, 9] , K = 3, X = 7
Output : [6, 7, 8]
Example 2 :

	Input : [2, 4, 5, 6, 9] , K = 3, X = 6
	Output : [4, 5, 6]
	Example 3 :

	Input : [2, 4, 5, 6, 9] , K = 3, X = 10
	Output : [5, 6, 9]
	
#endif

    using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KClosestElements {
public:
    struct numCompare {
        bool operator()(const pair<int, int>& x, const pair<int, int>& y) { return x.first > y.first; }
    };

    static vector<int> findClosestElements(const vector<int>& arr, int K, int X) {
        vector<int> result;
        // TODO: Write your code here
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < arr.size(); ++i) {
            pq.push({ abs(arr[i] - X), arr[i] });
            if (pq.size() > K)
                pq.pop();
        }

        while (!pq.empty()) {
            result.emplace_back(pq.top().second);
            pq.pop();
        }

        sort(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<int> result = KClosestElements::findClosestElements(vector<int>{5, 6, 7, 8, 9}, 3, 7);
    cout << "'K' closest numbers to 'X' are: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    result = KClosestElements::findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 6);
    cout << "'K' closest numbers to 'X' are: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
}