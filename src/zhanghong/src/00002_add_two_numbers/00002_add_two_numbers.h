#ifndef SRC_ZHANGHONG_SRC_00002_ADD_TWO_NUMBERS
#define SRC_ZHANGHONG_SRC_00002_ADD_TWO_NUMBERS

struct ListNode
{
	int val;
	struct ListNode * next;

	ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode * l1, ListNode* l2);
};

#endif
