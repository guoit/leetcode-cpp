/*
1209 Remove All Adjacent Duplicates in String II

Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made.

It is guaranteed that the answer is unique.

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation:
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"

Constraints:
1 <= s.length <= 10^5
2 <= k <= 10^4
s only contains lower case English letters.
*/
#include <stack>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	string removeDuplicates(string s, int k) {
		stack<int> count;
		for (int i = 0; i < s.size(); ++i) {
			if (i == 0 || s[i] != s[i - 1]) { // must have i == 0 check because i could become 0 later
				count.push(1);
			}
			else if (++count.top() == k) {
					count.pop();
					s.erase(i - k + 1, k);
					i -= k;
			}			
		}
		return s;
	}
};

int main() {
	Solution obj;
	cout << obj.removeDuplicates("deeedbbcccbdaa", 3) << endl;

	cin.get();
	return 0;
}