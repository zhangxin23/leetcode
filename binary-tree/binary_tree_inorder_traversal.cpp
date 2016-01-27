#include <iostream>
#include <vector>
#include <stack>
#include "tree.h"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stk;
        if(root == NULL)
            return result;

        stk.push(root);
        TreeNode* node = root;
        while(!stk.empty()) {
            if(node->left) {
                stk.push(node->left);
                node = node->left;
            } else {
                TreeNode* tmp = stk.top();
                stk.pop();
                result.push_back(tmp->val);
                if(tmp->right) {
                    stk.push(tmp->right);
                    node = tmp->right;
                }
            }
        }

        return result;
    }
};
