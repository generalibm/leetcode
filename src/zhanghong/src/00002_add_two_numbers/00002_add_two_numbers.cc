#include "00002_add_two_numbers.h"

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{

//	2 4 3
//	5 6 4 7

	ListNode preHead(0), *p = &preHead;
	int extra = 0;
	while (l1 || l2 || extra)
	{
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
		extra = sum / 10;
		p->next = new ListNode(sum % 10);
		p = p->next;
		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
	}
	return preHead.next;
}
