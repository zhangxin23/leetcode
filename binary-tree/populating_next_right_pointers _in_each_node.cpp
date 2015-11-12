#include <iostream>
#include "tree.h"

using namespace std;

/**
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 * Note:
 *
 * You may only use constant extra space.
 * You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 * For example,
 * Given the following perfect binary tree,
 *        1
 *      /  \
 *     2    3
 *    / \  / \
 *   4  5  6  7
 * After calling your function, the tree should look like:
 *        1 -> NULL
 *      /  \
 *     2 -> 3 -> NULL
 *    / \  / \
 *   4->5->6->7 -> NULL
 * */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *next = NULL;
        while(root) {
            if(next == NULL)
                next = root->left == NULL ? NULL : root->left;

            TreeLinkNode *prev = NULL;
            for(; root != NULL; root = root->next) {
                if(prev)
                    prev->next = root->left;
                root->left->next = root->right;
                prev = root->right;
            }
            root = next;
        }
    }
};