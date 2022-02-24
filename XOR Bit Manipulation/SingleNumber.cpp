/*
Problem Statement#
In a non-empty array of integers, every number appears twice except for one, find that single number.

Example 1:

Input: 1, 4, 2, 1, 3, 2, 3
Output: 4
Example 2:

Input: 7, 9, 7
Output: 9

*/

using namespace std;

#include <iostream>
#include <vector>

class SingleNumber {
public:
    static int findSingleNumber(const vector<int>& arr) {
        // TODO: Write your code here
        int x = arr[0];
        for (int i = 1; i < arr.size(); ++i)
            x ^= arr[i];
        return x;
    }
};

int main(int argc, char* argv[]) {
    cout << SingleNumber::findSingleNumber(vector<int>{1, 4, 2, 1, 3, 2, 3}) << endl;
}