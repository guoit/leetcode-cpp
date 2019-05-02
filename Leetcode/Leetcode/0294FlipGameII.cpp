/*
294 Flip Game II

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

Example:

Input: s = "++++"
Output: true
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
Follow up:
Derive your algorithm's runtime complexity.
*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	bool canWin(string s) {
		for (int i = 0; i < s.size() - 1; ++i) {
			if (s[i] == '+' && s[i + 1] == '+') {
				if (!canWin(s.substr(0, i) + "--" + s.substr(i + 2, s.size() - i - 2)))
					return true;
			}
		}
		return false;
	}
};

int main()
{
	string s = "+++++";
	Solution obj;
	cout << obj.canWin(s) << endl;
	cin.get();
	return 0;
}