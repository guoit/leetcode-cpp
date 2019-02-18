/*
Flight

All aircraft have a fixed maximum operating travel distance. The goal is to optimize the total operating travel distance of a given aircraft. 
A forward/return shipping route pair is "optimal" if there does not exist another pair that has a higher operating travel distance than this pair, and also has a total less than or equal to the maximum operating travel distance of the aircraft.

Input:
maximumOperatingTravelDistance	-	an integer representing the maximum operating travel distance of the given aircraft;
forwardShippingRouteList	-	a list of pairs of integers where the first integer represents the unique identifier of a forward shipping route and the second integer represents the amount of travel distance required by this shipping route;
returnShippingRouteList		-	a list of pairs of integers where the first integer represents the unique identifier of a return shipping route and the second integer represents the amount of travel distance required by this shipping route;

Output:
Return a list of pairs of integers representing the pairs of IDs of forward and return shipping routes that optimally utilize the given aircraft. If no route is possible, return an empty list.

Example:

Input:
maximumOperatingTravelDistance = 10000
forwardShippingRouteList = [[1, 3000], [2, 5000], [3, 7000], [4, 10000]]
returnShippingRouteList = [[1, 2000], [2, 3000], [3, 4000], [4, 5000]]

Output:
[[2, 4], [3, 2]]
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include "utilities.h"
using namespace std;

class Solution {
public:
	// sort the two lists first
	// use two pointers, f from forward list's begin to end, r from return list's end to begin
	// for each f, we just need to move r to left until the sum <= maxDist
	vector<pair<int, int>> flight(int maxDist, vector<pair<int, int>> &forwardList, vector<pair<int, int>> &returnList) {
		// sort the input lists based on the travel distance
		auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)->bool {return a.second < b.second; };
		sort(forwardList.begin(), forwardList.end(), cmp);
		sort(returnList.begin(), returnList.end(), cmp);

		long curMax = LONG_MIN;
		vector<pair<int, int>> res;
		auto f = forwardList.begin();	// f iterates from forward list's begin to end
		auto r = returnList.rbegin();	// r iterates from return list's end to begin

		for (; f != forwardList.end(); ++f) {
			while ((r != returnList.rend()) && (f->second + r->second > maxDist)) {
				++r;
			}

			if (r != returnList.rend()) {
				long curSum = f->second + r->second;
				if (curSum >= curMax) {
					if (curSum > curMax)	res.clear();
					curMax = curSum;
					res.push_back({ f->first, r->first });
				}
			}
		}

		return res;
	}
};

//int main() {
//
//	int maxDist = 10000;
//	vector<pair<int, int>> forwardList = { {1, 3000},{2, 5000},{3, 7000},{4, 10000} };
//	vector<pair<int, int>> returnList = { {1, 2000},{2, 3000},{3, 4000},{4, 5000} };
//	Solution obj;
//	auto res = obj.flight(maxDist, forwardList, returnList);
//
//	cin.get();
//	return 0;
//}