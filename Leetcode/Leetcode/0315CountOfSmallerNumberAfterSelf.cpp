/*
315. Count of Smaller Numbers After Self

You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
Example:
Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/
#include <vector>
#include <set>
#include "utilities.h"
using namespace std;
class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		multiset<int> m;
		vector<int> count(nums.size(), 0);
		for (int i = nums.size() - 1; i > -1; --i) {
			auto it = m.lower_bound(nums[i]);
			count[i] = distance(m.begin(), it);
			m.insert(nums[i]);
		}

		return count;
	}
};

//int main() {
//	Solution obj;
//	vector<int> nums{5,2,6,1};
//	cout << obj.countSmaller(nums) << endl;
//	cin.get();
//	return 0;
//}