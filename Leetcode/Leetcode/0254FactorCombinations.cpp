/*
254 Factor Combinations

Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note:

Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
You may assume that n is always positive.
Factors should be greater than 1 and less than n.


Examples:
input: 1
output:

[]
input: 37
output:

[]
input: 12
output:

[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:

[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	vector<vector<int>> getFactors(int n) {
		return helper(2, n);
	}

	vector<vector<int>> helper(int start, int n) {
		vector<vector<int>> res;
		for (int a = start; a*a <= n; ++a) {
			if (n % a == 0) {
				res.push_back({ a, n / a });
				for (auto v : helper(a, n / a)) {
					v.insert(v.begin(), a);
					res.push_back(v);
				}
			}
		}

		return res;
	}
};

int main() {
	Solution obj;
	auto res = obj.getFactors(32);

	cin.get();
	return 0;
}