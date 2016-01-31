#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia:
 * “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
 *
 *       _______3______
 *      /              \
 *   ___5__          ___1__
 *  /      \        /      \
 *  6      _2       0       8
 *        /  \
 *        7   4
 * For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3.
 * Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 * */

//
// Created by zhangxin on 16/1/30.
//

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == NULL || p == NULL || q == NULL)
            return NULL;

        vector<TreeNode*> pPath, qPath;

        findPath(root, p, pPath);
        findPath(root, q, qPath);

        TreeNode* result = NULL;
        for(int i = 0; i < min(pPath.size(), qPath.size()); i++) {
            if(pPath[i] == qPath[i])
                result = pPath[i];
            else
                break;
        }

        return result;
    }

    bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        if(root == NULL)
            return false;

        path.push_back(root);
        if(root == node)
            return true;

        if(root->left && findPath(root->left, node, path))
            return true;

        if(root->right && findPath(root->right, node, path))
            return true;

        path.pop_back();

        return false;
    }
};
