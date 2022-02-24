#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct MinStack {
	stack<int> st;
	stack<int> auxSt;

	void Push(int n) {
		st.push(n);

		if (auxSt.empty() || MinElement() > n)
			auxSt.push(n);
	}

	void Pop() {
		if (st.empty())
			return;

		if (st.top() == MinElement())
			auxSt.pop();

		st.pop();
	}

	int Top() {
		return st.top();
	}

	int MinElement() {
		return (auxSt.empty()) ? -1 : auxSt.top();
	}
};