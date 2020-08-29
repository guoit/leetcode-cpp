/*
116 Populating Next Right Pointers in Each Node

Given a binary tree

	struct TreeLinkNode {
	  TreeLinkNode *left;
	  TreeLinkNode *right;
	  TreeLinkNode *next;
	}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
		 1
	   /  \
	  2    3
	 / \  / \
	4  5  6  7
After calling your function, the tree should look like:
		 1 -> NULL
	   /  \
	  2 -> 3 -> NULL
	 / \  / \
	4->5->6->7 -> NULL
*/
#include "utilities.h"
using namespace std;
struct Node {
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node(int value) : val(value), left(NULL), right(NULL), next(NULL) {	}
};
class Solution {
public:
	Node* connect(Node* root) {
		if (!root) return NULL;
		Node* extra = new Node(0);   // extra pre Node before each children's level list     
		Node *parent = root;

		while (parent->left != NULL) { // height level traversal
			Node *pre = extra;

			while (parent != NULL) { // horizontal level traversal
				pre->next = parent->left;
				parent->left->next = parent->right;
				pre = parent->right;
				parent = parent->next;
			}

			parent = extra->next; // go to next level
		}

		delete extra;
		return root;
	}
};