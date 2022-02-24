/*
find the point where the maximum number of intervals overlap.

*/
using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>


class Interval {
public:
    int start;
    int end;

    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

struct Compare {
    bool operator() (const Interval& a, const Interval& b) {
        return a.end < b.end;
    }
};

class MinimumMeetingRooms {
public:
    static int findPointWithMaximumOverlaps(vector<Interval>& intervals) {
        if (intervals.size() < 2)
            return intervals.size();

        // sort meetings by their start time
        sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b) {
                return a.start > b.start;
            });

        int maxOverlaps = 0;
        priority_queue<Interval, vector<Interval>, Compare> pq;
        for (auto it : intervals) {

            // remove all finished intervals.
            while (!pq.empty() && pq.top().end <= it.start) {
                pq.pop();
            }

            // add the current interval into the min heap
            pq.push(it);

            // all active interval are in the min heap, so we need rooms for all of them.
            maxOverlaps = max(maxOverlaps, (int)pq.size());
        }

        return maxOverlaps;
    }
};