#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 *   [
 *    [ 1, 2, 3 ],
 *    [ 4, 5, 6 ],
 *    [ 7, 8, 9 ]
 *   ]
 * You should return [1,2,3,6,9,8,7,4,5].
 * */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        if(matrix == NULL || matrix.size() <= 0 || matrix[0].size() <= 0)
            return result;

        int x_begin = 0, x_end = matrix[0].size() - 1;
        int y_begin = 0, y_end = matrix.size() - 1;

        while(true) {
            for(int i = x_begin; i <= x_end; i++)
                result.push_back(matrix[y_begin][i]);
            if(++y_begin > y_end)
                break;

            for(int j = y_begin; j <= y_end; j++)
                result.push_back(matrix[j][x_end]);
            if(--x_end < x_begin)
                break;

            for(int i = x_end; i >= x_begin; i--)
                result.push_back(matrix[y_end][i]);
            if(--y_end < y_begin)
                break;

            for(int j = y_end; j >= y_begin; j--)
                result.push_back(matrix[j][x_begin]);
            if(++x_begin > x_end)
                break;
        }

        return result;
    }
};
