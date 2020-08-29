/*
980 Unique Paths III

On a 2-dimensional grid, there are 4 types of squares:
1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Example 1:
Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:
Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths:
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:
Input: [[0,1],[2,0]]
Output: 0
Explanation:
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.

Note:
1 <= grid.length * grid[0].length <= 20
*/
#include <vector>
#include <functional>
#include <iostream>
using namespace std;
class Solution {
public:
	// DFS solution, DP is too time consuming and too space consuming
	// https://zxi.mytechroad.com/blog/searching/leetcode-980-unique-paths-iii/
	int uniquePathsIII(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		int sx = -1, sy = -1; // start position
		int req = 1; // remaining empty positions, including start position
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 0) req++;
				else if (grid[i][j] == 1) { sx = i; sy = j; }
			}
		}

		function<int(int, int, int)> dfs = [&](int i, int j, int k)->int{
			// i, j: index of current position
			// k: remaining empty spaces
			// return number of steps

			// check boundaries of input parameters
			if (i < 0 || i >= m || j < 0 || j >= n || k < 0) return 0;
			// if current position is an obstacle, return 0
			if (grid[i][j] == -1) return 0;
			// if current position is the end, return 1
			if (grid[i][j] == 2) return k == 0;
			// if current position is empty space or start, continue searching
			grid[i][j] = -1; // mark visited or obstacle
			int paths =
				dfs(i, j - 1, k - 1) +
				dfs(i - 1, j, k - 1) +
				dfs(i, j + 1, k - 1) +
				dfs(i + 1, j, k - 1);
			grid[i][j] = 0; // recover the original position
			return paths;
		};

		return dfs(sx, sy, req);
	}
};

//int main() {
//	//vector<vector<int>> grid{ {1,0,0,0},{0,0,0,0},{0,0,2,-1} };
//	vector<vector<int>> grid{ {1, 0}, {2, 0} };
//	Solution obj;
//	cout << obj.uniquePathsIII(grid) << endl;
//	cin.get();
//	return 0;
//}