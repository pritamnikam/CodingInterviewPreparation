using namespace std;

#include <iostream>

/*
If we know the length of the LinkedList cycle, we can find the start of the cycle through the following steps:

Take two pointers. Let’s call them pointer1 and pointer2.
Initialize both pointers to point to the start of the LinkedList.
We can find the length of the LinkedList cycle using the approach discussed in LinkedList Cycle. Let’s assume that the length of the cycle is ‘K’ nodes.
Move pointer2 ahead by ‘K’ nodes.
Now, keep incrementing pointer1 and pointer2 until they both meet.
As pointer2 is ‘K’ nodes ahead of pointer1, which means, pointer2 must have completed one loop in the cycle when both pointers meet. Their meeting point will be the start of the cycle.


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

class LinkedListCycleStart {
public:
    static ListNode* findCycleStart(ListNode* head) {
        int cycleLength = 0;
        // find the LinkedList cycle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {  // found the cycle
                cycleLength = calculateCycleLength(slow);
                break;
            }
        }

        return findStart(head, cycleLength);
    }

private:
    static int calculateCycleLength(ListNode* slow) {
        ListNode* current = slow;
        int cycleLength = 0;
        do {
            current = current->next;
            cycleLength++;
        } while (current != slow);

        return cycleLength;
    }

    static ListNode* findStart(ListNode* head, int cycleLength) {
        ListNode* pointer1 = head, * pointer2 = head;
        // move pointer2 ahead 'cycleLength' nodes
        while (cycleLength > 0) {
            pointer2 = pointer2->next;
            cycleLength--;
        }

        // increment both pointers until they meet at the start of the cycle
        while (pointer1 != pointer2) {
            pointer1 = pointer1->next;
            pointer2 = pointer2->next;
        }

        return pointer1;
    }
};
#if 0
int main(int argc, char* argv[]) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    head->next->next->next->next->next->next = head->next->next;
    cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

    head->next->next->next->next->next->next = head->next->next->next;
    cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;

    head->next->next->next->next->next->next = head;
    cout << "LinkedList cycle start: " << LinkedListCycleStart::findCycleStart(head)->value << endl;
}
#endif