#ifndef SRC_ZHANGHONG_SRC_00148_SORT_LIST_00148_SORT_LIST_H_
#define SRC_ZHANGHONG_SRC_00148_SORT_LIST_00148_SORT_LIST_H_

#include <vector>
#include <iostream>

namespace Solution148 {

struct ListNode;

class Solution {
public:
    ListNode* sortList(ListNode* head);

    void quickSort(ListNode * head, ListNode * left, ListNode * right);

    void test(std::vector<int> vec);
};

}

#endif /* SRC_ZHANGHONG_SRC_00148_SORT_LIST_00148_SORT_LIST_H_ */
