
/*
https://leetcode.com/problems/reorder-list/description/

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

*/

#include "stdafx.h"
#include "listnode.h"

using namespace std;

/*
	So the idea is first find the middle point of the list, then divide it by 2 parts: first and second.
	We then reverse the second part and reorder the 2 parts one by one.

	for a list like [1,2,3,4], the steps are:

	1. first: 1->2, second: 3->4.
	2. first: 1->2, second: 4->3.
	3. combine: 1->4->2->3.

	Time complexity is O(n), space complexity is O(1).
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution{
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next) return;

		ListNode* s = head, *f = head;

		while (f->next && f->next->next)
		{
			s = s->next;
			f = f->next->next;
		}

		ListNode* r = s->next;
		ListNode* next = r, *pre = nullptr;
		s->next = nullptr;

		while (r)
		{
			next = r->next;
			r->next = pre;
			pre = r;
			r = next;
		}

		ListNode* first = head, *sec = pre;

		while (first && sec)
		{
			ListNode* temp1 = first->next, *temp2 = sec->next;
			first->next = sec;
			sec->next = temp1;

			first = temp1;
			sec = temp2;
		}
	}
};