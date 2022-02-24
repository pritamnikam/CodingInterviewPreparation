#if 0
Find the Smallest Missing Positive Number

Given an unsorted array containing numbers, find the smallest missing positive number in it.

Example 1:

Input: [-3, 1, 5, 4, 2]
Output : 3
Explanation : The smallest missing positive number is '3'

Example 2 :
Input : [3, -2, 0, 1, 2]
Output : 4

Example 3 :
Input : [3, 2, 5, 1]
Output : 4

#endif

using namespace std;

#include <iostream>
#include <vector>

class FirstSmallestMissingPositive {
    static void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
public:
    static int findNumber(vector<int>& nums) {
        // TODO: Write your code here
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] > 0 &&
                nums[i] <= nums.size() && 
                nums[i] != nums[nums[i] - 1]) {
                swap(nums, i, nums[i] - 1);
            }
            else {
                ++i;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return 1 + nums.size();
    }
};

/*

Solution#
This problem follows the Cyclic Sort pattern and shares similarities with Find the Missing Number with one big difference. 
In this problem, the numbers are not bound by any range so we can have any number in the input array.

However, we will follow a similar approach though as discussed in Find the Missing Number to place the numbers on their 
correct indices and ignore all numbers that are out of the range of the array (i.e., all negative numbers and all numbers 
greater than or equal to the length of the array). Once we are done with the cyclic sort we will iterate the array and 
the first index that does not have the correct number will be the smallest missing positive number!

using namespace std;

#include <iostream>
#include <vector>

class FirstSmallestMissingPositive {
 public:
  static int findNumber(vector<int> &nums) {
    int i = 0;
    while (i < nums.size()) {
      if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
        swap(nums, i, nums[i] - 1);
      } else {
        i++;
      }
    }

    for (i = 0; i < nums.size(); i++) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    return nums.size() + 1;
  }

 private:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {-3, 1, 5, 4, 2};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;

  v1 = {3, -2, 0, 1, 2};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;

  v1 = {3, 2, 5, 1};
  cout << FirstSmallestMissingPositive::findNumber(v1) << endl;
}

Time complexity#
The time complexity of the above algorithm is O(n)O(n).

Space complexity#
The algorithm runs in constant space O(1)O(1).


*/

