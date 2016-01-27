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

private:
    //中序遍历思路
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

public:
    TreeNode* sortedList2BSTIterator(ListNode *head) {
        return sortedList2BSTIteratorCore(head);
    }

private:
    //仿照排序数组转化为BST的思路
    TreeNode* sortedList2BSTIteratorCore(ListNode *head) {
        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return new TreeNode(head->val);

        ListNode *fast = head, *slow = head, *prev = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        ListNode *left = head, *mid = slow, *right = mid->next;
        prev->next = NULL;

        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedList2BSTIteratorCore(left);
        root->right = sortedList2BSTIteratorCore(right);
        return root;
    }
};
