#include <iostream>
#include <vector>

using namespace std;

/**
 * Find all possible combinations of k numbers that add up to a number n,
 * given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 *
 * Ensure that numbers within the set are sorted in ascending order.
 *
 * Example 1:
 *
 * Input: k = 3, n = 7
 *
 * Output:
 *
 *  [[1,2,4]]
 *
 * Example 2:
 *
 * Input: k = 3, n = 9
 *
 * Output:
 *
 *  [[1,2,6], [1,3,5], [2,3,4]]
 * */

//
// Created by zhangxin on 16-2-1.
//

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> path;
        dfs(k, n, result, path, 1);
        return result;
    }

    void dfs(int k, int n, vector<vector<int> >& result, vector<int>& path, int start) {
        if(k == 0 && n == 0) {
            result.push_back(path);
            return;
        }

        if(k == 0 || n == 0)
            return;

        for(int i = start; i <= 9; i++) {
            path.push_back(i);
            dfs(k - 1, n - i, result, path, i + 1);
            path.pop_back();
        }
    }
};
