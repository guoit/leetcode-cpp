/*
493 Reverse Pairs

Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
*/
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
	// BIT solution
	int reversePairs(vector<int>& nums) {
		int res = 0, n = nums.size();
		vector<int> v = nums, bit(n + 1);
		sort(v.begin(), v.end());
		unordered_map<int, int> m;
		for (int i = 0; i < n; ++i) m[v[i]] = i + 1;
		for (int i = n - 1; i >= 0; --i) {
			res += getSum(lower_bound(v.begin(), v.end(), nums[i] / 2.0) - v.begin(), bit);
			update(m[nums[i]], bit);
		}
		return res;
	}
	int getSum(int i, vector<int>& bit) {
		int sum = 0;
		while (i > 0) {
			sum += bit[i];
			i -= (i & -i);
		}
		return sum;
	}
	void update(int i, vector<int>& bit) {
		while (i < bit.size()) {
			bit[i] += 1;
			i += (i & -i);
		}
	}

	// my own solution, O(NlogN), TLE
	int reversePairs2(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		multiset<long long> m;
		m.insert(nums[0]);
		int res = 0;
		for (int j = 1; j < nums.size(); ++j) {
			auto it = m.upper_bound(2 * (long)nums[j]);
			res += distance(it, m.end());
			m.insert(nums[j]);
		}

		return res;
	}
};

//int main() {
//	Solution obj;
//	vector<int> nums{ 3, 1 };
//	cout << obj.reversePairs(nums) << endl;
//	cin.get();
//	return 0;
//}