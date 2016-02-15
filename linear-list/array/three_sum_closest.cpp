#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

/**
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * For example, given array S={-1, 2, 1, -4}, and target = 1.
 * The sum that is closest to the target is 2.(-1 + 2 + 1 = 2).
 * */

class Solution {
public:
    int threeSumClosest_final(vector<int>& nums, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int first = 0; first < n - 2; first++) {
            int second = first + 1;
            int third = n - 1;

            while(second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                int gap = abs(sum - target);
                if(gap < min_gap) {
                    min_gap = gap;
                    result = sum;
                }

                if(sum > target) {
                    third--;
                } else {
                    second++;
                }
            }
        }

        return result;
    }

    int threeSumClosest(vector<int>& num, int target) {
        int result = 0;
        int min_gap = INT_MAX;
        sort(num.begin(), num.end());

        auto last = num.end();
        for(auto a = num.begin(); a != last - 2; a++) {
            auto b = a + 1;
            auto c = last - 1;

            while(b < c) {
                const int sum = *a + *b + *c;
                const int gap = abs(sum - target);
                if(min_gap > gap) {
                    result = sum;
                    min_gap = gap;
                }

                if(sum < target)
                    b++;
                else
                    c--;
            }
        }
        return result;
    }
};
