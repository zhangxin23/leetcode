#include <iostream>
#include "../linear-list/list/list.h"

using namespace std;

/**
 * Sort a linked list in O(nlogn) time using constant space complexity.
 * */


class Solution {
public:
    ListNode* sortList(ListNode *head) {
        if(head == NULL)
            return NULL;

        ListNode *slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow ->next;
        }

        fast = slow;
        slow = slow->next;
        fast->next = NULL;

        ListNode *first = sortList(head);
        ListNode *second = sortList(slow);

        return mergeTwoSortedList(first, second);
    }

    ListNode* mergeTwoSortedList(ListNode *first, ListNode *second) {
        if(first == NULL)
            return second;

        if(second == NULL)
            return first;

        ListNode dummy(-1);
        ListNode *p = &dummy;
        while(first != NULL && second != NULL) {
            if(first->val < second->val) {
                p->next = first;
                first = first->next;
            } else {
                p->next = second;
                second = second->next;
            }
            p = p->next;
        }

        p->next = first != NULL ? first : second;

        return dummy.next;
    }
};