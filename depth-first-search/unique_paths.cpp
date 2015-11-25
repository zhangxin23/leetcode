#include <iostream>
#include <vector>

using namespace std;

/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time.
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 * */

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < 0 || n < 0)
            return 0;

        if(m == 1 || n == 1)
            return 1;

        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }

    int uniquePaths_dp(int m, int n) {
        vector<vector<int> > board(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            board[i][0] = 1;
        }
        for(int i = 0; i < n; i++) {
            board[0][i] = 1;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                board[i][j] = board[i - 1][j] + board[i][j - 1];
            }
        }

        return board[m - 1][n - 1];
    }
};