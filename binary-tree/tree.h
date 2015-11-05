#ifndef LEETCODE_TREE_H
#define LEETCODE_TREE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

#endif //LEETCODE_TREE_H
