#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

/* Print vector like [1, 2, 3, 4] */
template <class T>
static void myprint(vector<T>& A) {
	cout << "[";
	for (auto it = A.begin(); it != A.end(); ++it) {
		cout << *it;
		if (next(it) != A.end()) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

/* Print set like {1, 2, 3, 4} */
template <class T>
static void myprint(set<T>& S) {
	cout << "{";
	for (auto it = S.begin(); it != S.end(); ++it) {
		cout << *it;
		if (next(it) != S.end()) {
			cout << ", ";
		}
	}
	cout << "}" << endl;
}

/* Print map like {a:1, b:2, c:3, d:4} */
template <class T1, class T2>
static void myprint(map<T1, T2>& M) {
	cout << "{";
	for (auto it = M.begin(); it != M.end(); ++it) {
		cout << it->first<<":"<<it->second;		
		if (next(it) != M.end()) {
			cout << ", ";
		}
	}
	cout << "}" << endl;
}

/* TreeNode definition */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}	
};

/*Definition for singly - linked list.*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};