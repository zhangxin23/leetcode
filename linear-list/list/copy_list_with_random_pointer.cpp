#include <stddef.h>

/**
 * A linked list is given such that each node contains an additional random pointer which could point to
 * any node in the list or null.
 * Return a deep copy of the list.
 * */

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
        RandomListNode* cur = head;
        while(cur) {
            RandomListNode* tmp = new RandomListNode(cur->label);
            RandomListNode* next = cur->next;
            cur->next = tmp;
            tmp->next = next;
            cur = next;
        }

        cur = head;
        while(cur) {
            if(cur->random != NULL)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        cur = head;
        RandomListNode* new_head = head->next;
        RandomListNode* new_cur = new_head;
        while(new_cur) {
            cur->next = cur->next->next;
            new_cur->next = new_cur->next->next;
            cur = cur->next;
            new_cur = new_cur->next;
        }

        return new_head;
    }
};
