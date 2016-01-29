#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *      1
 *    /   \
 *   2     3
 *    \
 *     5
 * All root-to-leaf paths are:
 *
 * ["1->2->5", "1->3"]
 * */

//
// Created by zhangxin on 16-1-29.
//

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        core(root, result, path);
        return result;
    }

    void core(TreeNode* root, vector<string>& result, vector<int>& path) {
        if(!root)
            return;

        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            string str = to_string(path[0]);
            for(int i = 1; i < path.size(); i++)
                str = str + "->" + to_string(path[i]);
            result.push_back(str);
            path.pop_back();
            return;
        }

        core(root->left, result, path);
        core(root->right, result, path);
        path.pop_back();
    }
};
