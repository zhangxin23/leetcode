#include <iostream>
#include <vector>
#include <stack>
#include "tree.h"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *node;
        stack<const TreeNode *> stk;

        if(root != NULL) {
            stk.push(root);
            node = root->left;
        }

        while(!stk.empty()) {
            if(node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                result.push_back(node->val);
                stk.pop();
                node = node->right;
            }
        }

        return result;
    }
};
