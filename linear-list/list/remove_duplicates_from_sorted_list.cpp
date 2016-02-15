#include "list.h"

/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 *  Given 1->1->2, return 1->2.
 *  Given 1->1->2->3->3, return 1->2->3.
 * */

class Solution {
public:
    ListNode* removeDulicates(ListNode* head) {
        if(head == NULL)
            return NULL;

        for(ListNode* prev = head, *cur = head->next; cur; cur = cur->next) {
            if(prev->val == cur->val) {
                prev->next = cur->next;
                delete cur;
                cur = prev;
            } else {
                prev = cur;
            }
        }

        return head;
    }
};
