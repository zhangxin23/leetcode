#include "list.h"

/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 * For example, Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 *  • Given n will always be valid.
 *  • Try to do this in one pass.
 * */

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode dummy(-1);
            dummy.next = head;
            ListNode* p = &dummy, *q = &dummy;

            for(int i = 0; i < n; i++) {
                p = p->next;
            }

            while(p->next) {
                p = p->next;
                q = q->next;
            }

            ListNode* tmp= p->next;
            p->next = p->next->next;
            delete tmp;
            return head;
        }
};
