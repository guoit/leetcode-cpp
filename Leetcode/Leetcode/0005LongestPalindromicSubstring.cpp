/*
"""
5 Longest Palindromic Substring
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

"""
*/

#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		const int N = s.length();
		int start = 0, maxLen = 0;

		for (int i = 0; i < N; ++i) {
			// search odd-length palindrome
			search(s, i, i, start, maxLen);
			// search even-length palindrome
			search(s, i, i + 1, start, maxLen);
		}

		return s.substr(start, maxLen);
	}

	// search palindrome bi-directionly
	void search(string &s, int left, int right, int &start, int &maxLen) {
		const int n = s.length();
		while (left > -1 && right < n && s[left] == s[right]) {
			if (right - left + 1 > maxLen) {
				start = left;
				maxLen = right - left + 1;
			}				
			--left;
			++right;
		}
	}
};