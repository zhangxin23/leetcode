#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 * For example, Given [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], return 6.
 * */

class Solution {
public:
    int trap_final(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        int sum = 0;

        for(int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i - 1], height[i - 1]);
            right_max[n - i - 1] = max(right_max[n - i], height[n - i]);
        }

        for(int i = 0; i < n; i++) {
            int h = min(left_max[i], right_max[i]);
            if(h > height[i])
                sum += h - height[i];
        }

        return sum;
    }

    int trap(int A[], int n) {
        int *max_left = new int[n];
        int *max_right = new int[n];

        memset(max_left, 0, sizeof(int) * n);
        memset(max_right, 0, sizeof(int) * n);

        for(int i = 1; i < n; i++) {
            max_left[i] = max(max_left[i - 1], A[i - 1]);
            max_right[n - i - 1] = max(max_right[n - i], A[n - i]);
        }

        int sum = 0;
        for(int i = 0; i < n; i++) {
            int height = min(max_left[i], max_right[i]);
            if(height > A[i]) {
                sum += height - A[i];
            }
        }

        delete[] max_left;
        delete[] max_right;
        return sum;
    }
};
