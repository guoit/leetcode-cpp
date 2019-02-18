/*
490 The Maze

There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. 
The start and destination coordinates are represented by row and column indexes.

Example 1
Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)

Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

Example 2
Input 1: a maze represented by a 2D array

0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0

Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)

Output: false
Explanation: There is no way for the ball to stop at the destination.

Note:

There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
	// http://www.cnblogs.com/grandyang/p/6381458.html
	// difference from above solution: I used dp[i][j] == -1 to mark [i][j] has been visited, in this way, we don't need to modify original matrix maze
	bool hasPath_DFS(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		if (maze.empty() || maze[0].empty())	return true;
		const int m = maze.size(), n = maze[0].size();

		vector<vector<int>> dp(m, vector<int>(n, -1));
		return helper(maze, dp, start[0], start[1], destination[0], destination[1]);
	}

	bool helper(vector<vector<int>>& maze, vector<vector<int>>& dp, int i, int j, int di, int dj) {		
		if (i == di && j == dj)	return true;
		if (dp[i][j] != -1)	return dp[i][j];
		bool res = false;
		int m = maze.size(), n = maze[0].size();
		maze[i][j] = -1;	// mark [i][j] visited, we cannot use dp[i][j] because we don't know its value yet

		for (auto &d : dirs) {
			int x = i, y = j;
			while (x > -1 && x < m && y > -1 && y < n && maze[x][y] != 1) {
				x += d.first;
				y += d.second;
			}
			x -= d.first;
			y -= d.second;
			// analysis of below code: if maze[x][y] == -1 (visited), and dp[x][y] == true, should we call helper for x, y?
			// answer is no. Because if x, y already visited and dp[x][y] == true, previous dfs which reaches x, y must have returned true, so there is no need to continue calling helper anymore
			if (maze[x][y] != -1)	res |= helper(maze, dp, x, y, di, dj);
		}

		dp[i][j] = res;
		return res;
	}

	bool hasPath_BFS(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		if (maze.empty() || maze[0].empty())	return true;
		const int m = maze.size(), n = maze[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));	// we cannot mark maze as -1 as visited because this will affect further scrolling (further scrolling doesn't know if the cell was a wall or empty)

		queue<pair<int, int>> q;
		q.push({ start[0], start[1] });
		visited[start[0]][start[1]] = true;

		while (!q.empty()) {
			auto t = q.front();
			q.pop();
			if (t.first == destination[0] && t.second == destination[1])	return true;
			for (auto & d : dirs) {
				int x = t.first, y = t.second;
				while (x > -1 && x < m && y > -1 && y < n && maze[x][y] == 0) {
					x += d.first;
					y += d.second;
				}
				x -= d.first;
				y -= d.second;
				if (!visited[x][y]){
					visited[x][y] = true;
					q.push({ x, y });
				}
			}
		}

		return false;
	}

private:
	vector<pair<int, int>> dirs{ {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
};

int main() {

	vector<vector<int>> maze{ {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 1, 1}, {0, 0, 0, 0, 0} };
	Solution obj;
	vector<int> start{ 0, 4 };
	vector<int> dest{ 3, 2 };
	cout << obj.hasPath_DFS(maze, start, dest) << endl;

	cin.get();
	return 0;
}