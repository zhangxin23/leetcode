#include <iostream>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree, find the maximum path sum.
 * The path may start and end at any node in the tree.
 *
 * For example:
 * Given the below binary tree,
 *       1
 *     /  \
 *    2    3
 *
 * Return 6.
 * */

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maxSum = INT32_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

    int dfs(TreeNode *root, int &maxSum) {
        if(root == NULL)
            return 0;

        int left = dfs(root->left, maxSum);
        int right = dfs(root->right, maxSum);

        int sum = root->val;
        if(left > 0)
            sum += left;
        if(right > 0)
            sum += right;

        maxSum = max(maxSum, sum);

        return max(left, right) > 0 ? max(left, right) + root->val : root->val;
    }
};
