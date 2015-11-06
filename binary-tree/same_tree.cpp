#include <iostream>
#include <stack>
#include "tree.h"

using namespace std;

/**
 * Given two binary trees, write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 * */

class Solution {
public:
    bool isSameTreeRecursive(TreeNode *p, TreeNode *q) {
        if(!p && !q)
            return true;

        if(!p || !q)
            return false;

        return p->val == q->val
               && isSameTreeRecursive(p->left, q->left)
               && isSameTreeRecursive(p->right, q->right);
    }

    bool isSameTreeIterative(TreeNode *p, TreeNode *q) {
        stack<TreeNode *> s;
        s.push(p);
        s.push(q);

        while(!s.empty()) {
            p = s.top(); s.pop();
            q = s.top(); s.pop();

            if(!p && !q)
                continue;

            if(!p || !q)
                return false;

            if(p->val != q->val)
                return false;

            s.push(p->left);
            s.push(q->left);

            s.push(p->right);
            s.push(q->right);
        }

        return true;
    }
};