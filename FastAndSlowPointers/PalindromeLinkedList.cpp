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

class PalindromicLinkedList {
public:
    static bool isPalindrome(ListNode* head) {
        // TODO: Write your code here
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // find middle of the LinkedList
        ListNode* mid = middleOfList(head);
        ListNode* headSecondHalf = reverse(mid);  // reverse the second half
        ListNode* copyHeadSecondHalf = headSecondHalf;  // store the head of reversed part to revert back later

        // compare the first and the second half
        while (head != nullptr && headSecondHalf != nullptr) {
            if (head->value != headSecondHalf->value) {
                break;  // not a palindrome
            }
            head = head->next;
            headSecondHalf = headSecondHalf->next;
        }

        reverse(copyHeadSecondHalf);
        return (head == nullptr || headSecondHalf == nullptr);
    }

private:
    static ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    static ListNode* middleOfList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

/*
int main(int argc, char* argv[]) {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(2);
    cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;

    head->next->next->next->next->next = new ListNode(2);
    cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;
}
*/