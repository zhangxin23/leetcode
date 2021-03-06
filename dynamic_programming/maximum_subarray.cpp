#include <iostream>
#include <vector>

using namespace std;

/**
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 * */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int f = 0;
        int result = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            f = max(nums[i] + f, nums[i]);
            result = max(result, f);
        }

        return result;
    }
};