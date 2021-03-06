#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 * Note:
 *  • Elements in a quadruplet (a,b,c,d) must be in non-descending order.(ie,a≤b≤c≤d)
 *  • The solution set must not contain duplicate quadruplets.
 * For example, given array S={1, 0, -1, 0, -2, 2}, and target = 0.
 * A solution set is:
 *  (-1, 0, 0, 1)
 *  (-2, -1, 1, 2)
 *  (-2, 0, 0, 2)
 * */

class Solution {
public:
    vector<vector<int>> fourSum_final(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        for(int first = 0; first < n - 3; first++) {
            for(int second = first + 1; second < n - 2; second++) {
                int third = second + 1;
                int fourth = n - 1;
                while(third < fourth) {
                    int sum = nums[first] + nums[second] + nums[third] + nums[fourth];
                    if(sum == target) {
                        result.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                        third++;
                        fourth--;
                    } else if(sum < target) {
                        third++;
                    } else {
                        fourth--;
                    }
                }
            }
        }

        sort(result.begin(), result.end());
        vector<vector<int> >::iterator unique_end = unique(result.begin(), result.end());
        result.erase(unique_end, result.end());
        return result;
    }

    vector<vector<int> > fourSum(vector<int>& num, int target) {
        vector<vector<int> > result;
        if(num.size() < 4)
            return result;
        sort(num.begin(), num.end());

        auto last = num.end();
        for(auto a = num.begin(); a < last - 3; a++) {
            for(auto b = a + 1; b < last - 2; b++) {
                auto c = b + 1;
                auto d = last - 1;
                while(c < d) {
                    if(*a + *b + *c + *d < target)
                        c++;
                    else if(*a + *b + *c + *d > target)
                        d--;
                    else {
                        result.push_back({*a, *b, *c, *d});
                        c++;
                        d--;
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        vector<vector<int> >::iterator unique_end = unique(result.begin(), result.end());
        result.erase(unique_end, result.end());
        return result;
    }
};
