/*
265 Paint House II

There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2]is the cost of painting house 1 with color 2, and so on... 
Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	// http://www.cnblogs.com/grandyang/p/5322870.html
	// O(n*k) time, O(1) space solution
	int minCostII(vector<vector<int>>& costs) {
		if (costs.empty() || costs[0].empty()) return 0;

		int min1 = 0, min2 = 0, idx1 = -1;
		for (int i = 0; i < costs.size(); ++i) {
			int m1 = INT_MAX, m2 = m1, id1 = -1;
			for (int j = 0; j < costs[i].size(); ++j) {
				int cost = costs[i][j] + (j == idx1 ? min2 : min1);
				if (cost < m1) {
					m2 = m1; m1 = cost; id1 = j;
				}
				else if (cost < m2) {
					m2 = cost;
				}
			}
			min1 = m1; min2 = m2; idx1 = id1;
		}
		return min1;
	}
	// 2nd try, use 1-D DP array because 1st solution's dp[i][...] only replies on previous dp[i-1][...]
	// with[j] = costs[i][j] + without[j]
	// without[j] is the previous min cost with last house not painted by color j
	// also use two-pass to update "without" array in each i loop
	// time O(n*k), space O(k)
	int minCostII2(vector<vector<int>>& costs) {
		if (costs.empty() || costs[0].empty())	return 0;
		int n = costs.size(), k = costs[0].size();

		vector<int> without(k, 0);	// without[i] is the previous minimum total cost with the last house NOT painted with color i
		vector<int> with(k, 0);	// with[i] current total minimum cost with the last house painted with color i

		for (int i = 0; i < n; ++i) {
			int left_min = INT_MAX;
			for (int j = 0; j < k; ++j) {
				with[j] = costs[i][j] + without[j];

				// left to right pass to update minimum
				if (j > 0) {
					without[j] = min(left_min, with[j - 1]);
					left_min = without[j];
				}
			}

			// right to left pass to update minimum
			int right_min = INT_MAX;
			for (int j = k - 2; j > -1; --j) {
				without[j] = min(right_min, with[j + 1]);
				right_min = without[j];
			}
		}

		return *min_element(with.begin(), with.end());
	}

	// 1st try, use 2-D DP to save the result
	// dp[i][j] = costs[i][j] + min(dp[i-1][0 to k except j])
	// time O(n*k*k), space O(n*k)
	int minCostII3(vector<vector<int>>& costs) {
		if (costs.empty() || costs[0].empty())	return 0;
		int n = costs.size(), k = costs[0].size();
		
		vector<vector<int>> dp(n, vector<int>(k, 0));
		for (int j = 0; j < k; ++j)	dp[0][j] = costs[0][j];

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				int minCost = INT_MAX;
				for (int p = 1; p < k; ++p) {
					minCost = min(minCost, dp[i - 1][(j + p) % k]);
				}
				dp[i][j] = costs[i][j] + minCost;
			}
		}

		return *min_element(dp[n-1].begin(), dp[n-1].end());
	}
};

int main()
{
	vector<vector<int>> costs{ {10, 2, 3}, {10, 1, 9}, {5, 6, 7} };	//expect 9
	Solution obj;
	cout << obj.minCostII2(costs)<<endl;

	cin.get();
	return 0;
}