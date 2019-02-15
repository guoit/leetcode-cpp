/*
Maximum Minimum Path	-	Amazon OA2

You are gonna climb mountains represented by a matrix. Each integer in the matrix represents the altitude at that point. You are supposed to climb from the top-left corner to the bottom-right corner
and only move rightward or downward in each step.
You can have many paths to do so. Each path has a minimum altitude. Find the maximum among all the minimum altitudes of all paths.
e.g.
[5, 4, 5]
[1, 3, 6]

Three paths: 5 1 3 6，5 4 3 6，5 4 5 6. Minimums are 1, 3, 4 respectively. Return the maximum in them which is 4.

another example:
[8, 4, 7]
[6, 5, 9]

3 paths：
8-4-7-9 min: 4
8-4-5-9 min: 4
8-6-5-9 min: 5
return: 5
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	// dp[i][j] = (m[i][j] > dp[i][j-1] && m[i][j] > dp[i-1][j]) ? max(dp[i][j-1], dp[i-1][j]) : matrix[i][j]
	// use 1-D array for dp
	int maxMinPath(vector<vector<int>> &matrix) {
		const int m = matrix.size();
		if (0 == m)	return 0;
		const int n = matrix[0].size();
		if (0 == n)	return 0;

		vector<int> dp(n, 0);
		dp[0] = matrix[0][0];

		for (int i = 1; i < n; ++i)	dp[i] = min(matrix[0][i], dp[i - 1]);
		for (int i = 1; i < m; ++i) {
			dp[0] = min(matrix[i][0], dp[0]);
			for (int j = 1; j < n; ++j) {
				dp[j] = (matrix[i][j] > dp[j-1] && matrix[i][j] > dp[j]) ? max(dp[j-1], dp[j]) : matrix[i][j];
			}				
		}

		return dp.back();
	}
};

//int main() {
//	vector<vector<int>> matrix = { {8, 4, 7}, {6, 5, 9} };	// expected 5
//	Solution obj;
//	cout << obj.maxMinPath(matrix) << endl;
//
//	cin.get();
//	return 0;
//}

