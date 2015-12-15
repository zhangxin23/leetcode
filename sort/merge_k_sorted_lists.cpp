#include <iostream>
#include <vector>
#include "../linear-list/list/list.h"

using namespace std;

/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * */

class Solution {
public:
    ListNode* merge(vector<ListNode*> &lists) {
        if(lists.size() == 0)
            return NULL;

        ListNode *p = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            p = mergeTwoSortedList(p, lists[i]);
        }

        return p;
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