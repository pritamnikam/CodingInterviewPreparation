/*
207. Course Schedule

https://leetcode.com/problems/course-schedule/

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.


Constraints:

1 <= numCourses <= 105
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

*/
using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses < 2)
            return true;

        unordered_map<int, int> inDegree;
        unordered_map<int, vector<int>> adjList;

        for (int i = 0; i < numCourses; ++i) {
            inDegree[i] = 0;
            adjList[i] = vector<int>();
        }

        for (auto edge : prerequisites) {
            int u = edge[0], v = edge[1];
            inDegree[v]++;
            adjList[u].emplace_back(v);
        }

        queue<int> sources;
        for (auto entry : inDegree) {
            if (entry.second == 0)
                sources.push(entry.first);
        }

        vector<int> cources;
        while (!sources.empty()) {
            int u = sources.front();
            sources.pop();

            cources.emplace_back(u);

            for (int v : adjList[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0)
                    sources.push(v);
            }
        }

        return cources.size() == numCourses;
    }
};