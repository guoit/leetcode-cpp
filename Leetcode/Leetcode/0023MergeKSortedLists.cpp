/*
23 Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
Example:
Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "utilities.h"
#include <queue>
using namespace std;
struct cmp {
	bool operator()(ListNode* node1, ListNode* node2) {
		return node1->val > node2->val;
	}

};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
		ListNode sentinel(0);
		ListNode* pre = &sentinel;
		for (ListNode* node : lists) {
			if (node) pq.push(node); // pitfall: the given lists may contain NULL pointers
		}
		while (!pq.empty()) {
			pre->next = pq.top(); pq.pop();
			pre = pre->next;
			if (NULL != pre->next) pq.push(pre->next);
		}
		return sentinel.next;
	}
};