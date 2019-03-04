/*
256 Paint House

There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. 
The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. 
For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... 
Find the minimum cost to paint all houses.

Note:
All costs are positive integers.
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	// create three dp arrays
	// r[i] is the min cost from 0 to i when house i is painted with red
	// b[i] is the min cost from 0 to i when house i is painted with blue
	// g[i] is the min cost from 0 to i when house i is painted with green
	int minCost(vector<vector<int>>& costs) {
		int n = costs.size();
		if (n < 1)	return 0;
		vector<int> r(n, 0), b(n, 0), g(n, 0);
		r[0] = costs[0][0];
		b[0] = costs[0][1];
		g[0] = costs[0][2];
		for (int i = 1; i < n; ++i) {
			r[i] = costs[i][0] + min(b[i - 1], g[i - 1]);
			b[i] = costs[i][1] + min(r[i - 1], g[i - 1]);
			g[i] = costs[i][2] + min(r[i - 1], b[i - 1]);
		}

		return min(r.back(), min(b.back(), g.back()));
	}

	// optimize space complexity to O(1)
	int minCost2(vector<vector<int>>& costs) {
		if (costs.empty() || costs[0].empty())	return 0;
		int r0 = costs[0][0], b0 = costs[0][1], g0 = costs[0][2];
		int r = 0, b = 0, g = 0;
		for (int i = 1; i < costs.size(); ++i) {
			r = costs[i][0] + min(b0, g0);
			b = costs[i][1] + min(r0, g0);
			g = costs[i][2] + min(r0, b0);

			r0 = r;
			b0 = b;
			g0 = g;
		}

		return min(r0, min(b0, g0));
	}

	// follow up: extend to K colors
	// use the trick (j + 1)%K where j from (this color) to (this color +K-1) to get all different colors except this color
};