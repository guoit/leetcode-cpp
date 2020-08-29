/*
85 Maximal Rectangle

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
	// use 84 largest rectangle in histogram
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m < 1) return 0;
		int n = matrix[0].size();
		vector<int> hist(n, 0);
		int res = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '0') {
					hist[j] = 0;
				}
				else {
					hist[j] += 1;
				}
			}
			res = max(res, largestRectangleArea(hist));
		}
		return res;
	}

	// use h_max matrix, see onenote
	int maximalRectangle2(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m < 1) return 0;
		int n = matrix[0].size();
		vector<vector<int>> h_max(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			h_max[i][0] = matrix[i][0] - '0';
			for (int j = 1; j < n; ++j) {
				if (matrix[i][j]=='1') {
					h_max[i][j] = 1 + h_max[i][j - 1];
				}
				else {
					h_max[i][j] = 0;
				}
			}
		}

		int res = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				res = max(res, h_max[i][j]);
				int k = i - 1, minH = h_max[i][j];
				while (k > -1 && h_max[k][j] != 0) {
					minH = min(minH, h_max[k][j]);
					res = max(res, minH*(i - k + 1));
					--k;
				}
			}
		}

		return res;
	}

private:
	int largestRectangleArea(vector<int>& hist) {
		hist.push_back(0);
		stack<int> s;
		int res = 0;
		for (int i = 0; i < hist.size(); ++i) {
			while (!s.empty() && hist[s.top()] >= hist[i]) {
				int h = hist[s.top()]; s.pop();
				int left = s.empty() ? -1 : s.top();
				res = max(res, h*(i - left - 1));
			}
			s.push(i);
		}
		hist.pop_back();
		return res;
	}
};

//int main() {
//	vector<vector<char>> matrix{{'0', '0', '0'}, {'0', '0', '0'}, {'1', '1', '1'}};
//	Solution obj;
//	cout << obj.maximalRectangle(matrix) << endl;
//	cout << obj.maximalRectangle2(matrix) << endl;
//	cin.get();
//	return 0;
//}