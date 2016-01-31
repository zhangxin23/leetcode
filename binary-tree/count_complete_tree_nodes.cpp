#include <iostream>
#include "tree.h"

using namespace std;

/**
 * Given a complete binary tree, count the number of nodes.
 *
 * Definition of a complete binary tree from Wikipedia:
 * In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.
 * It can have between 1 and 2h nodes inclusive at the last level h.
 * */

//
// Created by zhangxin on 16/1/31.
//

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left = getLeftHeight(root->left);
        int right = getRightHeight(root->right);

        if(left == right) {
            return (2 << left) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }

    int getLeftHeight(TreeNode* root) {
        if(root == NULL)
            return 0;

        int height = 0;
        while(root) {
            height++;
            root = root->left;
        }

        return height;
    }

    int getRightHeight(TreeNode* root) {
        if(root == NULL)
            return 0;

        int height = 0;
        while(root) {
            height++;
            root = root->right;
        }

        return height;
    }
};