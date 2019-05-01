/*
291 Word Pattern II

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Example 1:

Input: pattern = "abab", str = "redblueredblue"
Output: true
Example 2:

Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
Output: true
Example 3:

Input: pattern = "aabb", str = "xyzabcxzyabc"
Output: false
Notes:
You may assume both pattern and str contains only lowercase letters.
*/
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
	bool wordPatternMatch(string pattern, string str) {
		unordered_map<char, string> map;
		return helper(pattern, 0, str, 0, map);
	}

	bool helper(string& pattern, int i, string& str, int j, unordered_map<char, string>& map) {
		if (i == pattern.size() && j == str.size())	return true;
		else if (i >= pattern.size() || j >= str.size())	return false;

		char p = pattern[i];
		if (map.count(p)) {
			string s = map[p];
			if (s == str.substr(j, s.size()))
				return helper(pattern, i + 1, str, j + s.size(), map);
			else
				return false;
		}
		else {
			for (int k = j + 1; k <= str.size(); ++k) {
				map[p] = str.substr(j, k-j);
				if (helper(pattern, i + 1, str, k, map))	return true;
				map.erase(p);
			}
			return false;
		}
	}
};

//int main()
//{
//	//string pattern = "abab";
//	//string str = "redblueredblue";
//	//string pattern = "aabb";
//	//string str = "xyzabcxzyabc";
//	string pattern = "aaaa";
//	string str = "asdasdasdasd";
//	Solution obj;
//	cout << obj.wordPatternMatch(pattern, str) << endl;
//	cin.get();
//	return 0;
//}