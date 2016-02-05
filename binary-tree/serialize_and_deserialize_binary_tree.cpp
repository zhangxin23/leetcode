#include <iostream>
#include <queue>
#include <sstream>
#include "tree.h"

using namespace std;

/**
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer,
 * or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree.
 * There is no restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
 *
 * For example, you may serialize the following tree
 *
 *       1
 *      / \
 *     2   3
 *        / \
 *       4   5
 * as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree.
 * You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
 * Note: Do not use class member/global/static variables to store states.
 * Your serialize and deserialize algorithms should be stateless.
 * */

//
// Created by zhangxin on 16/1/31.
//

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "[";
        queue<TreeNode*> q;
        TreeNode* node = NULL;
        if(root == NULL)
            return result;

        q.push(root);
        result += to_string(root->val);
        while(!q.empty()) {
            node = q.front();
            q.pop();

            result += ",";
            result += root->left ? to_string(root->left->val) : "null";
            result += ",";
            result += root->right ? to_string(root->right->val) : "null";

            if(root->left)
                q.push(root->left);

            if(root->right)
                q.push(root->right);
        }

        result += "]";
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data.substr(1, data.length() - 1));
        string item;
        vector<string> elements;
        queue<TreeNode*> q;
        while(getline(ss, item, ','))
            elements.push_back(item);

        int len = elements.size();
        if(len == 0)
            return NULL;

        TreeNode* root = new TreeNode(atoi(elements[0].c_str()));
        q.push(root);
        for(int i = 0; i < len / 2; i++) {
            TreeNode* left = elements[2 * i + 1] == "null" ? NULL : new TreeNode(atoi(elements[2 * i + 1].c_str()));
            TreeNode* right = elements[2 * i + 2] == "null" ? NULL : new TreeNode(atoi(elements[2 * i + 2].c_str()));
            if(left)
                q.push(left);
            if(right)
                q.push(right);

            TreeNode* node = q.front();
            q.pop();
            node->left = left;
            node->right = right;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));