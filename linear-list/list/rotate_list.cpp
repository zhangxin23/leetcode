#include "list.h"

/**
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example: Given 1->2->3->4->5->nullptr and k = 2, return 4->5->1->2->3->nullptr.
 * */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0)
            return head;

        int len = 1;
        ListNode* p = head;
        while(p->next) {
            len++;
            p = p->next;
        }
        k %= len;
        p->next = head;
        for(int step = 0; step < len - k; step++) {
            p = p->next;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};
