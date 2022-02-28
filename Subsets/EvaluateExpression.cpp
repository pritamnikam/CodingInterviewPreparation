/*
Evaluate Expression(hard) #

Given an expression containing digitsand operations(+, -, *), 
find all possible ways in which the expression can be evaluated by grouping the numbersand operators using parentheses.

Example 1:

Input: "1+2*3"
Output : 7, 9
Explanation : 1 + (2 * 3) = > 7 and (1 + 2) * 3 = > 9
Example 2:

Input: "2*3-4-5"
Output : 8, -12, 7, -7, -3
Explanation : 2 * (3 - (4 - 5)) = > 8, 2 * (3 - 4 - 5) = > -12, 2 * 3 - (4 - 5) = > 7, 2 * (3 - 4) - 5 = > -7, (2 * 3) - 4 - 5 = > -3

Solution #
This problem follows the Subsets pattern and can be mapped to Balanced Parentheses. We can follow a similar BFS approach.

Let’s take Example-1 mentioned above to generate different ways to evaluate the expression.

We can iterate through the expression character-by-character.
we can break the expression into two halves whenever we get an operator (+, -, *).
The two parts can be calculated by recursively calling the function.
Once we have the evaluation results from the left and right halves, we can combine them to produce all results.

*/


using namespace std;

#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class EvaluateExpression {
    static unordered_map<string, vector<int>> map = unordered_map<string, vector<int>>();
public:
    static vector<int> diffWaysToEvaluateExpression(const string& input) {
        if (map.find(input) != map.end()) {
            return map[input];
        }

        vector<int> result;

        // base case: if the input string is a number, parse and add it to output.
        if (input.find("+") == string::npos && 
            input.find("-") == string::npos &&
            input.find("*") == string::npos) {
            result.push_back(stoi(input));
        }
        else {
            // search for operator:
            for (int i = 0; i < input.length(); i++) {
                char chr = input[i];
                if (!isdigit(chr)) {
                    // break the equation here into two parts and make recursively calls
                    vector<int> leftParts = diffWaysToEvaluateExpression(input.substr(0, i));
                    vector<int> rightParts = diffWaysToEvaluateExpression(input.substr(i + 1));

                    // for every parts from left
                    for (auto part1 : leftParts) {

                        // for every parts from right
                        for (auto part2 : rightParts) {
                            if (chr == '+') {
                                result.push_back(part1 + part2);
                            }
                            else if (chr == '-') {
                                result.push_back(part1 - part2);
                            }
                            else if (chr == '*') {
                                result.push_back(part1 * part2);
                            }
                        }
                    }
                }
            }
        }
        map[input] = result;
        return result;
    }
};

int main(int argc, char* argv[]) {
    vector<int> result = EvaluateExpression::diffWaysToEvaluateExpression("1+2*3");
    cout << "Expression evaluations: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    result = EvaluateExpression::diffWaysToEvaluateExpression("2*3-4-5");
    cout << "Expression evaluations: ";
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
}