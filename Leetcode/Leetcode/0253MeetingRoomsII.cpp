/*
253 Meeting Rooms II

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval(int s, int e) {
		start = s;
		end = e;
	}
};
class Solution {
public:
	// method 1: use a map to count the "start" and "end" times on specific time. Increase count by 1 for start time, and decrease count by 1 for end time
	// as map automatically sort the time, so then we iterate the map and update the max rooms we need
	int minMeetingRooms(vector<Interval>& intervals) {
		map<int, int> m;
		for (const auto &i : intervals) {
			++m[i.start];
			--m[i.end];
		}

		int res = 0, rooms = 0;
		for (const auto &t : m) {
			rooms += t.second;
			res = max(res, rooms);
		}

		return res;
	}

	// method 2: use two arrays to store start time and end time separately, then sort the two arrays.
	// Then use two pointers, one points to start time array, one points to end time array
	// if start time < end time, we increase room, otherwise we advance the end time pointer
	int minMeetingRooms2(vector<Interval>& intervals) {
		vector<int> start, end;
		for (const auto &i : intervals) {
			start.push_back(i.start);
			end.push_back(i.end);
		}

		sort(start.begin(), start.end());
		sort(end.begin(), end.end());

		int res = 0, endpos = 0;
		for (int s : start) {
			if (s < end[endpos]) {
				++res;
			}
			else {
				++endpos;
			}
		}

		return res;
	}

	// method 3: use a min heap to store the end time, every time when we insert a new interval, we find the min end time, then remove it and add the new interval's end time into min heap
	int minMeetingRooms3(vector<Interval>& intervals) {
		priority_queue<int, vector<int>, std::greater<int>> q;	// min heap
		for (const auto &i : intervals) {
			if (!q.empty() && q.top() <= i.start) {
				q.pop();
			}
			q.push(i.end);
		}

		return q.size();
	}
};

//int main() {
//	vector<Interval> v = { Interval(0, 30), Interval(5, 10), Interval(15, 20) };
//	Solution obj;
//	cout << obj.minMeetingRooms3(v) << endl;
//
//	cin.get();
//	return 0;
//}