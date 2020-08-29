/*
327 Count of Range Sum

Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:

Input: nums = [-2,5,-1], lower = -2, upper = 2,
Output: 3
Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective sums are: -2, -1, 2.
*/
#include <vector>
#include <set>
#include <iostream>
using namespace std;
class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		multiset<long long> m;
		m.insert(0); // Trick! This is for the accumulation sum up to current num
		long long sum = 0;
		int res = 0;
		for (int num : nums) {
			sum += num;
			res += distance(m.lower_bound(sum - upper), m.upper_bound(sum - lower));
			m.insert(sum);
		}

		return res;
	}

};

//int main() {
//	vector<int> nums{-2, 5, -1};
//	int lower = -2, upper = 2;
//	Solution obj;
//	cout << obj.countRangeSum(nums, lower, upper)<<endl;
//	cin.get();
//	return 0;
//}
