#include <iostream>
#include <stack>
#include "tree.h"

using namespace std;

/**
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 * */

//
// Created by zhangxin on 16/1/31.
//

class BSTIterator {
private:
    stack<TreeNode*> stk;

public:
    BSTIterator(TreeNode *root) {
        while(root) {
            stk.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        int ret = node->val;
        if(node->right) {
            node = node->right;
            while(node) {
                stk.push(node);
                node = node->left;
            }
        }
        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */