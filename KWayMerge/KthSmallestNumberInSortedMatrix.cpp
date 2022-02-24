/*
Kth Smallest Number in a Sorted Matrix

Problem Statement#
Given an N * N matrix where each row and column is sorted in ascending order, find the Kth smallest element in the matrix.

Example 1:

Input: Matrix=[
    [2, 6, 8],
    [3, 7, 10],
    [5, 8, 11]
  ],
  K=5
Output: 7
Explanation: The 5th smallest number in the matrix is 7.

Time complexity#
First, we inserted at most ‘K’ or one element from each of the ‘N’ rows, which will take O(min(K, N)). 

Then we went through at most ‘K’ elements in the matrix and remove/add one element in the heap in each step. 
As we can’t have more than ‘N’ elements in the heap in any condition, therefore, the overall time complexity 
of the above algorithm will be O(min(K, N) + K * logN).

Space complexity#
The space complexity will be O(N)O(N) because, in the worst case, our min-heap will be storing one number from each of the ‘N’ rows.


*/
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

// data structure to hold, number mapping to row and col in matrix
typedef pair<int, pair<int, int>> ppi;

struct Compare {
    bool operator() (const ppi& a, const ppi& b) {
        return a.first > b.first;
    }
};

class KthSmallestInSortedMatrix {
public:
    static int findKthSmallest(vector<vector<int>>& matrix, int k) {
        int result = -1;
        // TODO: Write your code here

        priority_queue<ppi, vector<ppi>, Compare> minHeap;

        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows && i < k; ++i) {
            minHeap.push({ matrix[i][0], {i, 0} });
        }

        int numberCount = 0;
        while (!minHeap.empty()) {
            ppi top = minHeap.top();
            minHeap.pop();
            
            result = top.first;

            ++numberCount;
            if (k == numberCount)
                break;

            int row = top.second.first;
            int col = top.second.second + 1;
            if (col < cols) {
                top.first = matrix[row][col];
                top.second.first = row;
                top.second.second = col;
                minHeap.push(top);
            }
        }

        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> matrix2 = { vector<int>{2, 6, 8}, vector<int>{3, 7, 10},
                                   vector<int>{5, 8, 11} };
    int result = KthSmallestInSortedMatrix::findKthSmallest(matrix2, 5);
    cout << "Kth smallest number is: " << result << endl;
}