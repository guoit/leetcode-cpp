/*
716 Max Stack

Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.

Example 1:
MaxStack stack = new MaxStack();
stack.push(5);
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5

Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
*/
#include <map>
#include <vector>
#include <list>
using namespace std;
class MaxStack {
public:
	/** initialize your data structure here. */
	MaxStack() {

	}

	void push(int x) {
		ll.push_front(x);
		m[x].push_back(ll.begin());
	}

	int pop() {
		int x = ll.front();
		m[x].pop_back();
		if (m[x].empty()) m.erase(x);
		ll.pop_front();

		return x;
	}

	int top() {
		return ll.front();
	}

	int peekMax() {
		return m.rbegin()->first;
	}

	int popMax() {
		int x = m.rbegin()->first;
		auto it = m[x].back();

		m[x].pop_back();
		if (m[x].empty()) m.erase(x);

		ll.erase(it);

		return x;
	}
private:
	list<int> ll; // stores the elements, front is the operating end of "stack"
	map<int, vector<list<int>::iterator>> m; // ordered map to hold pairs of value and a vector of its iterators in list
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */