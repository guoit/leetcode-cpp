/*
25 Reverse Nodes in K Group

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/
#include "utilities.h"

using namespace std;
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* extra = new ListNode(0);
		extra->next = head;

		ListNode *pre = extra, *tail = head;
		for (int i = 1; tail != NULL; ++i) {
			if (i % k == 0) {
				ListNode* next = tail->next; // temporarily save next group's head
				tail->next = NULL; // break the list on tail

				head = pre->next; // head of this k group
				reverse(head); // reverse this k group, so head is tail, tail is head now

				swap(head, tail); // swap the head and tail variables

				pre->next = head; // connect pre to this reversed k group
				tail->next = next; // connect this reversed k group to next group
				pre = tail; // update pre to tail
			}
			tail = tail->next;
		}

		head = extra->next;
		delete extra;
		return head;
	}

	// Reverse linkedlist
	void reverse(ListNode* head) {
		ListNode *cur = head, *pre = NULL;
		while (NULL != cur) {
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
	}
};