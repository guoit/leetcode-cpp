/*
250 Count Univalue Subtrees

Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,

			  5
			 / \
			1   5
		   / \   \
		  5   5   5


return 4.
*/
#include "utilities.h"
class Solution {
public:
	int countUnivalSubtrees(TreeNode* root) {
		int count = 0;
		univalue(root, count);
		return count;
	}

	bool univalue(TreeNode* root, int &count) {
		if (NULL == root)	return true;

		bool bUnivalue = true;
		if (root->left) {
			bUnivalue &= univalue(root->left, count);
			bUnivalue &= root->val == root->left->val;
		}
		if (root->right) {
			bUnivalue &= univalue(root->right, count);
			bUnivalue &= root->val == root->right->val;
		}

		count += bUnivalue;
	}
};

//int main() {
//	TreeNode root(5);
//	root.left = &TreeNode(1);
//	root.right = &TreeNode(5);
//	root.left->left = &TreeNode(5);
//	root.left->right = &TreeNode(5);
//	root.right->right = &TreeNode(5);
//
//	Solution obj;
//	cout << obj.countUnivalSubtrees(&root)<< endl;
//
//	cin.get();
//	return 0;
//}