/**
 *You are given two linked lists representing two non-negative numbers.
 *The digits are stored in reverse order and each of their nodes contain a single digit.
 *Add the two numbers and return it as a linked list.
 *  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *  Output: 7 -> 0 -> 8
 * */

class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *firstList, ListNode *secondList) {
            ListNode dummy(-1);
            int carray = 0;
            ListNode *prev = &dummy;
            for(ListNode *pa = firstList, *pb = secondList;
                pa != nullptr || pb != nullptr;
                pa = pa == nullptr ? nullptr : pa->next,
                pb = pb == nullptr ? nullptr : pb->next,
                prev = prev->next) {
                const int ai = pa == nullptr ? 0 : pa->val;
                const int bi = pb == nullptr ? 0 : pb->val;
                const int value = (ai + bi + carry) % 10;
                prev->next = new ListNode(valud);
            }

            if(carry > 0)
                prev->next = new ListNode(carry);

            return dummy.next;
        }
};
