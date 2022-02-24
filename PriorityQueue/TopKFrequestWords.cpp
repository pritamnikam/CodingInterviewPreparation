#include<iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*

Approach -> Hashing+Max Heap
Step 1-> Put everything in Hashmap
Step2-> Construct a min heap and put everything from hashmap to heap and maintain the size of the heap to be less than or equal to 'K'
Step 3-> Pop everything from the heap into a vector and dont forget to reverse coz the top element is at the bottom as we used a min heap

*/

typedef pair<string, int> PSI;

vector<string> topKFrequent(vector<string>& words, int k) {
    auto mycmp = [](auto& l, auto& r) {
        if (l.second == r.second)
            return l.first < r.first;
        return l.second > r.second;
    };

    vector<string> res;
    unordered_map<string, int> um;
    priority_queue<PSI, vector<PSI>, decltype(mycmp)> pq(mycmp);

    for (auto& i : words)
        um[i]++; //->Step1->O(N)

    for (auto& i : um) //Step2-> O(NlogK)
    {
        pq.push(i);
        if (pq.size() > k) pq.pop();
    }
    //Step 3->O(K)
    while (!pq.empty())  //O(K)
    {
        res.emplace_back(pq.top().first);
        pq.pop();
    }

    std::reverse(begin(res), end(res)); //->O(K)
    return res;
}
