#include <iostream>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * */

class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(left * right != 0)
            return min(left, right) + 1;
        else if(left == 0)
            return right + 1;
        else if(right == 0)
            return left + 1;
    }
};