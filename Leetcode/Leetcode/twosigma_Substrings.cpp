/*
Substrings

Consider a string, s = "abc". An alphabetically-ordered sequence of substrings of s wouldbe {"a", "ab", "abc", "b", "bc", "c"}.
If we reduce this sequence to only those substrings thatstart with a vowel and end with a consonant, we're left with {"ab", "abc"}.
The alphabetically first element in this reduced list is "ab", and the alphabetically last elementis "abc".
As a reminder:
Vowels: a, e, i, o, and u.
Consonants: b, c, d, f, g, h, j, k, l, m, n, p, q, r, s, t, v, w, x, y, and z.

Complete the findSubstrings function in your editor. It has 1 parameter: a string, s,consisting of lowercase English letters (a − z).
The function must find the substrings of sthat start with a vowel and end with a consonant, then print the alphabetically first andalphabetically last of these substrings.

Constraints
3 ≤ length of s ≤ 5 × 10^5

Output FormatYour function must print two lines of output denoting the alphabetically first and lastsubstrings of s that start with a vowel and end with a consonant.
Print the alphabeticallyfirst qualifying substring on the first line, and the alphabetically last qualifying substringon the second line.

Example 1:
Input: "aba"
Output: "ab", "ab"

Example 2:
Input: "aab"
Output: "aab", "ab"
*/
#include <vector>
#include <string>
#include <map>
#include <set>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<string> findSubstrings(string s) {
		map<char, vector<int>> vowels;
		set<int> consonants;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
				vowels[s[i]].push_back(i);
			else
				consonants.insert(i);
		}

		if (vowels.empty() || consonants.empty())	return {"", ""};	// corner case: there is no vowel or no consonant in s

		// find the alphabetically max substring starting with vowel and ending with consonant
		string maxSubstr = "";
		auto big_vowel_it = vowels.rbegin();
		auto &big_vowel_pos = big_vowel_it->second;
		int last_consonant_pos = *consonants.rbegin();
		for (int start : big_vowel_pos) {
			string sub = s.substr(start, last_consonant_pos - start + 1);
			if (sub.compare(maxSubstr) > 0)	maxSubstr = sub;
		}

		// find the alphabetically min substring starting with vowel and ending with consonant
		string minSubstr = "";
		auto small_vowel_it = vowels.begin();
		auto &small_vowel_pos = small_vowel_it->second;
		for (int start : small_vowel_pos) {
			auto it_consonant = consonants.lower_bound(start);
			if (it_consonant != consonants.end()) {
				int first_consonant_pos = *it_consonant;
				string sub = s.substr(start, first_consonant_pos - start + 1);
				if (minSubstr.empty() || sub.compare(minSubstr) < 0)	minSubstr = sub;
			}
		}

		return { minSubstr, maxSubstr };
	}
};

int main()
{
	string s = "aab";
	Solution obj;
	auto res = obj.findSubstrings(s);
	cin.get();
	return 0;
}