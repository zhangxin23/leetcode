#include <iostream>
#include <stack>
#include "tree.h"

using namespace std;

/**
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *
 *                 5
 *                / \
 *               4   8
 *              /   / \
 *             11  13  4
 *            /  \      \
 *           7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 * */

class Solution {
public:
    bool hasPathSumRecursive(TreeNode *root, int sum) {
        if(root == NULL)
            return false;

        if(root->left == NULL && root->right == NULL && root->val == sum)
            return true;

        return hasPathSumRecursive(root->left, sum - root->val) ||
               hasPathSumRecursive(root->right, sum - root->val);
    }

    bool hasPathSumIterative(TreeNode *root, int sum) {
        stack<TreeNode *> node_stack;
        stack<int> value_stack;

        if(root) {
            node_stack.push(root);
            value_stack.push(root->val);
        }

        while(!node_stack.empty()) {
            TreeNode *node = node_stack.top(); node_stack.pop();
            int value = value_stack.top(); value_stack.pop();

            if(!node->left && !node->right && (value == sum))
                return true;

            if(node->left) {
                node_stack.push(node->left);
                value_stack.push(node->val + value);
            }

            if(node->right) {
                node_stack.push(node->right);
                value_stack.push(node->val + value);
            }
        }

        return false;
    }
};