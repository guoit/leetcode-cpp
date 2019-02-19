/*
[LintCode] 533 Two Sum - Closest to target	- Amazon OA2
Description
Given an array nums of n integers, find two integers in nums such that the sum is closest to a given number, target.

Return the difference between the sum of the two integers and the target.

Example
Given array nums = [-1, 2, 1, -4], and target = 4.

The minimum difference is 1. (4 - (2 + 1) = 1).

Challenge
Do it in O(nlogn) time complexity.
https://yeqiuquan.blogspot.com/2017/04/lintcode-533-two-sum-closest-to-target.html
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	int twoSumClosest(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());

		int res = INT_MAX;
		int i = 0, j = nums.size() - 1;

		while (i < j) {
			if (nums[i] + nums[j] < target) {
				if (target - nums[i] - nums[j] < res)
					res = target - nums[i] - nums[j];
				++i;
			}
			else {
				if (nums[i] + nums[j] - target < res)
					res = nums[i] + nums[j] - target;
				--j;
			}
		}

		return res;
	}

	// follow up: find all pairs with max sum <= target
	vector<pair<int, int>> twoSumLessAndClosest(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		vector<pair<int, int>> res;

		int min_diff = INT_MAX;
		int i = 0, j = nums.size() - 1;
		while (i < j) {
			if (nums[i] + nums[j] <= target) {
				int diff = target - nums[i] - nums[j];
				if (diff < min_diff)	res.clear();
				if (diff <= min_diff) {
					res.push_back({ nums[i], nums[j] });
					min_diff = diff;
				}
				++i;
			}
			else {
				--j;
			}
		}

		return res;
	}
};

//int main() {
//	//vector<int> nums{ -1, 1, 1, 2, 4, -4 };
//	vector<int> nums;
//	Solution obj;
//	auto res = obj.twoSumLessAndClosest(nums, 4);
//
//	cin.get();
//	return 0;
//}