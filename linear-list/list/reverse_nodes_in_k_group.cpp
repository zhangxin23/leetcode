/**
 *Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *You may not alter the values in the nodes, only nodes itself may be changed.
 *Only constant memory is allowed.
 *For example, Given this linked list: 1->2->3->4->5
 *For k = 2, you should return: 2->1->4->3->5
 *For k = 3, you should return: 3->2->1->4->5
 * */

class Solution {
    public:
        ListNode* reverseNodesInKGroup(ListNode* head, int k) {
            if(head == nullptr || head->next == nullptr || k < 2)
                return head;

            ListNode dummy(-1);
            dummy.next = head;
            for(ListNode* prev = &dummy, *end = prev->next;
                end;
                end = prev->next) {
                for(int i = 0; i < k && end != nullptr; k++) {
                    end = end->next;
                }

                if(i != k - 1)
                    break;

                prev = reverseKNodes(prev, prev->next, end);
            }
            return dummy.next;
        }

        ListNode* reverseKNodes(ListNode* prev, ListNode* begin, ListNode* end) {
            ListNode* end_next = end->next;
            for(ListNode* prev1 = begin, *prev2 = begin->next, *prev3 = prev2->next;
                prev3 != end_next;
                prev1 = prev2, prev2 = prev3, prev3 = prev3 ? prev3->next : nullptr) {
                prev2->next = prev1;
            }

            prev->next = end;
            begin->next = end_next;
            prev = begin;
            return prev;
        }
};
