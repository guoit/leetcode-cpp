/*
305 Number of Islands II

A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. 
Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?
*/
#include <vector>
#include <iostream>
#include "utilities.h"
using namespace std;
class Solution {
public:
	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
		vector<int> root(m*n, -1);	// union find's root array, prefer -1 because -1 can mark that pixel is water, otherwise root[i] is the root index (island index) of pixel i
		vector<pair<int, int>> dirs{ {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
		vector<int> res;
		int cnt = 0;
		for (auto& pos : positions) {
			// set this island's root
			int id = pos.first * n + pos.second;
			if (root[id] == -1) {
				++cnt;
				root[id] = id;
			}
			int p = find(root, id);

			// check neighboring pixels' root, if not -1, then we further check if they belong to the same island, if not union the root island
			for (auto& d : dirs) {
				int x = pos.first + d.first, y = pos.second + d.second;
				if (x > -1 && x < m && y > -1 && y < n) {
					int cur_id = x * n + y;
					if (-1 != root[cur_id]) {
						int q = find(root, cur_id);
						if (p != q) {
							root[q] = p;
							--cnt;
						}
					}
				}
			}

			res.push_back(cnt);
		}

		return res;
	}

	// modified union find, -1 means water, not root, so the result id must have root[id] == id
	// before using this function, it is necessary to check root[i] != -1
	int find(vector<int>& root, int i) {
		while (root[i] != i)	i = root[i];
		return i;
	}
};

//int main() {
//	Solution obj;
//
//	int m = 4, n = 4;
//	vector<pair<int, int>> positions{ {1,1},{2,0},{2,2},{3,1}, {2, 1} };	// expect [1, 2, 3, 4, 1]
//
//	cout << obj.numIslands2(m, n, positions) << endl;
//	cin.get();
//	return 0;
//}