/*
Problem Statement #
Every non - negative integer N has a binary representation, for example, 8 can be represented as “1000” in binary and 7 as “0111” in binary.

The complement of a binary representation is the number in binary that we get when we change every 1 to a 0 and every 0 to a 1. For example, the binary complement of “1010” is “0101”.

For a given positive number N in base - 10, return the complement of its binary representation as a base - 10 integer.

Example 1:

Input: 8
Output : 7
Explanation : 8 is 1000 in binary, its complement is 0111 in binary, which is 7 in base - 10.
Example 2 :

	Input : 10
	Output : 5
	Explanation : 10 is 1010 in binary, its complement is 0101 in binary, which is 5 in base - 10.
*/

#include <iostream>

using namespace std;

class CalculateComplement {
public:
    static int bitwiseComplement(int num) {
        // TODO: Write your code here
        int bitCount = 0;
        int n = num;
        while (n > 0) {
            n = n >> 1;
            ++bitCount;
        }

        int all_bits_set = ((1 << bitCount) - 1);
        return num ^ all_bits_set;
    }
};

int main(int argc, char* argv[]) {
    // your code goes here
    cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(8) << endl;
    cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(10) << endl;
}