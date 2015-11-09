#include <iostream>
#include <bits/stl_bvector.h>
#include "tree.h"

using namespace std;

/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note: You may assume that duplicates do not exist in the tree.
 * */

class Solution {

    typedef vector<int>::iterator TreeNodeIterator;

public:
    TreeNode* buildTree(vector<int> preOrder, vector<int> inOrder) {
        return buildTreeCore(begin(preOrder), end(preOrder), begin(inOrder), end(inOrder));
    }

    TreeNode* buildTreeCore(TreeNodeIterator preFirst, TreeNodeIterator preLast,
                            TreeNodeIterator inFirst, TreeNodeIterator inLast) {
        if(preFirst == preLast)
            return NULL;

        if(inFirst == inLast)
            return NULL;

        TreeNode *root = new TreeNode(*preFirst);
        TreeNodeIterator inRootPos = find(inFirst, inLast, root->val);
        int leftSize = distance(inFirst, inRootPos);

        root->left = buildTreeCore(next(preFirst), next(preFirst, leftSize + 1), inFirst, next(preFirst, leftSize));
        root->right = buildTreeCore(next(preFirst, leftSize + 1), preLast, next(inRootPos), inLast);

        return root;
    }
};