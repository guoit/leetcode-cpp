/*
855 Exam Room

In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.

When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  
If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)

Return a class ExamRoom(int N) that exposes two functions: 
ExamRoom.seat() returning an int representing what seat the student sat in, and 
ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  
It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.

Example 1:

Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
Output: [null,0,9,4,2,null,5]
Explanation:
ExamRoom(10) -> null
seat() -> 0, no one is in the room, then the student sits at seat number 0.
seat() -> 9, the student sits at the last seat number 9.
seat() -> 4, the student sits at the last seat number 4.
seat() -> 2, the student sits at the last seat number 2.
leave(4) -> null
seat() -> 5, the student sits at the last seat number 5.
​​​​​​​

Note:

1 <= N <= 10^9
ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.

*/
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class ExamRoom {
public:
	ExamRoom(int N) {
		SEAT_LIMIT = N;
	}

	int seat() {
		if (sit.empty()) {
			sit.insert(0);
			return 0;
		}
		
		int dist = 0, res = 0;	// max distance, and result seat

		auto it = sit.begin();
		// if the first seat is not 0, calculate max distance and result seat
		if (*it != 0) {
			res = 0;	// sit in 0
			dist = *it;	// max distance is (*it - 0)
		}
		
		++it;
		// iterate all seats and update max distance and result seat
		for (; it != sit.end(); ++it) {
			auto pre = prev(it);
			int mid = (*pre + *it) / 2;
			if (mid - *pre > dist) {	// bug fixed: should check the first half distance, not the second half
				dist = mid - *pre;
				res = mid;
			}
		}

		// if the last seat is not N - 1, calculate max distance and result seat
		if (*prev(it) != SEAT_LIMIT - 1) {
			auto pre = prev(it);
			if (SEAT_LIMIT - 1 - *pre > dist) {
				res = SEAT_LIMIT - 1;
			}
		}

		sit.insert(res);	// bug fixed: forgot to insert res into set
		return res;
	}

	void leave(int p) {
		sit.erase(p);
	}

private:
	set<int> sit;
	int SEAT_LIMIT;
};

//int main() {
//	ExamRoom obj(10);
//	cout << obj.seat() << endl;	// expect 0
//	cout << obj.seat() << endl;	// expect 9
//	cout << obj.seat() << endl;	// expect 4
//	cout << obj.seat() << endl;	// expect 2
//	obj.leave(4);
//	cout << obj.seat() << endl;	// expect 5
//
//	cin.get();
//	return 0;
//}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */