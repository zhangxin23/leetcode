#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST’s shown below.
 *
 *  1         3     3      2      1
 *   \       /     /      / \      \
 *    3     2     1      1   3      2
 *   /     /       \                 \
 *  2     1         2                 3
 *
 * OJ's Binary Tree Serialization:
 * The serialization of a binary tree follows a level order traversal,
 * where '#' signifies a path terminator where no node exists below.
 *
 * Here's an example:
 *      1
 *     / \
 *    2   3
 *       /
 *      4
 *       \
 *        5
 * The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 * */

class Solution {
public:
    vector<TreeNode *> generateTree(int n) {
        return generate(0, n - 1);
    }

    vector<TreeNode *> generate(int start, int end) {
        vector<TreeNode *> result;

        if(start > end) {
            result.push_back(NULL);
            return result;
        }

        for(int i = start; i <= end; i++) {
            vector<TreeNode *> left = generate(start, i - 1);
            vector<TreeNode *> right = generate(i + 1, end);

            for(int j = 0; j < left.size(); j++) {
                for(int k = 0; k < right.size(); k++) {
                    TreeNode *node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};