#if 0

Scheduling Tasks


You are given a list of tasks that need to be run, in any order, on a server.

Each task will take one CPU interval to execute but once a task has finished, 
it has a cooling period during which it can’t be run again.If the cooling period 
for all tasks is ‘K’ intervals, find the minimum number of CPU intervals that the 
server needs to finish all tasks.

If at any time the server can’t execute any task then it must stay idle.

Example 1:

Input: [a, a, a, b, c, c] , K = 2
Output : 7
Explanation : a->c->b->a->c->idle->a

Example 2 :
Input : [a, b, a] , K = 3
Output : 5
Explanation : a->b->idle->idle->a


Solution#
This problem follows the Top ‘K’ Elements patternand is quite similar to Rearrange String K Distance Apart.
We need to rearrange tasks such that same tasks are ‘K’ distance apart.

Following a similar approach, we will use a Max Heap to execute the highest frequency task first.
After executing a task we decrease its frequencyand put it in a waiting list.

In each iteration, we will try to execute as many as k + 1 tasks.
For the next iteration, we will put all the waiting tasks back in the Max Heap.

If, for any iteration, we are not able to execute k + 1 tasks, the CPU has to 
remain idle for the remaining time in the next iteration.



#endif
using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskScheduler {
public:
    struct valueCompare {
        char operator()(const pair<int, int>& x, const pair<int, int>& y) {
            return y.second > x.second;
        }
    };

    static int scheduleTasks(vector<char>& tasks, int k) {
        int intervalCount = 0;
        unordered_map<char, int> taskFrequencyMap;
        for (char chr : tasks) {
            taskFrequencyMap[chr]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

        // add all tasks to the max heap
        for (auto entry : taskFrequencyMap) {
            maxHeap.push(entry);
        }

        while (!maxHeap.empty()) {
            vector<pair<char, int>> waitList;
            int n = k + 1;  // try to execute as many as 'k+1' tasks from the max-heap
            for (; n > 0 && !maxHeap.empty(); n--) {
                intervalCount++;
                auto currentEntry = maxHeap.top();
                maxHeap.pop();
                if (currentEntry.second > 1) {
                    currentEntry.second--;
                    waitList.push_back(currentEntry);
                }
            }
            // put all the waiting list back on the heap
            for (auto it = waitList.begin(); it != waitList.end(); it++) {
                maxHeap.push(*it);
            }
            if (!maxHeap.empty()) {
                intervalCount += n;  // we'll be having 'n' idle intervals for the next iteration
            }
        }

        return intervalCount;
    }
};

int main(int argc, char* argv[]) {
    vector<char> tasks = { 'a', 'a', 'a', 'b', 'c', 'c' };
    cout << "Minimum intervals needed to execute all tasks: "
        << TaskScheduler::scheduleTasks(tasks, 2) << endl;

    tasks = vector<char>{ 'a', 'b', 'a' };
    cout << "Minimum intervals needed to execute all tasks: "
        << TaskScheduler::scheduleTasks(tasks, 3) << endl;
}