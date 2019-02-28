/*
249 Group Shifted Strings

Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

Note: For the return value, each inner list's elements must follow the lexicographic order.
*/
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	// for each character, calculate the distance from previous character, then use the difference to form a string with digits, which serves as a key
	// for each group, we use multiset to save the strings because it allows duplicates and it can also sort the strings in the group
	vector<vector<string>> groupStrings(vector<string>& strings) {
		unordered_map<string, multiset<string>> m;
		for (auto s : strings) {
			string key = diff(s);
			m[key].insert(s);
		}

		vector<vector<string>> res;
		for (const auto& item : m) {
			res.push_back(vector<string>(item.second.begin(), item.second.end()));
		}

		return res;
	}

	string diff(string &s) {
		string res;
		for (int i = 1; i < s.size(); ++i) {
			res.push_back((s[i] - s[i - 1] + 26) % 26 + '0');
			res.push_back(',');	// trap here: don't forget to add comma to separate them
		}

		return res;
	}
};

//int main() {
//	vector<string> words{ "abc", "bcd", "acef", "xyz", "az", "ba", "a", "z" };
//	Solution obj;
//	auto res = obj.groupStrings(words);
//	cin.get();
//	return 0;
//}