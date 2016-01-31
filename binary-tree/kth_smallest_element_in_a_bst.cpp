#include <iostream>
#include "tree.h"

using namespace std;


/**
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
 * How would you optimize the kthSmallest routine?
 * */

//
// Created by zhangxin on 16/1/31.
//

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* result = NULL;
        inorder(root, k, &result);
        return result->val;
    }

    void inorder(TreeNode* root, int& k, TreeNode** result) {
        if(k == 0)
            return;

        if(root->left)
            inorder(root->left, k, result);

        if(k == 1) {
            *result = root;
            k--;
            return;
        }
        k--;

        if(root->right)
            inorder(root->right, k, result);
    }
};