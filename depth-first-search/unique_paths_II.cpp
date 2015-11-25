#include <iostream>
#include <vector>

using namespace std;

/**
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *  [0,0,0],
 *  [0,1,0],
 *  [0,0,0]
 * ]
 * The total number of unique paths is 2.
 * */

class Solution {
public:
    int uniquePaths(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int> > board(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 1)
                board[i][0] = 0;
            else
                board[i][0] = 1;
        }

        for(int i = 0; i < n; i++) {
            if(grid[0][i] == 1)
                board[0][i] = 0;
            else
                board[0][i] = 1;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(grid[i][j] == 1) {
                    board[i][j] = 0;
                } else {
                    board[i][j] = board[i - 1][j] + board[i][j - 1];
                }
            }
        }

        return board[m - 1][n - 1];
    }
};