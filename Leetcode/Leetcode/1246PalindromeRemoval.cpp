/*
1246 Palindrome Removal

Given an integer array arr, in one move you can select a palindromic subarray arr[i], arr[i+1], ..., arr[j] where i <= j, and remove that subarray from the given array. Note that after removing a subarray, the elements on the left and on the right of that subarray move to fill the gap left by the removal.
Return the minimum number of moves needed to remove all numbers from the array.

Example 1:
Input: arr = [1,2]
Output: 2
Example 2:
Input: arr = [1,3,4,1,5]
Output: 3
Explanation: Remove [4] then remove [1,3,1] then remove [5].

Constraints:
1 <= arr.length <= 100
1 <= arr[i] <= 20
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	int minimumMoves(vector<int>& arr) {
		int n = arr.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = n - 1; i > -1; --i) {
			dp[i][i] = 1; // length 1 subarray, always 1
			for (int j = i + 1; j < n; ++j) {
				dp[i][j] = 1 + dp[i + 1][j]; // must initialize dp[i][j] to a value by removing arr[i], otherwise it will become 0
				for (int k = i + 1; k <= j; ++k) {
					// when we find a [k]==[i], we can remove both [i] and [k] without adding steps
					if (arr[i] == arr[k]) {
						dp[i][j] = min(dp[i][j], (k == i + 1 ? 1 : dp[i + 1][k - 1]) + (k==j ? 0 : dp[k + 1][j]));					
					}
				}
			}
		}
		return dp[0][n - 1];
	}
};

//int main() {
//	vector<int> test{16,13,13,10, 2};
//	Solution obj;
//	cout << obj.minimumMoves(test) <<" expect 4"<< endl;
//	cin.get();
//	return 0;
//}