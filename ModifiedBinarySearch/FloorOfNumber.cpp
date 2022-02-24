/*
find the floor of a given number

Problem 1#
Given an array of numbers sorted in ascending order, find the floor of a given number ‘key’. The floor of the ‘key’ will be the biggest element in the given array smaller than or equal to the ‘key’

Write a function to return the index of the floor of the ‘key’. If there isn’t a floor, return -1.

Example 1:

Input: [4, 6, 10], key = 6
Output: 1
Explanation: The biggest number smaller than or equal to '6' is '6' having index '1'.
Example 2:

Input: [1, 3, 8, 10, 15], key = 12
Output: 3
Explanation: The biggest number smaller than or equal to '12' is '10' having index '3'.
Example 3:

Input: [4, 6, 10], key = 17
Output: 2
Explanation: The biggest number smaller than or equal to '17' is '10' having index '2'.
Example 4:

Input: [4, 6, 10], key = -1
Output: -1
Explanation: There is no number smaller than or equal to '-1' in the given array.

Time complexity#
Since we are reducing the search range by half at every step, this means that the time complexity of our algorithm will be O(logN)O(logN) where ‘N’ is the total elements in the given array.

Space complexity#
The algorithm runs in constant space O(1)O(1).


*/

using namespace std;

#include <iostream>
#include <vector>

class FloorOfANumber {
public:
    static int searchFloorOfANumber(const vector<int>& arr, int key) {
        if (key < arr[0]) {  // if the 'key' is smaller than the smallest element
            return -1;
        }

        int start = 0, end = arr.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (key < arr[mid]) {
                end = mid - 1;
            }
            else if (key > arr[mid]) {
                start = mid + 1;
            }
            else {  // found the key
                return mid;
            }
        }
        // since the loop is running until 'start <= end', so at the end of the while loop, 'start ==
        // end+1' we are not able to find the element in the given array, so the next smaller number
        // will be arr[end]
        return end;
    }
};

int main(int argc, char* argv[]) {
    cout << FloorOfANumber::searchFloorOfANumber(vector<int>{4, 6, 10}, 6) << endl;
    cout << FloorOfANumber::searchFloorOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
    cout << FloorOfANumber::searchFloorOfANumber(vector<int>{4, 6, 10}, 17) << endl;
    cout << FloorOfANumber::searchFloorOfANumber(vector<int>{4, 6, 10}, -1) << endl;
}