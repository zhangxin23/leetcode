#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Given a collection of integers that might contain duplicates, S, return all possible subsets.
 *
 * Note:
 *
 *  Elements in a subset must be in non-descending order.
 *  The solution set must not contain duplicate subsets.
 *
 *
 * For example,
 * If S = [1,2,2], a solution is:
 *
 *   [
 *     [2],
 *     [1],
 *     [1,2,2],
 *     [2,2],
 *     [1,2],
 *     []
 *   ]
 * */

class Solution {
public:
    vector<vector<int> > subsets(vector<int> input) {
        sort(input.begin(), input.end());
        vector<vector<int> > result;
        vector<int> path;
        subsets_core(input, path, input.begin(), result);
        return result;
    }

private:
    void subsets_core(vector<int> &input, vector<int> &path, vector<int>::iterator start,
                      vector<vector<int> > &result) {
        result.push_back(path);

        for(vector<int>::iterator i = start; i != input.end(); i++) {
            if(i != start && *i == *(i - 1))
                continue;

            path.push_back(*i);
            subsets_core(input, path, i + 1, result);
            path.pop_back();
        }
    }
};