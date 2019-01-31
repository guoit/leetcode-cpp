/*
94 Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
	\
	 2
	/
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <deque>
#include "utilities.h"

class Solution {
public:
	// recursive solution
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		helper(root, res);

		return res;
	}

	void helper(TreeNode* root, vector<int>& res) {
		if (NULL != root) {
			helper(root->left, res);
			res.push_back(root->val);
			helper(root->right, res);
		}
	}

	// iterative solution
	vector<int> inorderTraversal_Iterative(TreeNode* root) {
		deque<TreeNode*> q;
		vector<int> res;
		TreeNode* it = root;

		while (NULL != it) {
			q.push_back(it);
			it = it->left;
		}

		while (!q.empty()) {
			it = q.back();
			res.push_back(it->val);
			q.pop_back();

			it = it->right;
			while (NULL != it) {
				q.push_back(it);
				it = it->left;
			}
		}

		return res;
	}
};

