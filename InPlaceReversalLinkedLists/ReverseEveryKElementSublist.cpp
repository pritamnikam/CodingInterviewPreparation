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

class ReverseEveryKElements {
public:
    static ListNode* reverse(ListNode* head, int k) {
		// base cases:
		if (head == nullptr || k < 2)
			return head;

		// Make sure we do have enough nodes
		int count = 0;
		ListNode* cur = head;
		while (cur && count < k) {
			cur = cur->next;
			++count;
		}

		// otherwise, return original list
		if (count < k)
			return head;


		cur = head;
		count = 0;
		ListNode* prev = nullptr;
		ListNode* next = nullptr;

		// iterative version of reversing the list
		while (count < k) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
			++count;
		}

		// recurrively call the reverse in-group for next group
		if (next != nullptr) {
			head->next = reverse(next, k);
		}

		return prev;
    }
};

int main(int argc, char* argv[]) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    ListNode* result = ReverseEveryKElements::reverse(head, 3);
    cout << "Nodes of the reversed LinkedList are: ";
    while (result != nullptr) {
        cout << result->value << " ";
        result = result->next;
    }
}