using namespace std;

#include <iostream>

/*
We can use the above solution to find the cycle in the LinkedList. 

Once the fast and slow pointers meet, we can save the slow pointer and iterate the whole cycle 
with another pointer until we see the slow pointer again to find the length of the cycle.

*/

class ListNode {
public:
    int value = 0;
    ListNode* next;

    ListNode(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedListCycle {
public:
    static int findCycleLength(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)  // found the cycle
            {
                return calculateLength(slow);
            }
        }
        return 0;
    }

private:
    static int calculateLength(ListNode* slow) {
        ListNode* current = slow;
        int cycleLength = 0;
        do {
            current = current->next;
            cycleLength++;
        } while (current != slow);
        return cycleLength;
    }
};

// Time and Space Complexity: 
// The above algorithm runs in O(N) time complexity and O(1) space complexity.

