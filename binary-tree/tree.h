#ifndef LEETCODE_TREE_H
#define LEETCODE_TREE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL) {}
};

#endif //LEETCODE_TREE_H
