/*
224 Basic Calculator

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
#include <string>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
	// stack solution
	int calculate(string s) {
		int n = s.size();
		stack<long> st;
		long value = 0;	// value within (...)
		int sign = 1;	// sign within (...)
		for (int i = 0; i < n; ++i) {
			if (s[i] == '+')
				sign = 1;
			else if (s[i] == '-')
				sign = -1;
			else if ((s[i] >= '0') && (s[i] <= '9')) {
				long num = 0;
				while ((i < n) && (s[i] >= '0') && (s[i] <= '9')) {
					num = num * 10 + s[i++] - '0';
				}
				value += sign * num;
				--i;
			}
			else if (s[i] == '(') {
				st.push(value);	// value before +/-(...)
				st.push(sign);	// sign before (...)
				value = 0;	// reset value to 0 for evaluation inside (...)
				sign = 1;	// reset sign to '+' for evaluation inside (...)
			}
			else if (s[i] == ')') {
				value *= st.top();	// apply the sign before (...)
				st.pop();
				value += st.top();	// add the value before +/-(...)
				st.pop();
			}
		}

		return value;
	}
};

//int main() {
//	Solution obj;
//	//string s = "1+ (2 + (3 + (4+5)))";
//	//string s = "-1";
//	string s = "100-(-(2-34)+6 -(9))";
//	//string s = "";
//	cout << obj.calculate(s) << " expect 71" << endl;
//
//	cin.get();
//	return 0;
//}