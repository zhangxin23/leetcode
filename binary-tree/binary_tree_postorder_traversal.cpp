#include <iostream>
#include <stack>
#include <vector>
#include "tree.h"

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode *curNode, *prevNode;
        stack<TreeNode *> stk;

        if(root == NULL)
            return result;

        stk.push(root);
        curNode = root->left;

        while(!stk.empty()) {
            while(curNode != NULL) {
                stk.push(curNode);
                curNode = curNode->left;
            }

            prevNode = NULL;
            while(!stk.empty()) {
                TreeNode* temp = stk.top();
                stk.pop();
                if(temp->right == prevNode) {
                    result.push_back(temp->val);
                    prevNode = temp;
                } else {
                    stk.push(temp);
                    curNode = temp->right;
                    break;
                }
            }
        }

        return result;
    }
};

