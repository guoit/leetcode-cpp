/*
296 Best Meeting Point

A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. 
The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	// https://www.cnblogs.com/grandyang/p/5291058.html 
	int minTotalDistance(vector<vector<int>>& grid) {
		vector<int> rows, columns;
		for (auto& t : grid) {
			rows.push_back(t[0]);
			columns.push_back(t[1]);
		}

		return minDistance(rows) + minDistance(columns);
	}

	int minDistance(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int i = 0, j = nums.size() - 1;
		int res = 0;
		while (i < j)	res += nums[j--] - nums[i++];
		return res;
	}
};

int main()
{
	vector<vector<int>> g{ {0, 0}, {0,4}, {2,2} };
	Solution obj;
	cout << obj.minTotalDistance(g) << endl;
	cin.get();
	return 0;
}