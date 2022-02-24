/*
Word Ladder – Set 2 ( Bi-directional BFS )
https://www.geeksforgeeks.org/word-ladder-set-2-bi-directional-bfs/

Given a dictionary, and two words start and target (both of the same length). 
Find length of the smallest chain from start to target if it exists, such that adjacent words 
in the chain only differ by one character and each word in the chain is a valid word i.e., 
it exists in the dictionary. It may be assumed that the target word exists in the dictionary 
and the lengths of all the dictionary words are equal.

Examples:
Input: Dictionary = {POON, PLEE, SAME, POIE, PLEA, PLIE, POIN}
start = “TOON”
target = “PLEA”
Output: 7
TOON -> POON –> POIN –> POIE –> PLIE –> PLEE –> PLEA

*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

bool IsAdjustant(string& a, string& b) {
    int count = 0;
    for (int i = 0; i < a.length(); ++i)
        if (a[i] != b[i])
            ++count;

    return (count == 1);
}

struct Node {
    string word;
    int length;
};

int ladderLength(string beginWord,
                string endWord,
                vector<string>& wordList) {
    if (beginWord == endWord)
        return 0;

    unordered_set<string> dictionary(wordList.begin(), wordList.end());
    if (dictionary.find(endWord) == dictionary.end())
        return 0;

    int dictionaryLength = dictionary.size();

    unordered_map<string, int> visited1;
    unordered_map<string, int> visited2;

    queue<Node> q1;
    queue<Node> q2;

    q1.push({ beginWord, 1 });
    q2.push({ endWord, 1 });

    visited1[beginWord]++;
    visited2[endWord]++;

    // bi-directional BFS
    while (!q1.empty() && !q2.empty()) {
        Node curr1 = q1.front();
        q1.pop();

        Node curr2 = q2.front();
        q2.pop();

        // Check all the neighbors of curr1
        for (auto it : dictionary) {
            if (!visited1.count(it) && IsAdjustant(curr1.word, it)) {
                // reached end
                if (it == endWord) {
                    return curr1.length + 1;
                }

                // meet-in-middle
                if (visited2.count(it)) {
                    return curr1.length + visited2[it];
                }

                // enque this new word
                q1.push({ it, curr1.length + 1 });
                visited1[it] = curr1.length + 1;
            }
        }

        // Check all the neighbors of curr2
        for (auto it : dictionary) {
            if (!visited2.count(it) && IsAdjustant(curr2.word, it)) {
                // reached end
                if (it == endWord) {
                    return curr2.length + 1;
                }

                // meet-in-middle
                if (visited1.count(it)) {
                    return curr2.length + visited1[it];
                }

                // enque this new word
                q2.push({ it, curr2.length + 1 });
                visited2[it] = curr2.length + 1;
            }
        }
    } // while-bfs

    return 0;
}