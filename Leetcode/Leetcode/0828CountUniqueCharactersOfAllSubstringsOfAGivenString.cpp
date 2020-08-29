/*
828 Count Unique Characters of All Substrings of a Given String

Let's define a function countUniqueChars(s) that returns the number of unique characters on s, for example if s = "LEETCODE" then "L", "T","C","O","D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.

On this problem given a string s we need to return the sum of countUniqueChars(t) where t is a substring of s. Notice that some substrings can be repeated so on this case you have to count the repeated ones too.
Since the answer can be very large, return the answer modulo 10 ^ 9 + 7.

Example 1:
Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Evey substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
Example 2:
Input: s = "ABA"
Output: 8
Explanation: The same as example 1, except countUniqueChars("ABA") = 1.
Example 3:
Input: s = "LEETCODE"
Output: 92

Constraints:
0 <= s.length <= 10^4
s contain upper-case English letters only.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	// Change perspective to: for each letter s[i], we count how many substr that contains only this letter.
	// For s[i], we need to know its last position x, and its next position y, then the number of substr will be (i-x)*(y-i).
	// Here we save s[i]'s last two positions to idx[i][0] and idx[i][1], then we get (i - idx[c][1])*(idx[c][1] - idx[c][0]) with i the "right" position
	// At last, we will add the numbers by assuming s[n] is s[i].
	int uniqueLetterString(string s) {
		int res = 0, n = s.size(), M = 1e9 + 7;
		// i = current char - 'A'
		// idx[i][0] is the char's last second appearance index, idx[i][1] is the char's last appearance index
		vector<vector<int>> idx(26, vector<int>(2, -1));
		for (int i = 0; i < n; ++i) {
			int c = s[i] - 'A';
			res = (res + (i - idx[c][1])*(idx[c][1] - idx[c][0]) % M) % M;
			idx[c][0] = idx[c][1];
			idx[c][1] = i;
		}

		for (int c = 0; c < 26; ++c) {
			res = (res + (n - idx[c][1])*(idx[c][1] - idx[c][0]) % M) % M;
		}

		return res;
	}
};

//int main() {
//	string s = "ABA";
//	Solution obj;
//	cout << obj.uniqueLetterString(s) << " expect 8" << endl;
//	cin.get();
//	return 0;
//}