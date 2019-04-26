/*
286 Walls and Gates

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include "utilities.h"

using namespace std;
class Solution {
public:
#define INF 2147483647
	void wallsAndGates(vector<vector<int>>& rooms) {
		if (rooms.empty() || rooms[0].empty())	return;		
		const int m = rooms.size(), n = rooms[0].size();
		vector<pair<int, int>> dirs{ {0, -1}, {-1, 0}, {0, 1}, {1,0} };
		unordered_set<pair<int, int>> visited;
		queue<pair<int, int>> q;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (rooms[i][j] == 0)	q.push({ i, j });
				visited.insert({ i, j });
			}
		}

		int dist = 0;

		while (!q.empty()) {
			int size = q.size();
			for (int k = 0; k < size; ++k) {
				int x = q.front().first, y = q.front().second; q.pop();
				rooms[x][y] = min(rooms[x][y], dist);
				for (auto& t : dirs) {
					int i = x + t.first, j = y + t.second;
					if (i > -1 && i < m && j > -1 && j < n && rooms[i][j] != -1 && !visited.count({ i, j })) {
						q.push({ i, j });
						visited.insert({ i, j });
					}	
				}
			}
			++dist;
		}
	}
};

