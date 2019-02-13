/*
159 Longest Substring with At Most Two Distinct Characters

Given a string S, find the length of the longest substring T that contains at most two distinct characters.
For example,
Given S = “eceba”,
T is “ece” which its length is 3.

similar problems: 340 Longest Substring with At Most K Distinct Characters, 395 Longest Substring with At Least K Repeating Characters
*/
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	// http://www.cnblogs.com/grandyang/p/5185561.html
	// hashmap to count characters
	// two pointers
	int lengthOfLongestSubstringTwoDistinct(string s) {
		unordered_map<char, int> cnt;
		int res = 0;
		int left = 0;

		for (int i = 0; i < s.size(); ++i) {
			++cnt[s[i]];
			while (cnt.size() > 2) {
				if (--cnt[s[left]] == 0)	cnt.erase(s[left]);
				++left;
			}

			res = max(res, i - left + 1);
		}

		return res;
	}
};