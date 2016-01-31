#include <iostream>
#include <vector>
#include <queue>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
 *      1            <---
 *    /   \
 *   2     3         <---
 *    \     \
 *     5     4       <---
 * You should return [1, 3, 4].
 * */

//
// Created by zhangxin on 16/1/31.
//

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<int> level;
        queue<TreeNode*> cur, next;
        TreeNode* node = NULL;
        if(root == NULL)
            return result;

        cur.push(root);
        while(!cur.empty()) {
            while(!cur.empty()) {
                node = cur.front();
                cur.pop();
                level.push_back(node->val);

                if(node->left)
                    next.push(node->left);

                if(node->right)
                    next.push(node->right);
            }

            if(level.size() > 0)
                result.push_back(level[level.size() - 1]);
            level.clear();
            swap(cur, next);
        }

        return result;
    }
};