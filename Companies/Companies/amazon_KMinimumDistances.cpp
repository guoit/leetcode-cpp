/*
K Minimum Distances	-	Amazon OA2

You are in charge of preparing a recently purchased lot for one of Amazon's new building. 
The lot is covered with trenches and has a single obstacle that needs to be taken down before the foundation can be prepared for the building. 
The demolition robot must remove the obstacle before process can be made on the building.

Write an algorithm to determine the minimum distance required for the demolition robot to remove the obstacle.

Assumptions:
The lot is flat, except for trenches, and can be represented as a two-dimensional grid.
The demolition robot must start from the top-left corner of the lot, which is always flat, and can move one block up, down, left, or right at a time.
The demolition robot cannot enter trenches and cannot leave the lot.
The flat areas are represented as 1, areas with trenches are represented by 0 and the obstacle is represented by 9.

Input
The input to the function/method consists of three arguments:
numRows, an integer representing the number of rows;
numColumns, an integer representing the number of columns;
lot, representing the two-dimensional grid of integers.

Output
Return an integer representing the minimum distance traversed to remove the obstacle else return -1.

Constraints
1 <= numRows, numColumns <= 100

Example
Input:
numROws = 3
numColumns = 3
lot = [[1, 0, 0],
	   [1, 0, 0],
	   [1, 9, 1]]

Output:
3

Explanation:
Starting from the top-left corner, the demolition robot traversed the cells (0,0) -> (1,0) ->(2,0) ->(2,1). The robot traversed the total distance 3 to remove the obstacle. So, the output is 3.

Testcase 2:
Input:
5, 4,
[[1, 1, 1, 1],
 [0, 1, 1, 1],
 [0, 1, 0, 1],
 [1, 1, 9, 1],
 [0, 0, 1, 1]]

 Expected Return Value:
 5
*/
#include <queue>
#include <iostream>
using namespace std;

// BFS solution
int removeObstacle(int numRows, int numColumns, int **lot) {
	vector<pair<int, int>> dirs = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
	queue<pair<int, int>> q;
	int steps = 0;

	q.push({ 0, 0 });
	lot[0][0] = -1;	// -1 means visited

	while (!q.empty()) {
		int n = q.size();
		for (int i = 0; i < n; ++i) {
			auto cur = q.front();
			q.pop();
			for (auto d : dirs) {
				int x = cur.first + d.first;
				int y = cur.second + d.second;
				if (x > -1 && x < numRows && y > -1 && y < numColumns) {
					if (9 == lot[x][y])	return steps + 1;
					else if (1 == lot[x][y]) {
						q.push({ x, y });
						lot[x][y] = -1;
					}
				}
			}
		}
		++steps;
	}

	return -1;
}

//int main() {
//	int** p;
//	p = new int*[3];
//	for (int i = 0; i < 3; ++i) {
//		p[i] = new int[3]();
//	}
//	p[0][0] = 1;
//	p[0][1] = 0;
//	p[0][2] = 9;
//	p[1][0] = 1;
//	p[1][1] = 0;
//	p[1][2] = 1;
//	p[2][0] = 1;
//	p[2][1] = 1;
//	p[2][2] = 1;
//
//	cout << removeObstacle(3, 3, p) << endl;
//
//	for (int i = 0; i < 3; ++i) {
//		delete[] p[i];
//	}
//	delete[] p;
//
//	cin.get();
//	return 0;
//}