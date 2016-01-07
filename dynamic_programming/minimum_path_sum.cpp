#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a m x n grid filled with non-negative numbers,
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * 状态方程: result[i][j]表示到(i, j)的最小路径和.
 *
 * result[i][j] = min(result[i - 1][j], result[i][j - 1]) + grid[i][j]
 *
 * */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> result(n, vector<int>(m, 0));
        result[0][0] = grid[0][0];
        for(int i = 1; i < n; i++) {
            result[i][0] = result[i - 1][0] + grid[i - 1][0];
        }

        for(int j = 1; j < m; j++) {
            result[0][j] = result[0][j - 1] + grid[0][j - 1];
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                result[i][j] = min(result[i][j - 1], result[i - 1][j]) + grid[i][j];
            }
        }

        return result[n - 1][m - 1];
    }
};