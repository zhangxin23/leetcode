#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Given n non-negative integers representing the histogram’s bar height where the width of each bar is 1,
 * find the area of largest rectangle in the histogram.
 * For example, Given height = [2,1,5,6,2,3], return 10.
 * */

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int maxArea = 0;
        stack<int> stk;
        height.push_back(0);
        for(int i = 0; i < height.size();) {
            if(stk.empty() || height[i] > height[stk.top()]) {
                stk.push(i++);
            } else {
                int index = stk.top();
                stk.pop();
                maxArea = max(maxArea, height[index] * (stk.empty() ? i : (i - stk.top() - 1)));
            }
        }
        return maxArea;
    }
};
