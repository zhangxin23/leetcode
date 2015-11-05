#include <iostream>
#include <vector>
#include <queue>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree, return the bottom-up level order traversal of its nodes’ values.
 * (ie, from left to right, level by level from leaf to root).
 * */

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode *> current, next;
        vector<int> level;
        vector<vector<int> > result;

        if(root != NULL)
            current.push(root);

        while(!current.empty()) {
            while(!current.empty()) {
                TreeNode *node = current.front();
                current.pop();
                level.push_back(node->val);

                if(node->left != NULL)
                    next.push(node->left);
                if(node->right != NULL)
                    next.push(node->right);
            }
            result.push_back(level);
            level.clear();
            swap(current, next);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};