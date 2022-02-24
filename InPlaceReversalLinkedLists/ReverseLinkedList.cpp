using namespace std;

#include <iostream>

class ListNode {
public:
    int value = 0;
    ListNode* next;

    ListNode(int value) {
        this->value = value;
        next = nullptr;
    }
};

class ReverseLinkedList {
public:
    static ListNode* reverse(ListNode* head) {
        ListNode* current = head;      // current node that we will be processing
        ListNode* previous = nullptr;  // previous node that we have processed
        ListNode* next = nullptr;      // will be used to temporarily store the next node

        while (current != nullptr) {
            next = current->next;      // temporarily store the next node
            current->next = previous;  // reverse the current node
            previous = current;  // before we move to the next node, point previous to the current node
            current = next;      // move on the next node
        }
        // after the loop current will be pointing to 'null' and 'previous' will be the new head
        return previous;
    }
};

int main(int argc, char* argv[]) {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(8);
    head->next->next->next->next = new ListNode(10);

    ListNode* result = ReverseLinkedList::reverse(head);
    cout << "Nodes of the reversed LinkedList are: ";
    while (result != nullptr) {
        cout << result->value << " ";
        result = result->next;
    }
}