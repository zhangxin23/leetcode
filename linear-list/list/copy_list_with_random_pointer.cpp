/**
 *A linked list is given such that each node contains an additional random pointer which could point to
 *any node in the list or null.
 *Return a deep copy of the list.
 * */

class Solution {
    public:
        RandomListNode* copyRandomList(RandomListNode* head) {
            RandomListNode* cur = head;
            while(cur) {
                RandomListNode* tmp = new RandomListNode(prev->val);
                RandomListNode* next = cur->next;
                cur->next = tmp;
                tmp->next = next;
                cur = next;
            }

            cur = head;
            while(cur) {
                if(cur->random != nullptr)
                    cur->next->random = cur->random->next;
                cur = cur->next->next;
            }

            RandomListNode* new_head = head->next;
            RandomListNode* cur = head;
            RandomListnode* new_cur = new_head;
            while(new_cur) {
                cur->next = cur->next->next;
                new_cur->next = new_cur->next->next;
                cur = cur->next;
                new_cur = new_cur->next;
            }

            return new_head;
        }
};
