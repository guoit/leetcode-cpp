/*
246 Strobogrammatic Number

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:

Input:  "69"
Output: true
Example 2:

Input:  "88"
Output: true
Example 3:

Input:  "962"
Output: false
*/
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	bool isStrobogrammatic(string num) {
		int stro[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
		int i = 0, j = num.size() - 1;
		while (i <= j) {
			if (stro[num[i++] - '0'] != num[j--] - '0')
				return false;
		}

		return true;
	}
};

//int main() {
//	string words[] = {"", "1", "69", "2", "88", "962"};
//	Solution obj;
//	for (auto word : words) {
//		cout << word << " -> " << obj.isStrobogrammatic(word) << endl;
//	}
//	cin.get();
//	return 0;
//}