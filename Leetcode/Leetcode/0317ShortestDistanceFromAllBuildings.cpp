/*
317 Shortest Distance from All Buildings

You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. 
You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
	// https://segmentfault.com/a/1190000004187914
	// easier to understand
	int shortestDistance(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty())	return 0;
		int m = grid.size(), n = grid[0].size();

		vector<vector<int>> dist(m, vector<int>(n, 0));	// added distance from all buildings
		vector<vector<int>> nums(m, vector<int>(n, 0));	// number of buildings reached

		int numBuilding = 0;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) {
					++numBuilding;
					bfs(grid, i, j, dist, nums);
				}
			}
		}

		int res = INT_MAX;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 0 && dist[i][j] != 0 && nums[i][j] == numBuilding)
					res = min(res, dist[i][j]);
			}
		}

		return res == INT_MAX ? -1 : res;
	}

	void bfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dist, vector<vector<int>>& nums) {

	}

	// https://www.cnblogs.com/grandyang/p/5297683.html
	int shortestDistance2(vector<vector<int>>& grid) {
		int res = INT_MAX, val = 0, m = grid.size(), n = grid[0].size();
		vector<vector<int>> sum = grid;
		vector<vector<int>> dirs{ {0,-1},{-1,0},{0,1},{1,0} };
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == 1) {
					res = INT_MAX;
					vector<vector<int>> dist = grid;
					queue<pair<int, int>> q;
					q.push({ i, j });
					while (!q.empty()) {
						int a = q.front().first, b = q.front().second; q.pop();
						for (int k = 0; k < dirs.size(); ++k) {
							int x = a + dirs[k][0], y = b + dirs[k][1];
							if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == val) {
								--grid[x][y];
								dist[x][y] = dist[a][b] + 1;
								sum[x][y] += dist[x][y] - 1;
								q.push({ x, y });
								res = min(res, sum[x][y]);
							}
						}
					}
					--val;
				}
			}
		}
		return res == INT_MAX ? -1 : res;
	}
};

int main() {
	vector<vector<int>> grid{ {1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0} };
	Solution obj;
	cout << obj.shortestDistance2(grid) << endl;
	cin.get();
	return 0;
}