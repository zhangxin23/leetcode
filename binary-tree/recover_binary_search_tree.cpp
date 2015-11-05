#include <iostream>
#include "tree.h"

using namespace std;


/**
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * Recover the tree without changing its structure.
 * Note: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
 * */

class Solution {
private:
    TreeNode *mistake1, *mistake2;
    TreeNode *pre;

public:
    void inorderTraversal(TreeNode *root) {
        if(root == NULL) {
            return;
        }

        if(root->left != NULL) {
            inorderTraversal(root->left);
        }

        if(pre != NULL && root->val < pre->val) {
            if(mistake1 == NULL) {
                mistake1 = pre;
                mistake2 = root;
            } else {
                mistake2 = root;
            }
        }

        pre = root;

        if(root->right != NULL) {
            inorderTraversal(root->right);
        }
    }

    void recoverTree(TreeNode *root) {
        inorderTraversal(root);
        if(mistake1 != NULL && mistake2 != NULL) {
            int tmp = mistake1->val;
            mistake1->val = mistake2->val;
            mistake2->val = tmp;
        }
    }
};
