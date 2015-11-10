#include <iostream>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * */

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};