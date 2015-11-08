#include <iostream>
#include <stack>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree, flatten it to a linked list in-place.
 *
 *   For example,
 *   Given
 *
 *            1
 *           / \
 *          2   5
 *         / \   \
 *        3   4   6
 *   The flattened tree should look like:
 *      1
 *       \
 *        2
 *         \
 *          3
 *           \
 *            4
 *             \
 *              5
 *               \
 *                6
 * */

class Solution {
public:
    void flatten_recursive(TreeNode *root) {
        if(root == NULL)
            return;

        flatten_recursive(root->left);
        flatten_recursive(root->right);

        if(root->left == NULL)
            return;

        TreeNode *p = root->left;
        while(p->right)
            p = p->right;
        p->right = root->right;
        root->right = root->left;
        p->left = NULL;
    }

    void flatten_iterative(TreeNode *root) {
        stack<TreeNode *> s;
        if(root != NULL)
            s.push(root);

        while(!s.empty()) {
            TreeNode *p = s.top();
            s.pop();

            if(p->right != NULL)
                s.push(p->right);

            if(p->left != NULL)
                s.push(p->left);

            p->left = NULL;
            if(!s.empty())
                p->right = s.top();
        }
    }
};