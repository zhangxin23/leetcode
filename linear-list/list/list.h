#ifndef LEETCODE_LIST_H
#define LEETCODE_LIST_H

#include <stddef.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

#endif //LEETCODE_LIST_H
