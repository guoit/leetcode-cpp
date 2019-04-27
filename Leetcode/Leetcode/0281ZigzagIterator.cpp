/*
281 Zigzag Iterator

Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].
*/
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class ZigzagIterator {
public:
	ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		it = {v1.begin(), v2.begin()};
		end = {v1.end(), v2.end()};
		cur = 0;
	}
	int next() {
		int value = *it[cur];	// get current value
		++it[cur];	// advance current iterator
		cur ^= 1;	// switch to another iterator
		if (it[cur] == end[cur]) {	// if another iterator reaches end, switch iterator back
			cur ^= 1;
		}

		return value;
	}
	bool hasNext() {
		return (it[0] != end[0]) || (it[1] != end[1]) ;
	}
private:
	vector<vector<int>::iterator> it;
	vector<vector<int>::iterator> end;
	int cur = 0;
};

// follow-up solution with a queue
class ZigzagIterator2 {
public:
	ZigzagIterator2(vector<int>&v1, vector<int>&v2) {
		if (!v1.empty())	q.push({ v1.begin(), v1.end() });
		if (!v2.empty())	q.push({ v2.begin(), v2.end() });
	}
	int next() {
		auto t = q.front();	q.pop();
		int value = *(t.first++);
		if (t.first != t.second) {
			q.push(t);
		}

		return value;
	}
	bool hasNext() {
		return !q.empty();
	}
private:
	queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};

//int main() {
//	vector<int> v1 = { 1,2 };
//	vector<int> v2 = {3,4,5,6};
//	ZigzagIterator2 obj(v1, v2);
//	while (obj.hasNext()) {
//		cout << obj.next() << endl;
//	}
//	cin.get();
//
//	return 0;
//}