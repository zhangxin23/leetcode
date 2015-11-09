#include <iostream>
#include <stack>
#include <vector>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree, return the zigzag level order traversal of its nodes’ values.
 * (ie, from left to right, then right to left for the next level and alternate between).
 * */

class Solution {
public:
    vector<vector<int> > zigzagOrderLevel(TreeNode *root) {
        vector<vector<int> > result;
        vector<int> level;
        stack<TreeNode *> current, next;

        if(root != NULL)
            current.push(root);

        bool right_to_left = true;

        while(!current.empty()) {
            while(!current.empty()) {
                TreeNode *node = current.top();
                current.pop();
                level.push_back(node->val);

                if(right_to_left) {
                    if(node->left != NULL)
                        next.push(node->left);
                    if(node->right != NULL)
                        next.push(node->right);
                } else {
                    if(node->right != NULL)
                        next.push(node->right);
                    if(node->left != NULL)
                        next.push(node->left);
                }
            }

            right_to_left = !right_to_left;
            result.push_back(level);
            level.clear();
            swap(current, next);
        }
        return result;
    }
};