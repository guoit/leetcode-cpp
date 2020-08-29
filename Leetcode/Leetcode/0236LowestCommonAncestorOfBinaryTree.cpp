/*
236 Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

		_______3______
	   /              \
	___5__          ___1__
   /      \        /      \
   6      _2       0       8
		 /  \
		 7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Note:

All of the nodes' values will be unique.
p and q are different and both values will exist in the binary tree.
*/
#include "utilities.h"
using namespace std;
class Solution {
public:
	// This solution also handles the case that p or q doesn't exist in tree.
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		helper(root, p, q);
		return res;
	}

	// return value encoding:
	// 0 - no p or q found in this subtree
	// 1 - p was found in this subtree
	// 2 - q was found in this subtree
	// 3 - both p and q was found in this subtree
	int helper(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return 0;
		int left = helper(root->left, p, q);
		if (left == 3) return 3;
		int right = helper(root->right, p, q);
		if (right == 3) return 3;

		bool findP = (left & 1) || (right & 1) || (root == p);
		bool findQ = (left & 2) || (right & 2) || (root == q);

		int find = (findP ? 1 : 0) + (findQ ? 2 : 0);
		if (find == 3) res = root;
		return find;
	}

private:
	TreeNode* res;
};