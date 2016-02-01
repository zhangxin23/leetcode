#include <iostream>
#include <queue>
#include <string.h>
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

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

//
// Created by zhangxin on 16/1/31.
//

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        queue<TreeNode*> q;
        TreeNode* node = NULL;
        if(root == NULL)
            return result;

        q.push(root);
        while(!q.empty()) {
            node = q.front();
            q.pop();

            if(node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }

        if(result == "")
            return result;
        return result.substr(0, result.length() -1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> elements = split(data, ",");
        int len = elements.size();
        if(len == 0)
            return NULL;

        vector<int> nums(len, 0);
        vector<TreeNode*> nodes(len, NULL);

        for(int i = 0, null_count = 0; i < elements.size(); i++) {
            if(elements[i] == "null") {
                nums[i] = null_count;
                null_count++;
            } else {
                nums[i] = null_count;
                nodes[i] = new TreeNode(atoi(elements[i].c_str()));
            }
        }

        for(int i = 0; i < len; i++) {
            if(nodes[i] == NULL)
                continue;

            nodes[i]->left = nodes[2 * (i - nums[i]) + 1];
            nodes[i]->right = nodes[2 * (i - nums[i]) + 2];
        }

        return nodes[0];
    }

private:
    vector<string> split(string& str, const char* c) {
        char *cstr, *p;
        vector<string> result;
        cstr = new char[str.size() + 1];
        strcpy(cstr, str.c_str());
        p = strtok(cstr, c);
        while(p != NULL) {
            result.push_back(p);
            p = strtok(NULL, c);
        }
        return result;
    }
};
