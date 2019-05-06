/*
302 Smallest Rectangle Enclosing Black Pixels

An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. 
Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:
[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,

Return 6.
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int minArea(vector<vector<char>>& image, int x, int y) {
		const int m = image.size();
		const int n = image[0].size();
	}
	int binarysearch(vector<vector<char>>& image, int low, int high, bool isRow, bool small) {
		while (low < high) {
			int mid = (low + high) / 2;

		}
	}
};