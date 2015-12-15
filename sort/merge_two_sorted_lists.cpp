#include <iostream>
#include "../linear-list/list/list.h"

using namespace std;


/**
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 * */

class Solution {
public:
    ListNode* merge(ListNode *first, ListNode *second) {
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