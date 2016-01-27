#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *             5
 *            / \
 *           4   8
 *          /   / \
 *         11  13  4
 *        /  \    / \
 *       7    2  5   1
 * return
 *   [
 *      [5,4,11,2],
 *      [5,8,4,5]
 *   ]
 * */

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> cur;
        pathSumCore(root, sum, cur, result);
        return result;
    }

    void pathSumCore(TreeNode *root, int sum, vector<int> &cur, vector<vector<int> > &result) {
        if(!root)
            return;

        cur.push_back(root->val);

        if(!root->left && !root->right && root->val == sum) {
            result.push_back(cur);
            cur.pop_back();
            return;
        }

        pathSumCore(root->left, sum - root->val, cur, result);
        pathSumCore(root->right, sum - root->val, cur, result);

        cur.pop_back();
    }
};