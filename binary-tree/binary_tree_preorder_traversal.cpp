#include <iostream>
#include <vector>
#include <stack>
#include "tree.h"

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *node;
        stack<const TreeNode *> stk;

        if(root != NULL)
            stk.push(root);

        while(!stk.empty()) {
            node = stk.top();
            stk.pop();
            result.push_back(node->val);

            if(node->right != NULL)
                stk.push(node->right);

            if(node->left != NULL)
                stk.push(node->left);
        }

        return result;
    }
};