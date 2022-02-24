#if 0

Frequency Stack


Design a class that simulates a Stack data structure, implementing the following two operations :

push(int num) : Pushes the number ‘num’ on the stack.
pop() : Returns the most frequent number in the stack.If there is a tie, return the number which was pushed later.
Example :

After following push operations : push(1), push(2), push(3), push(2), push(1), push(2), push(5)

1. pop() should return 2, as it is the most frequent number
2. Next pop() should return 1
3. Next pop() should return 2


#endif
using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

struct ValueCompare {
    bool operator() (const pair<int, int>& x, const pair<int, int>& y) {
        if (x.second == y.second) // frequency is same
            return x.first > y.first; // return smaller index
        return (x.second < y.second);
    }
};

class FrequencyStack {
    unordered_map<int, int> freqMap;
public:
    virtual void push(int num) {
        // TODO: Write your code here
        freqMap[num]++;
    }

    virtual int pop() {
        // TODO: Write your code here
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            ValueCompare> maxHeap;

        for (auto it : freqMap) {
            maxHeap.push({ it.first, it.second });
        }

        auto currentEntry = maxHeap.top();
        maxHeap.pop();
        freqMap[currentEntry.first]--;
        if (freqMap[currentEntry.first] == 0)
            freqMap.erase(currentEntry.first);

        return currentEntry.first;
    }
};

int main(int argc, char* argv[]) {
    FrequencyStack frequencyStack;
    frequencyStack.push(1);
    frequencyStack.push(2);
    frequencyStack.push(3);
    frequencyStack.push(2);
    frequencyStack.push(1);
    frequencyStack.push(2);
    frequencyStack.push(5);
    cout << frequencyStack.pop() << endl;
    cout << frequencyStack.pop() << endl;
    cout << frequencyStack.pop() << endl;
}

#if 0
/*
Solution#
This problem follows the Top ‘K’ Elements pattern, and shares similarities with Top ‘K’ Frequent Numbers.

We can use a Max Heap to store the numbers. Instead of comparing the numbers we will compare their frequencies
so that the root of the heap is always the most frequently occurring number. There are two issues that need to 
be resolved though:

How can we keep track of the frequencies of numbers in the heap? When we are pushing a new number to the Max Heap,
we don’t know how many times the number has already appeared in the Max Heap. To resolve this, we will maintain a 
HashMap to store the current frequency of each number. Thus whenever we push a new number in the heap, we will 
increment its frequency in the HashMap and when we pop, we will decrement its frequency.

If two numbers have the same frequency, we will need to return the number which was pushed later while popping. 
To resolve this, we need to attach a sequence number to every number to know which number came first.
In short, we will keep three things with every number that we push to the heap:

    1. number // value of the number
    2. frequency // current frequency of the number when it was pushed to the heap
    3. sequenceNumber // a sequence number, to know what number came first
Code

*/
using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class Element {
public:
    int number = 0;
    int frequency = 0;
    int sequenceNumber = 0;

    Element(int number, int frequency, int sequenceNumber) {
        this->number = number;
        this->frequency = frequency;
        this->sequenceNumber = sequenceNumber;
    }
};

class FrequencyStack {
public:
    struct frequencyCompare {
        bool operator()(const Element& e1, const Element& e2) {
            if (e1.frequency != e2.frequency) {
                return e2.frequency > e1.frequency;
            }
            // if both elements have same frequency, return the one that was pushed later
            return e2.sequenceNumber > e1.sequenceNumber;
        }
    };

    int sequenceNumber = 0;
    priority_queue<Element, vector<Element>, frequencyCompare> maxHeap;
    unordered_map<int, int> frequencyMap;

    virtual void push(int num) {
        frequencyMap[num] += 1;
        maxHeap.push({ num, frequencyMap[num], sequenceNumber++ });
    }

    virtual int pop() {
        int num = maxHeap.top().number;
        maxHeap.pop();

        // decrement the frequency or remove if this is the last number
        if (frequencyMap[num] > 1) {
            frequencyMap[num] -= 1;
        }
        else {
            frequencyMap.erase(num);
        }

        return num;
    }
};

int main(int argc, char* argv[]) {
    FrequencyStack frequencyStack;
    frequencyStack.push(1);
    frequencyStack.push(2);
    frequencyStack.push(3);
    frequencyStack.push(2);
    frequencyStack.push(1);
    frequencyStack.push(2);
    frequencyStack.push(5);
    cout << frequencyStack.pop() << endl;
    cout << frequencyStack.pop() << endl;
    cout << frequencyStack.pop() << endl;
}
#endif