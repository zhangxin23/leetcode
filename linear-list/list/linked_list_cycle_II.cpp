/**
 *Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *Follow up: Can you solve it without using extra space?
 * */

class Solution {
    public:
        ListNode* detectCycle(ListNode* head) {
            ListNode* slow = head, *fast = head;
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast) {
                    ListNode* slow2 = head;
                    while(slow2 != fast) {
                        slow2 = slow2->next;
                        fast = fast->next;
                    }
                    return slow2;
                }
            }
            return null;
        }
};
