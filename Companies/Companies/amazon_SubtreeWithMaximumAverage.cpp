/*
Subtree: Maximum average node	-	Amazon OA2

Given a binary tree, find the subtree with maximum average. Return the root of the subtree.
Example Given a binary tree:
               1
              /  \
			-5   11
			/ \  / \
		   1  2  4 -2
return the node 11.

Your problem can be different in ways like -- it may not be a binary tree or the average doesn't include the root of the substree.

// TreeNode definition
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
#include "utilities.h"
class Solution {
public:
	TreeNode* findSubtree(TreeNode* root) {
		maxAvg = -DBL_MAX;
		res = NULL;
		if (NULL == root)	return NULL;
		getSubtreeCountSum(root);

		return res;
	}

	// subfunction calculates number of nodes, and their sum, also checks if this average is the largest
	pair<int, long> getSubtreeCountSum(TreeNode* root) {
		if (NULL == root)	return { 0, 0L };
		auto left = getSubtreeCountSum(root->left);
		auto right = getSubtreeCountSum(root->right);
		
		long sum = left.second + right.second + root->val;
		int cnt = left.first + right.first + 1;
		double avg = (double)sum / (double)cnt;

		if (cnt > 1 && avg > maxAvg) {	// cnt > 1 to exclude tree leaves
			res = root;
			maxAvg = avg;
		}

		return make_pair(cnt, sum);
	}

private:
	double maxAvg;
	TreeNode* res;
};

//int main() {
//	TreeNode root(1);
//	root.left = &TreeNode(-5);
//	root.right = &TreeNode(11);
//	root.left->left = &TreeNode(1);
//	root.left->right = &TreeNode(2);
//	root.right->left = &TreeNode(4);
//	root.right->right = &TreeNode(-2);
//
//	Solution obj;
//	cout << obj.findSubtree(&root)->val << endl;
//
//	cin.get();
//	return 0;
//}