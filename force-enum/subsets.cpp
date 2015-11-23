#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Given a set of distinct integers, S, return all possible subsets.
 *
 * Note:
 *
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,3], a solution is:
 *
 *[
 * [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 *]
 * */

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &input) {
        sort(input.begin(), input.end());
        vector<vector<int> > result;
        vector<int> path;
        subsets_core(input, path, 0, result);
        return result;
    }

private:
    void subsets_core(const vector<int> &input, vector<int> &path, int step, vector<vector<int> > &result) {
        if(step == input.size()) {
            result.push_back(path);
            return;
        }

        subsets_core(input, path, step + 1, result);
        path.push_back(input[step]);
        subsets_core(input, path, step + 1, result);
        path.pop_back();
    }
};
