/*
227 Basic Calculator II

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
#include <string>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
	int calculate(string s) {
		char pre_op = '+';
		s += '+';
		long num = 0;
		vector<long> stack;
		int n = s.size();

		for (int i = 0; i < n; ++i) {
			char c = s[i];
			if (c >= '0') {	// found a digit, we parse the whole number
				num = 0;
				while ((i < n) && (s[i] >= '0')) {
					num = num * 10 + s[i++] - '0';
				}
				--i;
			}
			else if (c == ' ')	// white space, just ignore
				continue;
			else {	// must be an operator, process the previously parsed number based on previous operator
				switch (pre_op) {
				case '+':
					stack.push_back(num);
					break;
				case '-':
					stack.push_back(-num);
					break;
				case '*':
					stack.back() *= num;
					break;
				case '/':
					stack.back() /= num;
				}
				
				pre_op = c;	// update previous operator
			}
		}

		return accumulate(stack.begin(), stack.end(), 0);
	}
};