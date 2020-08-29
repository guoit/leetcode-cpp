/*
1239. Maximum Length of a Concatenated String with Unique Characters

Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.
Return the maximum possible length of s.

Example 1:
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
Example 2:
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".
Example 3:
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26

Constraints:
1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters.

Understand the problem correctly:
(1) each string in arr may contain duplicate characters
(2) the eventually concatenated string must not contain duplicate characters
*/
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	int maxLength(vector<string>& arr) {
		// generate a vector of bit masks for each string in arr
		vector<int> a;
		for (const string& x : arr) {
			int mask = 0;
			for (char c : x) { mask |= (1 << (c - 'a')); }
			if (__builtin_popcount(mask) != x.size()) continue;
			a.push_back(mask);
		}

		int ans = 0;

		function<void(int, int)> dfs = [&](int s, int mask) {
			ans = max(ans, (int)__builtin_popcount(mask));
			for (int i = s; i < a.size(); ++i) {
				if ((mask & a[i]) == 0) dfs(i + 1, mask | a[i]);
			}
		};

		dfs(0, 0);
		return ans;
	}
};

//int main() {
//	Solution obj;
//	vector<string> arr{ "zog","nvwsuikgndmfexxgjtkb","nxko" };
//	cout << obj.maxLength(arr) << endl;
//	cin.get();
//	return 0;
//}