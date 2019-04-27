/*
324 Wiggle Sort II

Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.
Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include "utilities.h"
using namespace std;

class Solution {
public:
	void WiggleSort(vector<int>& nums) {
#define A(i) nums[(1 + 2*i) % (n | 1)]
		int n = nums.size(), i = 0, j = 0, k = n - 1;
		auto midptr = nums.begin() + n / 2;
		nth_element(nums.begin(), midptr, nums.end());
		myprint(nums);

		int mid = *midptr;
		while (j <= k) {
			cout << "i=" << i << ", A(i) = " << A(i) << endl;
			cout << "j=" << j << ", A(j) = " << A(j) << endl;
			cout << "k=" << k << ", A(k) = " << A(k) << endl;
			cout << endl;
			if (A(j) > mid)	swap(A(i++), A(j++));
			else if (A(j) < mid)	swap(A(j), A(k--));
			else	++j;
		}
	}
};

int main() {
	vector<int> nums = { 1, 5, 1, 1, 6, 4 };
	Solution obj;
	obj.WiggleSort(nums);
	for (auto num : nums) {
		cout << num << ' ';
	}
	cout << endl;
	cin.get();

	return 0;
}