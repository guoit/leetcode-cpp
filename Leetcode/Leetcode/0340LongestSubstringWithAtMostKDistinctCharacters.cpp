/*
340 Longest Substring with At Most K Distinct Characters	<not submitted>

Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	// same solution as 159, two pointers, O(N)
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		unordered_map<char, int> cnt;
		int res = 0;
		int left = 0;

		for (int i = 0; i < s.size(); ++i) {
			++cnt[s[i]];
			while (cnt.size() > k) {
				if (--cnt[s[left]] == 0)	cnt.erase(s[left]);
				++left;
			}

			res = max(res, i - left + 1);
		}

		return res;
	}

	// Amazon OA2, find the number of substrings with exact k distinct characters
	// We cannot use above solution because it omits substrings with smaller length but also have k distinct characters
	// We have to use O(N*N) to iterate all substrings, and for each substring, we use a hashmap to count characters
	int numberOfSubstringKDistinct(string s, int k) {
		unordered_map<char, int> cnt;
		int res = 0;

		for (int i = 0; i <= s.size() - k; ++i) {
			cnt.clear();
			int j = i;
			while (j < s.size() && cnt.size() <= k) {
				++cnt[s[j++]];
				if (cnt.size() == k)	++res;
			}
		}

		return res;
	}
};
