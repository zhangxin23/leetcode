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

        if(root != NULL) {
            stk.push(root);
            curNode = root->left;
        }

        while(!stk.empty()) {
            while(curNode != NULL) {
                stk.push(curNode);
                curNode = curNode->left;
            }

            prevNode = NULL;
            while(!stk.empty()) {
                curNode = stk.top();
                stk.pop();
                if(curNode->right == prevNode) {
                    result.push_back(curNode->val);
                    prevNode = curNode;
                } else {
                    stk.push(curNode);
                    curNode = curNode->right;
                    break;
                }
            }
        }

        return result;
    }
};

