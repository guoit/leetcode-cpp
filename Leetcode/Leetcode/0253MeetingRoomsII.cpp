/*
253 Meeting Rooms II

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/
#include <vector>
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
	int minMeetingRooms(vector<Interval>& intervals) {
	}
};