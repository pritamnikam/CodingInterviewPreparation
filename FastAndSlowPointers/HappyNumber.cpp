using namespace std;

#include <iostream>

/*
The process, defined above, to find out if a number is a happy number or not, always ends in a cycle.

If the number is a happy number, the process will be stuck in a cycle on number ‘1,’ and if the number 
is not a happy number then the process will be stuck in a cycle with a set of numbers.
*/

class HappyNumber {
public:
    static bool find(int num) {
        int slow = num, fast = num;
        do {
            slow = findSquareSum(slow);                 // move one step
            fast = findSquareSum(findSquareSum(fast));  // move two steps
        } while (slow != fast);                         // found the cycle

        return slow == 1;  // see if the cycle is stuck on the number '1'
    }

private:
    static int findSquareSum(int num) {
        int sum = 0, digit;
        while (num > 0) {
            digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }
};

/*
int main(int argc, char* argv[]) {
    cout << HappyNumber::find(23) << endl;
    cout << HappyNumber::find(12) << endl;
}
*/