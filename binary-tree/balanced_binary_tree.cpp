#include <iostream>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two
 * subtrees of every node never differ by more than 1.
 * */

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return isBalancedHeight(root) >= 0;
    }

    int isBalancedHeight(TreeNode *root) {
        if(root == NULL)
            return 0;

        int left = isBalancedHeight(root->left);
        int right = isBalancedHeight(root->right);

        if(left < 0 || right < 0 || abs(left - right) > 1)
            return -1;

        return max(left, right) + 1;
    }
};