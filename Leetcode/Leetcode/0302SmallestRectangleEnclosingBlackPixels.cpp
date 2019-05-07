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
		int left = binarysearch(image, 0, y, false, true);
		int right = binarysearch(image, y, n - 1, false, false);
		int up = binarysearch(image, 0, x, true, true);
		int down = binarysearch(image, x, m - 1, true, false);
		cout << left << right << up << down << endl;
		return (right - left + 1)*(down - up + 1);
	}


	int binarysearch(vector<vector<char>>& image, int low, int high, bool isRow, bool small) {
		// "small" means if the search range is in smaller portion (index close to 0)
		// for example, when search the "above" portion, small is true, when search the "below" portion, small is false
		while (low < high) {
			int mid = (low + high) / 2;

			// search if the row or column has '1'
			bool hasBlack = false;
			if (isRow) {
				for (int j = 0; j < image[0].size(); ++j) {
					if (image[mid][j] == '1') {
						hasBlack = true;
						break;
					}
				}
			}
			else {
				for (int i = 0; i < image.size(); ++i) {
					if (image[i][mid] == '1') {
						hasBlack = true;
						break;
					}
				}
			}

			if (hasBlack != small)	low = mid + 1;
			else high = mid;
		}

		return high;
	}
};

int main() {

	vector<vector<char>> image{ {'0','0','1','0'},  {'0','1','1','0'},  {'0','1','0','0'} };
	Solution obj;
	cout << obj.minArea(image, 0, 2);
	cin.get();
	return 0;
}