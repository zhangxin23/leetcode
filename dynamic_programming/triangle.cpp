#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a triangle, find the minimum path sum from top to bottom.
 * Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *   [
 *        [2],
 *       [3,4],
 *      [6,5,7],
 *     [4,1,8,3]
 *   ]
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 * 状态方程: f[j][j]表示从(i, j)出发,路径的最小和.
 *      f[i][j] = min(f[i + 1][j], f[i + 1][j + 1]) + f[i][j];
 * */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = triangle.size() - 2; i != 0; i--) {
            for(int j = 0; j < i + 1; j++) {
                triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return triangle[0][0];
    }
};