/*
255 Verify Preorder Sequence in Binary Search Tree

Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?
*/
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:

	// stack solution from http://www.cnblogs.com/grandyang/p/5327635.html
	bool verifyPreorder(vector<int>& preorder) {
		stack<int> s;
		int low = INT_MIN;
		for (int a : preorder) {
			if (a < low)	return false;
			while (!s.empty() && a > s.top()) {
				low = s.top(); s.pop();
			}
			s.push(a);
		}

		return true;
	}

	// O(1) space solution, use preorder's visited places as stack
	bool verifyPreorder2(vector<int>& preorder) {
		int low = INT_MIN, i = -1;
		for (auto a : preorder) {
			if (a < low) return false;
			while (i >= 0 && a > preorder[i]) {
				low = preorder[i--];
			}
			preorder[++i] = a;
		}
		return true;
	}

	// recursive solution, similar to 98 validate BST
	bool verifyPreorder3(vector<int>& preorder) {
		int lower = INT_MIN, upper = INT_MAX;
		return helper(preorder, 0, preorder.size() - 1, lower, upper);
	}

	bool helper(vector<int>& preorder, int start, int end, int lower, int upper) {
		if (start > end)	return true;
		int val = preorder[start];
		if (val <= lower || val >= upper)	return false;
		int i = start + 1;
		for (; i <= end; ++i) {
			if (preorder[i] > val)	break;
		}

		return helper(preorder, start + 1, i - 1, lower, val) &&
			helper(preorder, i, end, val, upper);
	}
};