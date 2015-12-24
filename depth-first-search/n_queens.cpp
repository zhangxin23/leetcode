#include <iostream>
#include <vector>

using namespace std;

/**
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 *   [
 *    [".Q..",  // Solution 1
 *     "...Q",
 *     "Q...",
 *     "..Q."],
 *
 *    ["..Q.",  // Solution 2
 *     "Q...",
 *     "...Q",
 *     ".Q.."]
 *   ]
 *
 * */

class Solution {
public:
    vector<vector<string> > nQueens(int n) {
        vector<vector<string> > result;
        vector<int> C(n, -1);
        dfs(C, result, 0);
        return result;
    }
private:
    void dfs(vector<int> &C, vector<vector<string> > &result, int row) {
        int n = C.size();
        if(row == n) {
            vector<string> solution;
            for(int row = 0; row < n; row++) {
                string s(n, '.');
                for(int col = 0; col < n; col++) {
                    if(col == C[row]) {
                        s[col] = 'Q';
                    }
                }
                solution.push_back(s);
            }
            result.push_back(solution);
            return;
        }

        for(int col = 0; col < n; col++) {
            if(isOK(C, row, col)) {
                C[row] = col;
                dfs(C, result, row + 1);
            }
        }
    }

    bool isOK(vector<int>& result, int row, int col) {
        for(int i = 0; i < row; i++) {
            if(col == result[i])
                return false;
            else if(abs(col - result[i]) == abs(i - row))
                return false;
        }
        return true;
    }
};