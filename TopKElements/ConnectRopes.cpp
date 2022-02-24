#if 0

Connect Ropes

Problem Statement#
Given ‘N’ ropes with different lengths, we need to connect these ropes into one big rope with minimum cost.The cost of connecting two ropes is equal to the sum of their lengths.

Example 1:

Input: [1, 3, 11, 5]
Output : 33
Explanation : First connect 1 + 3(= 4), then 4 + 5(= 9), and then 9 + 11(= 20).So the total cost is 33 (4 + 9 + 20)
Example 2 :

Input : [3, 4, 5, 6]
Output : 36
Explanation : First connect 3 + 4(= 7), then 5 + 6(= 11), 7 + 11(= 18).Total cost is 36 (7 + 11 + 18)
Example 3 :

Input : [1, 3, 11, 5, 2]
Output : 42
Explanation : First connect 1 + 2(= 3), then 3 + 3(= 6), 6 + 5(= 11), 11 + 11(= 22).Total cost is 42 (3 + 6 + 11 + 22)



Solution#
In this problem, following a greedy approach to connect the smallest ropes first will ensure the lowest cost.We can use a Min Heap to find the smallest ropes following a similar approach as discussed in Kth Smallest Number.Once we connect two ropes, we need to insert the resultant rope back in the Min Heap so that we can connect it with the remaining ropes.

#endif

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ConnectRopes {
public:
    static int minimumCostToConnectRopes(const vector<int>& ropeLengths) {
        int result = 0;
        // TODO: Write your code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int n : ropeLengths)
            pq.push(n);

        while (pq.size() > 1) {
            int r1 = pq.top(); pq.pop();
            int r2 = pq.top(); pq.pop();

            result += (r1 + r2);
            pq.push(r1 + r2);
            // cout << r1 <<", " << r2 << ", " << result << endl;
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    int result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5});
    cout << "Minimum cost to connect ropes: " << result << endl;
    result = ConnectRopes::minimumCostToConnectRopes(vector<int>{3, 4, 5, 6});
    cout << "Minimum cost to connect ropes: " << result << endl;
    result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5, 2});
    cout << "Minimum cost to connect ropes: " << result << endl;
}