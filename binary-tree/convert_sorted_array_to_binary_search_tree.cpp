#include <iostream>
#include "tree.h"

using namespace std;

/**
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 * */

class Solution {
public:
    TreeNode* sortedArray2BST(int array[], int n) {
        return sortedArray2BSTCore(array, 0, n - 1);
    }

    TreeNode* sortedArray2BSTCore(int array[], int start, int end) {
        if(array[start] >= array[end])
            return NULL;

        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(array[mid]);
        node->left = sortedArray2BSTCore(array, start, mid - 1);
        node->right = sortedArray2BSTCore(array, mid + 1, end);
        return node;
    }
};
