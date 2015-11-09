#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 *
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 *
 *  1         3     3      2      1
 *   \       /     /      / \      \
 *    3     2     1      1   3      2
 *   /     /       \                 \
 *  2     1         2                 3
 *
 *  表达式: f(i) = f(0) * f(i - 1) + f(1) * f(i - 2) + ... + f(i - 1) * f(0)
 *
 * */

class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1, 0);

        f[0] = 1;
        f[1] = 1;
        for(int i = 2; i <=n; i++) {
            for(int k = 0; k < i; i++) {
                f[i] += f[k] * f[i - 1 - k];
            }
        }
        return f[n];
    }
};
