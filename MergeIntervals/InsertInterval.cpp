#if 0

Insert Interval

Problem Statement #
Given a list of non - overlapping intervals sorted by their start time, insert a given interval at 
the correct positionand merge all necessary intervals to produce a list that has only mutually exclusive intervals.

Example 1:

Input: Intervals = [[1, 3], [5, 7], [8, 12]], New Interval = [4, 6]
Output : [[1, 3], [4, 7], [8, 12]]
Explanation : After insertion, since[4, 6] overlaps with[5, 7], we merged them into one[4, 7].
Example 2 :

	Input : Intervals = [[1, 3], [5, 7], [8, 12]], New Interval = [4, 10]
	Output : [[1, 3], [4, 12]]
	Explanation : After insertion, since[4, 10] overlaps with[5, 7] & [8, 12], we merged them into[4, 12].
	Example 3 :

	Input : Intervals = [[2, 3], [5, 7]], New Interval = [1, 4]
	Output : [[1, 4], [5, 7]]
	Explanation : After insertion, since[1, 4] overlaps with[2, 3], we merged them into one[1, 4].


#endif

    using namespace std;

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

class InsertInterval {
public:
    static vector<Interval> insert(const vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) {
            return vector<Interval>{newInterval};
        }

        // we can use the fact that intervals are already sorted and distinct;
        vector<Interval> mergedIntervals;
        // TODO: Write your code here
        // we can do this in 3 steps:
        // 1. intervals before newInterval
        int i = 0;
        while (i < intervals.size() && (intervals[i].end < newInterval.start)) {
            mergedIntervals.push_back(intervals[i]);
            ++i;
        }

        // 2. merge all overlapping intervals
        while (i < intervals.size() && (intervals[i].start <= newInterval.end)) {
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
            ++i;
        }

        mergedIntervals.push_back(newInterval);


        // 3. all remaining intervals after newIntervals
        while (i < intervals.size() && (intervals[i].start > newInterval.end)) {
            mergedIntervals.push_back(intervals[i]);
            ++i;
        }


        return mergedIntervals;
    }
};

int main(int argc, char* argv[]) {
    vector<Interval> input = { {1, 3}, {5, 7}, {8, 12} };
    cout << "Intervals after inserting the new interval: ";
    for (auto interval : InsertInterval::insert(input, { 4, 6 })) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    cout << "Intervals after inserting the new interval: ";
    for (auto interval : InsertInterval::insert(input, { 4, 10 })) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    input = { {2, 3}, {5, 7} };
    cout << "Intervals after inserting the new interval: ";
    for (auto interval : InsertInterval::insert(input, { 1, 4 })) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;
}

#if 0

Solution #
If the given list was not sorted, we could have simply appended the new interval to itand used the merge() function from Merge Intervals.But since the given list is sorted, we should try to come up with a solution better than O(N* logN)O(N∗logN)

When inserting a new interval in a sorted list, we need to first find the correct index where the new interval can be placed.In other words, we need to skip all the intervals which end before the start of the new interval.So we can iterate through the given sorted listed of intervalsand skip all the intervals with the following condition :

intervals[i].end < newInterval.start
    Once we have found the correct place, we can follow an approach similar to Merge Intervals to insertand /or merge the new interval.Let’s call the new interval ‘a’ and the first interval with the above condition ‘b’.There are five possibilities :

svg viewer
The diagram above clearly shows the merging approach.To handle all four merging scenarios, we need to do something like this :

    c.start = min(a.start, b.start)
    c.end = max(a.end, b.end)
    Our overall algorithm will look like this :

    Skip all intervals which end before the start of the new interval, i.e., skip all intervals with the following condition :
intervals[i].end < newInterval.start
    Let’s call the last interval ‘b’ that does not satisfy the above condition.If ‘b’ overlaps with the new interval(a) (i.e.b.start <= a.end), we need to merge them into a new interval ‘c’ :
c.start = min(a.start, b.start)
c.end = max(a.end, b.end)
We will repeat the above two steps to merge ‘c’ with the next overlapping interval.


using namespace std;

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

class InsertInterval {
public:
    static vector<Interval> insert(const vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) {
            return vector<Interval>{newInterval};
        }

        vector<Interval> mergedIntervals;

        int i = 0;
        // skip (and add to output) all intervals that come before the 'newInterval'
        while (i < intervals.size() && intervals[i].end < newInterval.start) {
            mergedIntervals.push_back(intervals[i++]);
        }

        // merge all intervals that overlap with 'newInterval'
        while (i < intervals.size() && intervals[i].start <= newInterval.end) {
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
            i++;
        }

        // insert the newInterval
        mergedIntervals.push_back(newInterval);

        // add all the remaining intervals to the output
        while (i < intervals.size()) {
            mergedIntervals.push_back(intervals[i++]);
        }

        return mergedIntervals;
    }
};

int main(int argc, char* argv[]) {
    vector<Interval> input = { {1, 3}, {5, 7}, {8, 12} };
    cout << "Intervals after inserting the new interval: ";
    for (auto interval : InsertInterval::insert(input, { 4, 6 })) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    cout << "Intervals after inserting the new interval: ";
    for (auto interval : InsertInterval::insert(input, { 4, 10 })) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;

    input = { {2, 3}, {5, 7} };
    cout << "Intervals after inserting the new interval: ";
    for (auto interval : InsertInterval::insert(input, { 1, 4 })) {
        cout << "[" << interval.start << "," << interval.end << "] ";
    }
    cout << endl;
}
#endif