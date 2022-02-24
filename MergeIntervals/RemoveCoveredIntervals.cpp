#if 0

1288. Remove Covered Intervals

https ://leetcode.com/problems/remove-covered-intervals/

Given an array intervals where intervals[i] = [li, ri] represent the interval[li, ri), remove all intervals that are covered by another interval in the list.

The interval[a, b) is covered by the interval[c, d) ifand only if c <= a and b <= d.

Return the number of remaining intervals.



Example 1:

Input: intervals = [[1, 4], [3, 6], [2, 8]]
Output : 2
Explanation : Interval[3, 6] is covered by[2, 8], therefore it is removed.
Example 2 :

    Input : intervals = [[1, 4], [2, 3]]
    Output : 1


    Constraints :

    1 <= intervals.length <= 1000
    intervals[i].length == 2
    0 <= li <= ri <= 105
    All the given intervals are unique.


#endif

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    
    // The interval [a, b) is covered by the interval [c, d) 
    // if and only if c <= a and b <= d.
    bool isCovered(vector<int>& i, vector<int>& j) {
        int a = i[0], b = i[1];
        int c = j[0], d = j[1];

        return (a <= c and d <= b) || (c <= a and b <= d);
    }

public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() < 2)
            return intervals.size();

        // sort intervals by start time
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0]) {
                    return a[1] > b[1];
                }
                return a[0] < b[0];
            });

        int count = 0;
        int i = 1;
        int n = intervals.size();
        vector<int> it = intervals[0];
        while (i < n) {
            bool covered = isCovered(it, intervals[i]);
            if (covered) {
                ++count;
                ++i;
                continue;
            }
            else {
                it = intervals[i];
                ++i;
            }
        }

        return n - count;
    }
};