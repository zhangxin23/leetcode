#include <iostream>
#include <vector>

using namespace std;

/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has properties:
 *
 * 1) Integers in each row are sorted from left to right.
 * 2) The first integer of each row is greater than the last integer of the previous row.
 *
 * For example, consider the following matrix:
 *
 *   [
 *     [1,   3,  5,  7],
 *     [10, 11, 16, 20],
 *     [23, 30, 34, 50]
 *   ]
 * Given target = 3, return true.
 * */

class Solution {
public:
    bool searchMatrix(vector<vector<int> > matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0, end = row * col;

        while(start != end) {
            int mid = start + (end - start) / 2;
            int value = matrix[mid / col][mid % col];

            if(value == target)
                return true;
            else if (value < target)
                start = mid + 1;
            else
                end = mid;
        }

        return false;
    }
};