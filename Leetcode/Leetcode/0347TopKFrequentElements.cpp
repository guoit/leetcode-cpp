/*
347 Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:
Input: nums = [1], k = 1
Output: [1]
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> count;
		for (int num : nums) {
			++count[num];
		}
		vector<int> ans;
		for (auto it = count.begin(); it != count.end(); ++it) {
			ans.push_back(it->first);
		}
		auto pos = prev(ans.end(), k);
		nth_element(ans.begin(), pos, ans.end(), [&](int n1, int n2) {
			return count[n1] < count[n2];
		});
		vector<int> res(pos, ans.end());

		return res;
	}
};