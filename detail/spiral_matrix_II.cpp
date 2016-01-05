#include <iostream>
#include <vector>

using namespace std;

/**
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 *
 * For example,
 * Given n = 3,
 *
 * You should return the following matrix:
 *   [
 *    [ 1, 2, 3 ],
 *    [ 8, 9, 4 ],
 *    [ 7, 6, 5 ]
 *   ]
 * */

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if(n == 0)
            return NULL;

        vector<vector<int> > result(n, vector<int>(n, 0));

        int x_begin = 0, x_end = n - 1;
        int y_begin = 0, y_end = n - 1;
        int num = 1;

        while(true) {
            for(int i = x_begin; i <= x_end; i++)
                result[y_begin][i] = num++;
            if(++y_begin > y_end)
                break;

            for(int j = y_begin; j <= y_end; j++)
                result[j][x_end] = num++;
            if(--x_end < x_begin)
                break;

            for(int i = x_end; i >= x_begin; i--)
                result[y_end][i] = num++;
            if(--y_end < y_begin)
                break;

            for(int j = y_end; j >= y_begin; j--)
                result[j][x_begin] = num++;
            if(++x_begin > x_end)
                break;
        }

        return result;
    }
};