#include "list.h"

/**
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *      Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *      Output: 7 -> 0 -> 8
 * */

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode *firstList, ListNode *secondList) {
            ListNode dummy(-1);
            int carry = 0;
            ListNode *prev = &dummy;
            for(ListNode *pa = firstList, *pb = secondList; pa != NULL || pb != NULL;
                pa = pa == NULL ? NULL : pa->next, pb = pb == NULL ? NULL : pb->next, prev = prev->next) {
                int ai = pa == NULL ? 0 : pa->val;
                int bi = pb == NULL ? 0 : pb->val;
                int value = (ai + bi + carry) % 10;
                prev->next = new ListNode(value);
                carry = (ai + bi + carry) / 10;
            }

            if(carry > 0)
                prev->next = new ListNode(carry);

            return dummy.next;
        }
};
