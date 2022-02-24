/*
minimum number of platforms

Problem 2: Given a list of intervals representing the arrival and departure times of trains to a 
train station, our goal is to find the minimum number of platforms required for the train station 
so that no train has to wait.


*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>


class Schedule {
public:
    int start;
    int end;

    Schedule(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

struct Compare {
    bool operator() (const Schedule& a, const Schedule& b) {
        return a.end < b.end;
    }
};

class MinimumMeetingRooms {
public:
    static int findPointWithMaximumOverlaps(vector<Schedule>& schedules) {
        if (schedules.size() < 2)
            return schedules.size();

        // sort in ascending order by start time
        sort(schedules.begin(), schedules.end(),
            [](const Schedule& a, const Schedule& b) {
                return a.start < b.start;
            });

        // for all schedules keep a pq for active trains
        priority_queue<Schedule, vector<Schedule>, Compare> pq;

        int platformsRequired = 0;
        for (auto it : schedules) {
            while (!pq.empty() && pq.top().end <= it.start)
                pq.pop();

            pq.push(it);

            platformsRequired = max(platformsRequired, (int)pq.size());
        }

        return platformsRequired;
    }
};