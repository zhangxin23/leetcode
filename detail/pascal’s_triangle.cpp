#include <iostream>
#include <vector>

using namespace std;

/**
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 *   [
 *        [1],
 *       [1,1],
 *      [1,2,1],
 *     [1,3,3,1],
 *    [1,4,6,4,1]
 *   ]
 * */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > result;
        result.push_back(vector<int>(1, 1));

        for(int i = 2; i <= numRows; i++) {
            vector<int> cur(i, 1);
            vector<int> prev = result[i - 1];
            for(int j = 1; j < i - 1; j++) {
                cur[j] = prev[j - 1] + prev[j];
            }
            result.push_back(cur);
        }

        return result;
    }
};
