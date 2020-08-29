/*
124 Binary Tree Maximum Path Sum

Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

	   1
	  / \
	 2   3
Return 6.
*/
#include "utilities.h"
#include <algorithm>
#include <list>
using namespace std;
class Solution {
public:
	int maxPathSum(TreeNode* root) {
		long global = INT_MIN;
		helper(root, global);
		return global;
	}

	int helper(TreeNode* root, long& global) {
		if (NULL == root) return 0;
		long left = max(helper(root->left, global), 0);
		long right = max(helper(root->right, global), 0);
		long value = root->val;

		long local = max(left, right) + value;
		global = max(global, value + left + right);

		return local;
	}
};

// Solution that outputs the max path in "tans"
class MaxPathSolution {
public:
	list<int> tans;
	int maxPathSum(TreeNode* root) {
		if (root == 0)return 0;
		int ans = root->val;
		int tmp = 0;
		help(root, ans, tmp);
		return ans;
	}
	list<int> help(TreeNode* root, int& ans, int &tmpans) {
		if (root == 0) {
			tmpans = 0;
			return {};
		}
		list<int> l = help(root->left, ans, tmpans);
		int lv = tmpans;
		list<int> r = help(root->right, ans, tmpans);
		int rv = tmpans;

		if (lv <= rv) {
			swap(l, r);
			swap(lv, rv);
		}
		if (rv <= 0) {
			rv = 0;
			r.clear();
		}
		if (lv <= 0) {
			l.clear();
			lv = 0;
		}
		tmpans = max(lv, rv) + root->val;
		l.push_back(root->val);
		if (lv + rv + root->val > ans) {
			ans = lv + rv + root->val;
			tans = l;
			tans.splice(tans.end(), r);
		}
		return l;
	}

};
