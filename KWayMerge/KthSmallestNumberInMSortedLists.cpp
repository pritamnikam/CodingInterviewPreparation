/*
Kth Smallest Number in M Sorted Lists

Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.

Example 1:

Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
Output: 4
Explanation: The 5th smallest number among all the arrays is 4, this can be verified from
the merged list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]
Example 2:

Input: L1=[5, 8, 9], L2=[1, 7], K=3
Output: 7
Explanation: The 3rd smallest number among all the arrays is 7.


*/
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

// pair holds number and pair of arr and count info
typedef pair<int, pair<int, int>> ppi;

struct Compare {
    bool operator() (const ppi& a, const ppi& b) {
        return a.first > b.first;
    }
};

class KthSmallestInMSortedArrays {
public:
    static int findKthSmallest(const vector<vector<int>>& lists, int k) {
        int result = -1;
        // TODO: Write your code here
        priority_queue<ppi, vector<ppi>, Compare> minHeap;

        for (int i = 0; i < lists.size(); ++i) {
            minHeap.push({ lists[i][0], {i, 0} });
        }

        while (!minHeap.empty()) {
            ppi cur = minHeap.top();
            minHeap.pop(); --k;
            result = cur.first;
            if (k == 0)
                break;

            int id = cur.second.first;
            int count = cur.second.second;
            if (lists[id].size() > count + 1) {
                minHeap.push({ lists[id][count + 1], {id, count + 1} });
            }
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> lists = { {2, 6, 8}, {3, 6, 7}, {1, 3, 4} };
    int result = KthSmallestInMSortedArrays::findKthSmallest(lists, 5);
    cout << "Kth smallest number is: " << result;
}

/*

Solution #
This problem follows the K-way merge pattern and we can follow a similar approach as discussed in Merge K Sorted Lists.

We can start merging all the arrays, but instead of inserting numbers into a merged list, we will keep count to see how 
many elements have been inserted in the merged list. Once that count is equal to ‘K’, we have found our required number.

A big difference from Merge K Sorted Lists is that in this problem, the input is a list of arrays compared to LinkedLists. 

This means that when we want to push the next number in the heap we need to know what the index of the current number in the 
current array was. To handle this, we will need to keep track of the array and the element indices.

Time complexity #
Since we’ll be going through at most ‘K’ elements among all the arrays, and we will remove/add one element in the heap in each step, the time complexity of the above algorithm will be O(K*logM)O(K∗logM) where ‘M’ is the total number of input arrays.

Space complexity #
The space complexity will be O(M)O(M) because, at any time, our min-heap will be storing one number from all the ‘M’ input arrays.



using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestInMSortedArrays {
public:
    struct valueCompare {
        bool operator()(const pair<int, pair<int, int>>& x, const pair<int, pair<int, int>>& y) {
            return x.first > y.first;
        }
    };

    static int findKthSmallest(const vector<vector<int>>& lists, int k) {
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       valueCompare> minHeap;

        // put the 1st element of each array in the min heap
        for (int i = 0; i < lists.size(); i++) {
            if (!lists[i].empty()) {
                minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
            }
        }

        // take the smallest (top) element form the min heap, if the running count is equal to k return
        // the number if the array of the top element has more elements, add the next element to the
        // heap
        int numberCount = 0, result = 0;
        while (!minHeap.empty()) {
            auto node = minHeap.top();
            minHeap.pop();
            result = node.first;
            if (++numberCount == k) {
                break;
            }
            node.second.second++;
            if (lists[node.second.first].size() > node.second.second) {
                node.first = lists[node.second.first][node.second.second];
                minHeap.push(node);
            }
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> lists = { {2, 6, 8}, {3, 6, 7}, {1, 3, 4} };
    int result = KthSmallestInMSortedArrays::findKthSmallest(lists, 5);
    cout << "Kth smallest number is: " << result;
}

*/



#if 0

Similar Problems #
Problem 1: Given ‘M’ sorted arrays, find the median number among all arrays.

Solution : This problem is similar to our parent problem with K = Median.
So if there are ‘N’ total numbers in all the arrays we need to find the K’th minimum 
number where K = N / 2.

Problem 2 : Given a list of ‘K’ sorted arrays, merge them into one sorted list.

Solution : This problem is similar to Merge K Sorted Lists except that the input 
is a list of arrays compared to LinkedLists.To handle this, we can use a similar approach 
as discussed in our parent problem by keeping a track of the arrayand the element indices.


#endif