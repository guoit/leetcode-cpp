/*
297 Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

	1
   / \
  2   3
	 / \
	4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/
#include "utilities.h"
#include <sstream>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
class CodecDFS {
	string serialize(TreeNode* root) {
		ostringstream out;
		// dfs function
		function<void(TreeNode*)> dfs = [&](TreeNode* root)->void {
			if (root) {
				out << root->val << " ";
				dfs(root->left);
				dfs(root->right);
			}
			else {
				out << "# ";
			}
		};

		dfs(root);
		return out.str();
	}

	TreeNode* deserialize(string data) {
		istringstream in(data);
		// dfs to deserialize from string
		function<TreeNode*()> dfs = [&]()->TreeNode* {
			string val;
			in >> val;
			if (val == "#") return NULL;
			TreeNode* root = new TreeNode(stoi(val));
			root->left = dfs();
			root->right = dfs();

			return root;
		};
		
		return dfs();
	}
};
class CodecBFS {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream out;
		
		queue<TreeNode*> q;
		if (root) q.push(root);
		while (!q.empty()) {
			TreeNode* node = q.front(); q.pop();
			if (NULL == node) {
				out << "# ";
			}
			else {
				out << node->val << ' ';
				q.push(node->left);
				q.push(node->right);
			}
		}

		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.empty()) return NULL;
		istringstream in(data);
		// Parse root and create root node
		string val;
		in >> val;
		TreeNode* root = new TreeNode(stoi(val));
		// Initialize BFS queue
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			TreeNode* node = q.front(); q.pop();
			// parse and link left child
			if (!(in >> val)) break;
			if (val != "#") {
				node->left = new TreeNode(stoi(val));
				q.push(node->left);
			}
			// parse and link right child
			if (!(in >> val)) break;
			if (val != "#") {
				node->right = new TreeNode(stoi(val));
				q.push(node->right);
			}
		}

		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));