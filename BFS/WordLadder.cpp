// 127. Word Ladder
// https://leetcode.com/problems/word-ladder/
//

/*
Given a dictionary, and two words start and target (both of the same length).
Find length of the smallest chain from start to target if it exists, such that adjacent words 
in the chain only differ by one character and each word in the chain is a valid word i.e., 
it exists in the dictionary. It may be assumed that the target word exists in the dictionary 
and the lengths of all the dictionary words are equal.


It falls under pathfinding problem.
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int ladderLength(string beginWord,
    string endWord,
    vector<string>& wordList) {
    unordered_set<string> dictionary(wordList.begin(), wordList.end());

    // start and end are equal
    if (beginWord == endWord)
        return 0;

    // If the target String is not present in the dictionary
    if (dictionary.find(endWord) == dictionary.end())
        return 0;

    // To store the current chain length and the length of the words
    int level = 0, wordLength = beginWord.length();

    // Queue
    queue<string> q;
    q.push(beginWord);

    // BFS:
    while (!q.empty()) {
        ++level; // Increment the chain length
        int qLength = q.size(); // Current size of the queue

        // for all words at the level:
        for (int i = 0; i < qLength; ++i) {
            string word = q.front();
            q.pop();

            // for every char in word
            for (int j = 0; j < word.length(); ++j) {
                char orgChar = word[j];

                // replace with other char
                for (char c = 'a'; c <= 'z'; ++c) {
                    word[j] = c;

                    // If the new word is equal to the target word
                    if (word == endWord)
                        return level + 1;

                    // Remove the word from the set if it is found in it
                    if (dictionary.find(word) == dictionary.end())
                        continue;

                    dictionary.erase(word);

                    // And push the newly generated word
                    // which will be a part of the chain
                    q.push(word);
                } // for-char

                // restore
                word[j] = orgChar;

            } // for-word
        } // for-level
    } // queue

    return 0;
}
