/*
220 Contains Duplicate III

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
	// http://www.cnblogs.com/grandyang/p/4545261.html
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (k <= 0 || t < 0)	return false;

		map<long, int> m;
		int j = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (i - j > k)	m.erase(nums[j++]);	// don't worry there could be a duplicated element being erased between j and i, because if that duplicate exists, previously function already returns true.
			auto it = m.lower_bound((long)nums[i] - t);
			if ((it != m.end()) && (it->first <= nums[i] + t))	return true;
			m[nums[i]] = j;
		}

		return false;
	}
};

int main() {
	vector<int> nums = {1, 2, 3, 1};
	int k = 3, t = 0;
	Solution obj;
	cout << obj.containsNearbyAlmostDuplicate(nums, k, t);
	cin.get();
	return 0;
}