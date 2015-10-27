/**
 *Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers
 *from the original list.
 *For example,
 *Given 1->2->3->3->4->4->5, return 1->2->5.
 *Given 1->1->1->2->3, return 2->3.
 * */

class Solution {
    public:
        ListNode* removeDuplicates(ListNode* head) {
            if(head == null)
                return null;

            ListNode dummy(-1);
            dummy.next = head;
            ListNode* prev = &dummy;
            ListNode* cur = head;
            while(cur) {
                bool duplicate = false;
                while(cur->next != null && cur-val == cur->next->val) {
                    duplicate = true;
                    ListNode* tmp = cur;
                    cur = cur->next;
                    delete tmp;
                }

                if(duplicate) {
                    ListNode* tmp = cur;
                    cur = cur->next;
                    delete tmp;
                    continue;
                }

                prev->next= cur;
                prev = prev->next;
                cur = cur->next;
            }
            prev->next = null;
            return head;
        }
};
