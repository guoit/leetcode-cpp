/*
267 Palindrome Permutation II

Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].

Hint:

If a palindromic permutation exists, we just need to generate the first half of the string.
To generate all distinct permutations of a (half of) string, use a similar approach from: Permutations II or Next Permutation.
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	// 1. count characters, and check if palindromic permutations exist (266's method)
	// 2. generate the first half of permutation string, use lc 47 Permutations II's method to avoid duplicated result
	vector<string> generatePalindromes(string s) {
		// count the number of characters
		unordered_map<char, int> count;
		for (const char& c : s)	count[c]++;

		// check odd number of characters and extract the middle character of palindromic strings
		string t = "", mid = "";
		for (auto& e : count) {
			if (e.second & 1) mid += e.first;			
			e.second /= 2;
			t += string(e.second, e.first);
		}

		// make sure there are at most 1 odd number character
		if (mid.size() > 1)	return {};

		// call permutate method and update result
		vector<string> res;
		permutate(t, count, mid, "", res);

		return res;
	}

	void permutate(const string& t, unordered_map<char, int>& m, const string& mid, string build, vector<string>& res) {
		if (build.size() == t.size()) {
			res.push_back(build + mid + string(build.rbegin(), build.rend()));
			return;
		}

		for (auto& it : m) {
			if (it.second == 0)	continue;
			--it.second;
			permutate(t, m, mid, build + it.first, res);
			++it.second;
		}
	}

	// another solution using algorithm's next_permutation function, which rearranges elements into next greater permutation
	vector<string> generatePalindromes2(string s) {
		// count the number of characters
		unordered_map<char, int> count;
		for (const char& c : s)	count[c]++;

		// check odd number of characters and extract the middle character of palindromic strings
		string t = "", mid = "";
		for (auto& e : count) {
			if (e.second & 1) mid += e.first;
			e.second /= 2;
			t += string(e.second, e.first);
		}

		// make sure there are at most 1 odd number character
		if (mid.size() > 1)	return {};

		// use next_permutation method to generate unique palindromic strings
		sort(t.begin(), t.end());
		vector<string> res;
		do {
			res.push_back(t + mid + string(t.rbegin(), t.rend()));
		} while (next_permutation(t.begin(), t.end()));

		return res;
	}
};

//int main() {
//	Solution obj;
//	auto res = obj.generatePalindromes2("aaa");
//	cin.get();
//	return 0;
//}