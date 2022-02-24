#if 0
find all the conflicting appointments

Similar Problems #
Problem 1: Given a list of appointments, find all the conflicting appointments.

Example :

	Appointments : [[4, 5], [2, 3], [3, 6], [5, 7], [7, 8]]
	Output :
	[4, 5] and [3, 6] conflict.
	[3, 6] and [5, 7] conflict.
#endif

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
public:
    int start;
    int end;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class ConflictingAppointments {
public:
    static bool isOverlap(Interval& i, Interval& j) {
        return i.end > j.start;
    }

    static vector<Interval> canAttendAllAppointments(vector<Interval>& intervals) {
        // TODO: Write your code here
        // sort intervals by their start times
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) { return a.start < b.start; });

        vector<Interval> result;
        Interval it = intervals[0];
        int i = 1;
        while (i < intervals.size()) {
            // for sorted intervals: if there exist an overlap
            if (isOverlap(it, intervals[i]))
                result.push_back(it);

            if (it.end < intervals[i].end) {
                it = intervals[i];
            }

            ++i;
        }

        return result;
    }
};
