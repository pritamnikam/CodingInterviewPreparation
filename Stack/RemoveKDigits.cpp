#if 0


402. Remove K Digits

Given string num representing a non - negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.



Example 1:

Input: num = "1432219", k = 3
Output : "1219"
Explanation : Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2 :

    Input : num = "10200", k = 1
    Output : "200"
    Explanation : Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
    Example 3 :

    Input : num = "10", k = 2
    Output : "0"
    Explanation : Remove all the digits from the number and it is left with nothing which is 0.


    Constraints :

    1 <= k <= num.length <= 105
    num consists of only digits.
    num does not have any leading zeros except for the zero itself.

#endif

using namespace std;

#include <stack>
#include <string>

/*
Use stack to collect numbers in ascending order.

iterate through the array and 
keep removing until we find top of stack is smaller that the current number

*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k < 1)
            return 0;

        if (num.size() < k)
            return "0";

        string result;
        stack<char> st;

        // result will be present in stack in ascending order
        st.push(num[0]);

        for (int i = 0; i < num.size(); ++i) {

            // make sure we only push if top of stack is smaller than the num[i].
            while (k > 0 &&
                !st.empty() &&
                st.top() > num[i]) {
                st.pop();
                --k;
            }

            // push to stack
            st.push(num[i]);

            // make sure that we dont have trailing zeros
            if (st.size() == 1 && st.top() == '0') {
                st.pop();
            }
        }

        // remove the numbers from stack as required number of deletion is not reached
        while (k > 0 && !st.empty()) {
            st.pop();
            --k;
        }

        // we have our answer, lets collect to our result arry;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        // result need to be reveres as stack has entries in ascending order
        reverse(result.begin(), result.end());
        return result.empty() ? "0" : result;
    }
};