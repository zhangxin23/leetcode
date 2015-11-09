#include <iostream>
#include <bits/stl_bvector.h>
#include "tree.h"

using namespace std;

/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * Note: You may assume that duplicates do not exist in the tree.
 * */

class Solution {

    typedef vector<int>::iterator TreeNodeIterator;

public:
    TreeNode* buildTree(vector<int> inOrder, vector<int> postOrder) {
        return buildTreeCore(begin(inOrder), end(inOrder), begin(postOrder), end(postOrder));
    }

    TreeNode* buildTreeCore(TreeNodeIterator inFirst, TreeNodeIterator inLast,
                            TreeNodeIterator postFirst, TreeNodeIterator postLast) {
        if(inFirst == inLast)
            return NULL;

        if(postFirst == postLast)
            return NULL;

        TreeNode *root = new TreeNode(*prev(postLast));
        TreeNodeIterator inRootPos = find(inFirst, inLast, root->val);
        int leftSize = distance(inFirst, inRootPos);

        root->left = buildTreeCore(inFirst, next(inFirst, leftSize), postFirst, next(postFirst, leftSize));
        root->right = buildTreeCore(next(inRootPos), inLast, next(postFirst, leftSize), prev(postLast));

        return root;
    }
};