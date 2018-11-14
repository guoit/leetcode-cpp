/*
34 Search for a Range

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		auto bounds = equal_range(nums.begin(), nums.end(), target);

		if (bounds.first == bounds.second) {
			return { -1, -1 };
		}
		else
		{
			//return { bounds.first - nums.begin(), bounds.second - nums.begin() - 1 };
			//return { distance(nums.begin(), bounds.first), distance(nums.begin(), bounds.second) - 1 };
			return { -1, -1 };
		}
	}
};