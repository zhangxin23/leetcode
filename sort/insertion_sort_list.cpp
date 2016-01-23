#include <iostream>
#include "../linear-list/list/list.h"

using namespace std;

/**
 * Sort a linked list using insertion sort.
 * */

class Solution {
public:
    ListNode* insertionSortList(ListNode *head) {
        if(head == NULL)
            return NULL;

        ListNode dummy(INT32_MIN);
        ListNode *p = head;
        while(p != NULL) {
            ListNode *pos = getPos(&dummy, p->val);
            ListNode *tmp = p->next;
            p->next = pos->next;
            pos->next = p;
            p = tmp;
        }

        return dummy.next;
    }

    ListNode* getPos(ListNode *head, int x) {
        ListNode *p = head;
        while(p != NULL && p->next != NULL && p->next->val < x) {
            p = p->next;
        }
        return p;
    }
};