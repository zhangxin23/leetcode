#include <iostream>
#include <vector>

using namespace std;

/**
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 * */

class Solution {
public:
    int nQueens(int n) {
        int count;
        vector<int> C;
        dfs(C, count, 0);
        return count;
    }
private:
    void dfs(vector<int> &C, int &count, int row) {
        int n = C.size();
        if(row == n) {
            count++;
            return;
        }

        for(int col = 0; col < n; col++) {
            if(isOK(C, row, col)) {
                C[row] = col;
                dfs(C, count, row + 1);
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