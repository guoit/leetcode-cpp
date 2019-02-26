/*
340 Longest Substring with At Most K Distinct Characters	<not submitted>

Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>

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

	// brutal force solution O(N^3) to verify if above function is correct
	int verify(string s, int k) {
		int res = 0;
		for (int i = 0; i < s.size(); ++i) {
			for (int j = i; j < s.size(); ++j) {
				unordered_set<char> unique;
				for (int k = i; k <= j; ++k)
					unique.insert(s[k]);
				if (unique.size() == k)
					++res;
			}
		}
		return res;
	}

	// follow-up for k-length substring with exact k distinct characters
	// output the unique substrings list
	vector<string> substringKDistinct(string s, int k) {
		unordered_map<char, int> cnt;
		unordered_set<string> res;

		for (int i = 0; i < s.size(); ++i) {
			if (i >= k) {
				if (--cnt[s[i - k]] == 0)	cnt.erase(s[i - k]);
			}
			++cnt[s[i]];
			if (cnt.size() == k)	res.insert(s.substr(i - k + 1, k));
		}

		return vector<string>(res.begin(), res.end());
	}
};

//int main() {
//	//string s = "aabbccbbbcccdd";
//	string s = "abac";
//	Solution obj;
//	cout << obj.numberOfSubstringKDistinct(s, 2)<<endl;
//	cout << obj.verify(s, 2) << endl;
//	auto res = obj.substringKDistinct(s, 3);
//	cin.get();
//	return 0;
//}