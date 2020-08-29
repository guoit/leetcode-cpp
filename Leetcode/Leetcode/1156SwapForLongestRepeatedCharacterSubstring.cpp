/*
1156 Swap For Longest Repeated Character Substring

Given a string text, we are allowed to swap two of the characters in the string. Find the length of the longest substring with repeated characters.

Example 1:
Input: text = "ababa"
Output: 3
Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa", which its length is 3.
Example 2:
Input: text = "aaabaaa"
Output: 6
Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa", which its length is 6.
Example 3:
Input: text = "aaabbaaa"
Output: 4
Example 4:
Input: text = "aaaaa"
Output: 5
Explanation: No need to swap, longest repeated character substring is "aaaaa", length is 5.
Example 5:
Input: text = "abcdef"
Output: 1

Constraints:
1 <= text.length <= 20000
text consist of lowercase English characters only.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	// https://zxi.mytechroad.com/blog/hashtable/leetcode-1156-swap-for-longest-repeated-character-substring/
	int maxRepOpt1(string text) {
		int n = text.size();
		if (n < 2) return n;
		// left[i] is the length of longest same characters ending with text[i]
		// right[i] is the length of longest same characters starting with text[i]
		// counts[i] represents the total count of letter with index (text[i] - 'a')
		vector<int> left(n, 1), right(n, 1), counts(26, 0);
		
		counts[text[0] - 'a']++;
		int cnt = 1;
		for (int i = 1; i < n; ++i) {
			if (text[i] == text[i - 1]) cnt++;
			else cnt = 1;
			left[i] = cnt;
			counts[text[i] - 'a']++;

		}
		
		cnt = 1;
		for (int i = n - 2; i > -1; --i) {
			if (text[i] == text[i + 1]) cnt++;
			else cnt = 1;
			right[i] = cnt;
		}

		int ans = 0;
		for (int i = 1; i < n - 1; ++i) {
			cnt = 0;
			char cl = text[i - 1], cr = text[i + 1];
			if (cl != cr) {
				// left char is not the same as right char, so we take the max of left continuous length and right continuous length
				// if total count of left char or right are larger than the local counts, this means there is extra left char or right char, so the count can increment 1.
				cnt = max(
					left[i - 1] + (counts[cl - 'a'] > left[i - 1] ? 1 : 0),
					right[i + 1] + (counts[cr - 'a'] > right[i + 1] ? 1 : 0)
				);
			}
			else {
				// left char is the same as right char, so we add them together (imagine swapping text[i] with the last continuous char as same as cr)
				// if total counts of cl is larger than the local count, this means there is extra cl/cr somewhere, and we can swap it with text[i]
				// what if text[i] == cl == cr? This is also handled by the above analysis, we swap text[i] with itself (actually this is not-swapping case)
				cnt = left[i - 1] + right[i + 1];
				if (counts[cl - 'a'] > cnt) ++cnt;
			}
			ans = max(ans, cnt);
		}

		return ans;
	}
};

//int main() {
//	string s = "abcd";
//	Solution obj;
//	cout << obj.maxRepOpt1(s) << " expect 1" << endl;
//	cin.get();
//	return 0;
//}