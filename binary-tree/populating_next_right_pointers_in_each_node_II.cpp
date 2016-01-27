#include <iostream>
#include "tree.h"

using namespace std;

/**
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 *
 * What if the given tree could be any binary tree? Would your previous solution still work?
 *
 * Note:
 *
 * You may only use constant extra space.
 * For example,
 * Given the following binary tree,
 *            1
 *          /  \
 *         2    3
 *        / \    \
 *       4   5    7
 *   After calling your function, the tree should look like:
 *            1 -> NULL
 *          /  \
 *         2 -> 3 -> NULL
 *        / \    \
 *       4-> 5 -> 7 -> NULL
 * */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(root) {
            TreeLinkNode *cur = NULL;
            TreeLinkNode *next = NULL;
            for(; root; root = root->next) {
                if(!next)
                    next = root->left ? root->left : root->right;

                if(root->left) {
                    if(cur)
                        cur->next = root->left;
                    cur = root->left;
                }

                if(root->right) {
                    if(cur)
                        cur->next = root->right;
                    cur = root->right;
                }
            }
            root = next;
        }
    }
};