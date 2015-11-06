#include <iostream>
#include <stack>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * */

class Solution {
public:
    bool isSymmetricTreeRecursive(TreeNode *root) {
        return root == NULL ? true : isSymmetricRecursive(root->left, root->right);
    }

    bool isSymmetricRecursive(TreeNode *left, TreeNode *right) {
        if(!left && !right)
            return true;

        if(!left || !right)
            return false;

        return left->val == right->val
                && isSymmetricRecursive(left->left, right->right)
                && isSymmetricRecursive(left->right, right->left);
    }

    bool isSymmetricTreeIterative(TreeNode *root) {
        if(root == NULL)
            return true;

        stack<TreeNode *> s;
        s.push(root->left);
        s.push(root->right);
        TreeNode *p, *q;

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
            s.push(q->right);

            s.push(p->right);
            s.push(q->left);
        }

        return true;
    }
};
