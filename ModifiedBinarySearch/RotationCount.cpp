/*
Rotation Count

Rotation Count (medium)#
Given an array of numbers which is sorted in ascending order and is rotated ‘k’ times around a pivot, find ‘k’.

You can assume that the array does not have any duplicates.

Example 1:
Input: [10, 15, 1, 3, 8]
Output: 2
Explanation: The array has been rotated 2 times.

Example 2:
Input: [4, 5, 7, 9, 10, -1, 2]
Output: 5
Explanation: The array has been rotated 5 times.

Example 3:
Input: [1, 3, 8, 10]
Output: 0
Explanation: The array has been not been rotated.

*/

using namespace std;

#include <iostream>
#include <vector>

class RotationCountOfRotatedArray {
public:
    static int countRotations(const vector<int>& arr) {
        int n = arr.size();
        int start = 0, end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int prev = (mid + n - 1) % n;
            int next = (mid + 1) % n;

            if (arr[mid] < arr[prev] && arr[mid] < arr[next]) {
                return mid;
            }

            if (arr[mid] < arr[end]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return 0;
    }
};

int main(int argc, char* argv[]) {
    cout << RotationCountOfRotatedArray::countRotations(vector<int>{10, 15, 1, 3, 8}) << endl;
    cout << RotationCountOfRotatedArray::countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
    cout << RotationCountOfRotatedArray::countRotations(vector<int>{1, 3, 8, 10}) << endl;
}