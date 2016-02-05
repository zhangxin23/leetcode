#include <iostream>
#include <vector>

using namespace std;

/**
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
 * Find the two elements that appear only once.
 *
 * For example:
 *
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 *
 * Note:
 * The order of the result is not important. So in the above example, [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 * */

//
// Created by zhangxin on 16-2-3.
//

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int diff = 0;
        for(int i = 0; i < nums.size(); i++) {
            diff ^= nums[i];
        }

        int kth = 0;
        for(int i = 0; i < sizeof(int) * 8; i++) {
            if((diff >> i) & 0x01) {
                kth = i;
                break;
            }
        }

        int start = 0, end = n - 1;
        while(start <= end) {
            if((nums[start] >> kth) & 0x01) {
                swap(nums[start], nums[end]);
                end--;
            } else if(((nums[end] >> kth) & 0x01) == 0x00) {
                swap(nums[start], nums[end]);
                start++;
            } else {
                start++;
                end--;
            }
        }

        int a = 0;
        for(int i = 0; i < start; i++) {
            a ^= nums[i];
        }

        int b = 0;
        for(int i = end + 1; i < n; i++) {
            b ^= nums[i];
        }
        return vector<int>({a, b});
    }
};