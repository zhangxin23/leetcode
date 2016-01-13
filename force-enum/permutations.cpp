#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 * */

class Solution {
public:
    vector<vector<int> > permutation(vector<int> &num) {
        sort(num.begin(), num.end());

        vector<int> path;
        vector<vector<int> > result;
        dfs(num, path, result);
        return result;
    }

private:
    void dfs(vector<int> &num, vector<int> &path, vector<vector<int> > &result) {
        if(path.size() == num.size()) {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < num.size(); i++) {
            vector<int>::iterator it = find(path.begin(), path.end(), num[i]);

            if(it == path.end()) {
                path.push_back(num[i]);
                dfs(num, path, result);
                path.pop_back();
            }
        }
    }
};