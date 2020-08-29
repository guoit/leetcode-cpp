/*
287 Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist.
Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
#include <vector>

using namespace std;
class Solution {
public:
	// binary search solution, O(nlogn) time
	int findDuplicate(vector<int>& nums) {
		int left = 1, right = nums.size();
		while (left < right) {
			int mid = (left + right) / 2;
			int count = 0;
			for (int num : nums) {
				if (num <= mid) count++;
			}
			if (count <= mid) left = mid + 1;
			else right = mid;
		}

		return right;
	}

	// linked list cycle detection method, O(n) time
	int findDuplicate2(vector<int>& nums) {
		int slow = 0, fast = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);

		fast = 0;
		do {
			slow = nums[slow];
			fast = nums[fast];
		} while (slow != fast);

		return slow;
	}

	// bits calculation, O(n) time
	int findDuplicate3(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < 32; ++i) {
			int bit = 1 << i;
			int cnt1 = 0, cnt2 = 0;
			for (int j = 0; j < nums.size(); ++j) {
				if (j & bit) cnt1++;
				if (nums[j] & bit) cnt2++;
			}
			if (cnt2 > cnt1) res += bit;
		}

		return res;
	}
};