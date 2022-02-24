#if 0
Merge Intervals

Problem Statement #
Given a list of intervals, merge all the overlapping intervals to produce a list that has only mutually exclusive intervals.

Example 1:

Intervals: [[1, 4], [2, 5], [7, 9]]
Output : [[1, 5], [7, 9]]
Explanation : Since the first two intervals[1, 4] and [2, 5] overlap, we merged them into
one[1, 5].
svg viewer
Example 2 :

Intervals : [[6, 7], [2, 4], [5, 9]]
Output : [[2, 4], [5, 9]]
Explanation : Since the intervals[6, 7] and [5, 9] overlap, we merged them into one[5, 9].

Example 3 :

Intervals : [[1, 4], [2, 6], [3, 5]]
Output : [[1, 6]]
Explanation : Since all the given intervals overlap, we merged them into one.
#endif
using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
public:
    int start = 0;
    int end = 0;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class MergeIntervals {
public:
    static vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> mergedIntervals;
        // sort all intervals O(n log n)
        sort(intervals.begin(), intervals.end(),
            [](const Interval& i, const Interval& j) {
                return i.start <= j.start;
            });

        for (Interval i : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (mergedIntervals.empty() || mergedIntervals.back().end < i.start) {
                mergedIntervals.push_back(i);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                mergedIntervals.back().end = max(mergedIntervals.back().end, i.end);
            }
        }

        return mergedIntervals;
    }
};

int main(int argc, char* argv[]) {
    vector<Interval> input = { {1, 3}, {2, 5}, {7, 9} };
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    input = { {6, 7}, {2, 4}, {5, 9} };
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    input = { {1, 4}, {2, 6}, {3, 5} };
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;
}

#if 0

Solution #
Let’s take the example of two intervals(‘a’and ‘b’) such that a.start <= b.start.There are four possible scenarios :

svg viewer
Our goal is to merge the intervals whenever they overlap.For the above - mentioned three overlapping scenarios(2, 3, and 4), this is how we will merge them :

svg viewer
The diagram above clearly shows a merging approach.Our algorithm will look like this :

    Sort the intervals on the start time to ensure a.start <= b.start
    If ‘a’ overlaps ‘b’(i.e.b.start <= a.end), we need to merge them into a new interval ‘c’ such that :
c.start = a.start
c.end = max(a.end, b.end)
We will keep repeating the above two steps to merge ‘c’ with the next interval if it overlaps with ‘c’.


using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
public:
    int start = 0;
    int end = 0;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class MergeIntervals {
public:
    static vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }

        // sort the intervals by start time
        sort(intervals.begin(), intervals.end(),
            [](const Interval& x, const Interval& y) { return x.start < y.start; });

        vector<Interval> mergedIntervals;

        vector<Interval>::const_iterator intervalItr = intervals.begin();
        Interval interval = *intervalItr++;
        int start = interval.start;
        int end = interval.end;
        while (intervalItr != intervals.end()) {
            interval = *intervalItr++;
            if (interval.start <= end) {  // overlapping intervals, adjust the 'end'
                end = max(interval.end, end);
            }
            else {  // non-overlapping interval, add the previous interval and reset
                mergedIntervals.push_back({ start, end });
                start = interval.start;
                end = interval.end;
            }
        }
        // add the last interval
        mergedIntervals.push_back({ start, end });
        return mergedIntervals;
    }
};

int main(int argc, char* argv[]) {
    vector<Interval> input = { {1, 3}, {2, 5}, {7, 9} };
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    input = { {6, 7}, {2, 4}, {5, 9} };
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    input = { {1, 4}, {2, 6}, {3, 5} };
    cout << "Merged intervals: ";
    for (auto interval : MergeIntervals::merge(input)) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;
}
#endif

#if 0

56. Merge Intervals
https ://www.educative.io/courses/grokking-the-coding-interview/3jyVPKRA8yx

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non - overlapping intervals that cover all the intervals in the input.



Example 1:

Input: intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
Output : [[1, 6], [8, 10], [15, 18]]
Explanation : Since intervals[1, 3] and [2, 6] overlaps, merge them into[1, 6].
Example 2 :

    Input : intervals = [[1, 4], [4, 5]]
    Output : [[1, 5]]
    Explanation : Intervals[1, 4] and [4, 5] are considered overlapping.


    Constraints :

    1 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 104


class Solution {
    public:
        /*
            steps:
            - Sort the intervals based on the start(i) values.
            - Initialize a variable merged
            - Traverse the intervals and
                - if the list of merged intervals is empty or if the current interval does not overlap with the previous, simply append it.
                - otherwise, there is overlap, so we merge the current and previous intervals.
            - return merged

            Time Complexity : O(nlogn)
            Space Complexity : O(1)
        */
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            // sort all intervals O(n log n)
            sort(intervals.begin(), intervals.end());

            vector<vector<int>> merged;
            for (auto interval : intervals) {
                // if the list of merged intervals is empty or if the current
                // interval does not overlap with the previous, simply append it.
                if (merged.empty() || merged.back()[1] < interval[0]) {
                    merged.push_back(interval);
                }
                // otherwise, there is overlap, so we merge the current and previous
                // intervals.
                else {
                    merged.back()[1] = max(merged.back()[1], interval[1]);
                }
            }
            return merged;
        }
};

#endif