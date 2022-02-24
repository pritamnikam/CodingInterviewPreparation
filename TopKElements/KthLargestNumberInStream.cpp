#if 0

Kth Largest Number in a Stream


Problem Statement#
Design a class to efficiently find the Kth largest element in a stream of numbers.

The class should have the following two things :

The constructor of the class should accept an integer array containing initial numbers from the streamand an integer ‘K’.
The class should expose a function add(int num) which will store the given numberand return the Kth largest number.
Example 1 :

Input: [3, 1, 5, 12, 2, 11] , K = 4
1. Calling add(6) should return '5'.
2. Calling add(13) should return '6'.
2. Calling add(4) should still return '6'.

#endif


using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthLargestNumberInStream {
    int k_;
    priority_queue<int, vector<int>, greater<int>> pq_;
public:
    KthLargestNumberInStream(const vector<int>& nums, int k) {
        // TODO: Write your code here
        k_ = k;
        for (int n : nums)
            add(n);
    }

    virtual int add(int num) {
        // TODO: Write your code here
        pq_.push(num);
        if (pq_.size() > k_)
            pq_.pop();

        return pq_.top();
    }
};

int main(int argc, char* argv[]) {
    KthLargestNumberInStream kthLargestNumber({ 3, 1, 5, 12, 2, 11 }, 4);
    cout << "4th largest number is: " << kthLargestNumber.add(6) << endl;
    cout << "4th largest number is: " << kthLargestNumber.add(13) << endl;
    cout << "4th largest number is: " << kthLargestNumber.add(4) << endl;
}