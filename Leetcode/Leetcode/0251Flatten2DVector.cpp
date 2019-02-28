/*
251 Flatten 2D Vector

Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =
[
  [1,2],
  [3],
  [4,5,6]
]

By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

Hint:

How many variables do you need to keep track?
Two variables is all you need. Try with x and y.
Beware of empty rows. It could be the first few rows.
To write correct code, think about the invariant to maintain. What is it?
The invariant is x and y must always point to a valid point in the 2d vector. Should you maintain your invariant ahead of time or right when you need it?
Not sure? Think about how you would implement hasNext(). Which is more complex?
Common logic in two different places should be refactored into a common method.
Follow up:
As an added challenge, try to code it using only iterators in C++ or iterators in Java.
*/
#include <vector>
#include <iostream>
using namespace std;
class Vector2D {
public:
	Vector2D(vector<vector<int>>& vec2d) {
		it = vec2d.begin();
		end = vec2d.end();
	}
	int next() {
		return (*it)[y++];
	}
	bool hasNext() {
		while (it != end && y == it->size()) {
			++it;
			y = 0;
		}

		return it != end;
	}
private:
	vector<vector<int>>::iterator it, end;
	int y;
};

int main() {
	vector<vector<int>> v2 = { {1, 2}, {3}, {5,6 } };
	Vector2D v(v2);
	while (v.hasNext()) {
		cout << v.next() << endl;
	}

	cin.get();
	return 0;
}
