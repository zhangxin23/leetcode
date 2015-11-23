#include <iostream>
#include <vector>

using namespace std;

/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *  [2,4],
 *  [3,4],
 *  [2,3],
 *  [1,2],
 *  [1,3],
 *  [1,4],
 * ]
 * */


class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> path;
        vector<vector<int> > result;
        dfs(n, k, 1, path, result);
        return result;
    }

private:
    void dfs(int n, int k, int start, vector<int> &path, vector<vector<int> > &result) {
        if(path.size() == k) {
            result.push_back(path);
            return;
        }

        for(int i = start; i <= n; i++) {
            path.push_back(i);
            dfs(n, k, start + 1, path, result);
            path.pop_back();
        }
    }
};
