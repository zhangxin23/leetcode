#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 * */

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix == NULL || matrix.size() == 0)
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height;
        int max_area = 0;

        for(int i = 0; i< n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1')
                    height[j]++;
                else if(matrix[i][j] == '0')
                    height[j] = 0;
            }
            max_area = max(max_area, maxHistogram(height));
        }

        return max_area;
    }

private:
    int maxHistogram(vector<int> &height) {
        int area = 0;
        stack<int> stk;
        for(int i = 0; i < height.size(); ) {
            if(stk.empty() || height[stk.top()] < height[i]) {
                stk.push(i++);
            } else {
                int idx = stk.top();
                stk.pop();
                area = max(area, (stk.empty() ? i : i - stk.top() - 1) * height[idx]);
            }
        }
        return area;
    }
};
