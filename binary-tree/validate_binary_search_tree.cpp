#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;


/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * • The left subtree of a node contains only nodes with keys less than the node’s key.
 * • The right subtree of a node contains only nodes with keys greater than the node’s key.
 * • Both the left and right subtrees must also be binary search trees.
 * */

class Solution {
public:
    bool validBST(TreeNode *root) {
        vector<int> result;
        inorder(root, result);
        for(int i = 0; i < result.size(); i++) {
            if(i > 0 && result[i - 1] >= result[i])
                return false;
        }
        return true;
    }

    void inorder(TreeNode* root, vector<int>& result) {
        if(root)
            return;

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
};