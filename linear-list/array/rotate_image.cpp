#include <iostream>
#include <vector>

using namespace std;

/**
 * You are given an n × n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up: Could you do this in-place?
 * */

class Solution {
    public:
        void rotate(vector<vector<int> >& matrix) {
            int n = matrix.size();

            //副对角线翻转
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++)
                    swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
            }

            //中线翻转
            for(int i = 0; i < n/2; i++) {
                for(int j = 0; j < n; j++)
                    swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
};
