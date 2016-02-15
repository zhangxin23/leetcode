#include "list.h"

/**
 * Given a singly linked list L : L(0)→ L(1)→ · · ·→ L(n−1)→ L(n),
 * reorder it to: L(0)→ L(n)→ L(1)→ L(n−1)→ L(2)→ L(n−2)→ · · ·
 * You must do this in-place without altering the nodes’ values.
 * For example, Given {1,2,3,4}, reorder it to {1,4,2,3}.
 * */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head;
        ListNode* prev = slow;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        slow = reverse(slow);

        ListNode* cur = head;
        while(cur && slow) {
            prev = cur->next;
            cur->next = slow;
            slow = slow->next;
            cur->next->next = prev;
            cur = prev;
        }

        if(slow)
            cur->next = slow;
    }

    ListNode* reverse(ListNode* head){
        if(head == NULL){
            return NULL;
        }

        ListNode* prev = head->next;
        head->next = NULL;

        while(prev != NULL){
            ListNode* tmp = prev;
            prev = prev->next;
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
};
