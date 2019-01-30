/*
188 Best Time to Buy and Sell Stock IV

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example 1:

Input: [2,4,1], k = 2
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: [3,2,6,5,0,3], k = 2
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
			 Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		const int n = prices.size();
		if (n < 1) {
			return 0;
		}
		vector<vector<int>> dp(k+1, vector<int>(n, 0));	// dp[i][j] is the max profit up to ith transaction, on jth day

		for (int i = 1; i <= k; ++i) {
			int minCost = prices[0];
			for (int j = 1; j < n; ++j) {
				dp[i][j] = max(dp[i][j - 1], prices[j] - minCost);
				minCost = min(minCost, prices[j] - dp[i - 1][j - 1]);
			}
		}

		return dp[k][n-1];
	}
};

//int main() {
//	Solution obj;
//	vector<int> prices = { 3, 2, 6, 5, 0, 3 };
//	int k = 2;
//	cout<<obj.maxProfit(k, prices)<<"\n";
//	cin.get();
//	return 0;
//
//}