#include <iostream>
#include <vector>

using namespace std;

/**
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 * */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if(rowIndex == 0)
            return result;

        result.push_back(1);

        for(int i = 1; i < rowIndex; i++) {
            for(int j = i - 1; j > 0; j--) {
                result[j] = result[j - 1] + result[j];
            }
            result.push_back(1);
        }

        return result;
    }
};