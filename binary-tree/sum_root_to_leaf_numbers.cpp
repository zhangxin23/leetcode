#include <iostream>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *       1
 *      / \
 *     2   3
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 *
 * Return the sum = 12 + 13 = 25.
 * */

class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if(root == NULL)
            return 0;

        if(root->left == NULL && root->right == NULL)
            return 10 * sum + root->val;

        return pathSum(root->left, 10 * sum + root->val) +
               pathSum(root->right, 10 * sum + root->val);
    }
};