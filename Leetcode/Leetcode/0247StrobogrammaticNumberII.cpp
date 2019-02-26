/*
247 Strobogrammatic Number II

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].

Hint:

Try to use recursion and notice that it should recurse with n - 2 instead of n - 1.
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	// iterative solution, adding pairs (1, 1), (6, 9), (8, 8), (9,6)
	vector<string> findStrobogrammatic2(int n) {
		vector<string> one{ "0", "1", "8" }, zero{ "" };
		vector<string> res = (n % 2 == 1) ? one : zero;
		for (int i = (n%2) + 2; i <= n; i+= 2) {
			vector<string> t;
			for (auto a : res) {
				if (i != n)	t.push_back("0" + a + "0");
				t.push_back("1" + a + "1");
				t.push_back("6" + a + "9");
				t.push_back("8" + a + "8");
				t.push_back("9" + a + "6");
			}
			res = t;
		}

		return res;
	}

	// recursive solution, from outer to inner
	vector<string> findStrobogrammatic(int n) {
		vector<string> res;
		if (n < 1)	return {};
		vector<pair<char, char>> stro{ {'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'} };
		string s(n, '\0');
		find(s, 0, n - 1, stro, res);

		return res;
	}

	void find(string &s, int i, int j, vector<pair<char, char>> &stro, vector<string> &res) {
		if (i > j) {
			res.push_back(s);
			return;
		}
		else if (i == j) {
			for (int k = 0; k < 3; ++k) {
				s[i] = stro[k].first;
				res.push_back(s);
			}
			return;
		}

		for (int k = (i == 0 ? 1 : 0); k < 5; ++k) {
			s[i] = stro[k].first;
			s[j] = stro[k].second;
			find(s, i + 1, j - 1, stro, res);
		}
	}
};


int main() {
	Solution obj;
	auto res = obj.findStrobogrammatic2(3);
	cin.get();
	return 0;
}