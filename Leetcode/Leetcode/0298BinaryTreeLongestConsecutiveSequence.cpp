/*
298 Binary Tree Longest Consecutive Sequence

Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,

   1
	\
	 3
	/ \
   2   4
		\
		 5
Longest consecutive sequence path is 3-4-5, so return 3.

   2
	\
	 3
	/
   2
  /
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/
#include <algorithm>
#include "utilities.h"
class Solution {
public:
	int longestConsecutive(TreeNode* root) {
		if (NULL == root)	return 0;
		int res = 1;
		dfs(root->left, root->val, 1, res);
		dfs(root->right, root->val, 1, res);

		return res;
	}
	void dfs(TreeNode* node, int preVal, int cnt, int& res) {
		if (node){
			if (node->val != preVal + 1) cnt = 0;
			res = max(res, cnt + 1);
			dfs(node->left, node->val, cnt + 1, res);
			dfs(node->right, node->val, cnt + 1, res);
		}
	}
};