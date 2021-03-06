/*
731 My Calendar II

Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.
Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.
A triple booking happens when three events have some non-empty intersection (ie., there is some time that is common to all 3 events.)
For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.
Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
Example 1:
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
Explanation:
The first two events can be booked.  The third event can be double booked.
The fourth event (5, 15) can't be booked, because it would result in a triple booking.
The fifth event (5, 10) can be booked, as it does not use time 10 which is already double booked.
The sixth event (25, 55) can be booked, as the time in [25, 40) will be double booked with the third event;
the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
Note:
The number of calls to MyCalendar.book per test case will be at most 1000.
In calls to MyCalendar.book(start, end), start and end are integers in the range [0, 10^9].
*/
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class MyCalendarII {
public:
	MyCalendarII() {}

	bool book(int start, int end) {

		for (auto t : s2) {
			if (t.second <= start || t.first >= end) continue;
			else return false;
		}

		for (auto t : s1) {
			if (t.second <= start || t.first >= end) continue;
			else s2.insert(make_pair(max(t.first, start), min(t.second, end)));			
		}
		s1.insert(make_pair(start, end));
		return true;
	}

private:
	set<pair<int, int>> s1, s2;
};

// another solution from http://www.cnblogs.com/grandyang/p/7968035.html
class MyCalendarII_Map {
public:
	MyCalendarII_Map() {}

	bool book(int start, int end) {
		++booking[start];
		--booking[end];

		int cnt = 0;
		for (auto b : booking) {
			cnt += b.second;
			if (cnt == 3) {
				--booking[start];
				++booking[end];
				return false;
			}
		}

		return true;
	}

private:
	map<int, int> booking;
};

/*
int main()
{
	MyCalendarII_Map cal;
	cout<<cal.book(10, 20)<<endl; // returns true
	cout << cal.book(50, 60)<<endl; // returns true
	cout << cal.book(10, 40)<<endl; // returns true
	cout << cal.book(5, 15)<<endl; // returns false
	cout << cal.book(5, 10)<<endl; // returns true
	cout << cal.book(25, 55)<<endl; // returns true

	cin.get();
	return 0;
}
*/