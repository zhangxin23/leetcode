#include <iostream>
#include "tree.h"
#include "../linear-list/list/list.h"

using namespace std;

/**
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 * */



class Solution {
public:
    TreeNode* sortedList2BST(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while(p) {
            len++;
            p = p->next;
        }
        return sortedList2BSTCore(head, 0, len - 1);
    }

    TreeNode* sortedList2BSTCore(ListNode*& list, int start, int end) {
        if(start > end)
            return NULL;

        int mid = start + (end - start) / 2;
        TreeNode *leftChild = sortedList2BSTCore(list, start, mid - 1);
        TreeNode *parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;
        parent->right = sortedList2BSTCore(list, mid + 1, end);
        return parent;
    }
};