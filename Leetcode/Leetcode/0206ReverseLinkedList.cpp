/*
206 Reverse Linked List

Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "utilities.h"

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* node = head;
		head = NULL;
		while (NULL != node) {
			ListNode* _next = node->next;
			node->next = head;
			head = node;
			node = _next;
		}

		return head;
	}
};