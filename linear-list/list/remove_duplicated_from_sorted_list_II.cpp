#include "list.h"

/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * For example,
 *  Given 1->2->3->3->4->4->5, return 1->2->5.
 *  Given 1->1->1->2->3, return 2->3.
 * */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;

        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy, *cur = head;
        bool duplicate = false;
        while(cur) {
            while(cur->next != NULL && cur->val == cur->next->val) {
                ListNode* temp = cur->next;
                cur->next = temp->next;
                delete temp;
                duplicate = true;
            }

            if(duplicate) {
                prev->next = cur->next;
                delete cur;
                cur = prev->next;
                duplicate = false;
                continue;
            }

            prev = cur;
            cur = cur->next;
        }

        return dummy.next;
    }
};
