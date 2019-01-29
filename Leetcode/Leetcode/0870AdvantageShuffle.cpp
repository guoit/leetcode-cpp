/*
870 Advantage Shuffle

Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.

Example 1:

Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]
Example 2:

Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]

Note:

1 <= A.length = B.length <= 10000
0 <= A[i] <= 10^9
0 <= B[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "utilities.h"

using namespace std;

class Solution {
public:
	vector<int> advantageCount(vector<int>& A, vector<int>& B) {
		map<int, int> remains;
		for (int num : A) {
			auto it = remains.find(num);
			if (it != remains.end()) {
				it->second++;
			}
			else {
				remains[num] = 1;
			}
		}
		//myprint(remains);

		vector<int> res;
		for (int num : B) {
			auto it = remains.lower_bound(num + 1);
			if (it == remains.end()) {
				it = remains.begin();
			}
			res.push_back(it->first);
			if (--(it->second) == 0) {
				remains.erase(it);
			}
		}

		return res;
	}
};

int main() {
	Solution obj;
	vector<int> A{ 12,24,8,32 };
	vector<int> B{ 13,25,32,11 };
	
	vector<int> C = obj.advantageCount(A, B);
	myprint(C);	

	cin.get();
	return 0;
}