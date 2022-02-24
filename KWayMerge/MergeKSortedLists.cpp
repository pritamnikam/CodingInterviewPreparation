/*
Merge K Sorted Lists

Problem Statement #
Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.

Example 1:

Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]
Example 2:

Input: L1=[5, 8, 9], L2=[1, 7]
Output: [1, 5, 7, 8, 9]


*/


using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ListNode {
public:
    int value = 0;
    ListNode* next;

    ListNode(int value) {
        this->value = value;
        this->next = nullptr;
    }
};


struct Compare {
    bool operator()(const ListNode* a, const ListNode* b) { return a->value > b->value; }
};

class MergeKSortedLists {
public:
    static ListNode* merge(const vector<ListNode*>& lists) {
        ListNode* resultHead = nullptr;
        // TODO: Write your code here
        priority_queue < ListNode*, vector<ListNode*>, Compare> mh;
        for (auto l : lists) {
            if (l != nullptr)
                mh.push(l);
        }

        ListNode* t = nullptr;
        while (!mh.empty()) {
            ListNode* cur = mh.top();
            mh.pop();

            // first in the list
            if (resultHead == nullptr) {
                resultHead = t = cur;
            }
            else {
                t->next = cur;
                t = cur;
            }

            // insert next from the same list
            if (cur->next)
                mh.push(cur->next);
        }

        return resultHead;
    }
};

int main(int argc, char* argv[]) {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(6);
    l1->next->next = new ListNode(8);

    ListNode* l2 = new ListNode(3);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(7);

    ListNode* l3 = new ListNode(1);
    l3->next = new ListNode(3);
    l3->next->next = new ListNode(4);

    ListNode* result = MergeKSortedLists::merge(vector<ListNode*>{l1, l2, l3});
    cout << "Here are the elements form the merged list: ";
    while (result != nullptr) {
        cout << result->value << " ";
        result = result->next;
    }
}

/*

Solution #
A brute force solution could be to add all elements of the given ‘K’ lists to one list and sort it. If there are a total of ‘N’ elements in all the input lists, then the brute force solution will have a time complexity of O(N*logN)O(N∗logN) as we will need to sort the merged list. Can we do better than this? How can we utilize the fact that the input lists are individually sorted?

If we have to find the smallest element of all the input lists, we have to compare only the smallest (i.e. the first) element of all the lists. Once we have the smallest element, we can put it in the merged list. Following a similar pattern, we can then find the next smallest element of all the lists to add it to the merged list.

The best data structure that comes to mind to find the smallest number among a set of ‘K’ numbers is a Heap. Let’s see how can we use a heap to find a better algorithm.

We can insert the first element of each array in a Min Heap.
After this, we can take out the smallest (top) element from the heap and add it to the merged list.
After removing the smallest element from the heap, we can insert the next element of the same list into the heap.
We can repeat steps 2 and 3 to populate the merged list in sorted order.

Time complexity #
Since we’ll be going through all the elements of all arrays and will be removing/adding one element to the heap in each step, the time complexity of the above algorithm will be O(N*logK),O(N∗logK), where ‘N’ is the total number of elements in all the ‘K’ input arrays.

Space complexity #
The space complexity will be O(K)  because, at any time, our min-heap will be storing one number from all the ‘K’ input arrays.


using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

class MergeKSortedLists {
 public:
  struct valueCompare {
    bool operator()(const ListNode *x, const ListNode *y) { return x->value > y->value; }
  };

  static ListNode *merge(const vector<ListNode *> &lists) {
    priority_queue<ListNode *, vector<ListNode *>, valueCompare> minHeap;

    // put the root of each list in the min heap
    for (auto root : lists) {
      if (root != nullptr) {
        minHeap.push(root);
      }
    }

    // take the smallest (top) element form the min-heap and add it to the result;
    // if the top element has a next element add it to the heap
    ListNode *resultHead = nullptr, *resultTail = nullptr;
    while (!minHeap.empty()) {
      ListNode *node = minHeap.top();
      minHeap.pop();
      if (resultHead == nullptr) {
        resultHead = resultTail = node;
      } else {
        resultTail->next = node;
        resultTail = resultTail->next;
      }
      if (node->next != nullptr) {
        minHeap.push(node->next);
      }
    }

    return resultHead;
  }
};

int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(6);
  l1->next->next = new ListNode(8);

  ListNode *l2 = new ListNode(3);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(7);

  ListNode *l3 = new ListNode(1);
  l3->next = new ListNode(3);
  l3->next->next = new ListNode(4);

  ListNode *result = MergeKSortedLists::merge(vector<ListNode *>{l1, l2, l3});
  cout << "Here are the elements form the merged list: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
*/

