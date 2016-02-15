#include "list.h"

/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 * For example, Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space.
 * You may not modify the values in the list, only nodes itself can be changed.
 * */

class Solution {
public:
    ListNode* swapNodesInPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev1 = &dummy;
        ListNode* prev2 = prev1->next;
        ListNode* cur = prev2->next;
        while(prev2 && prev2->next) {
            prev2->next = cur->next;
            cur->next = prev1->next;
            prev1->next = cur;
            prev1 = prev2;
            prev2 = prev2->next;
            cur = prev2->next;
        }

        return dummy.next;
    }
};
