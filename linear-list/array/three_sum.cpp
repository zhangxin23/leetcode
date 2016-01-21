#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Given an array S of n integers, are there elements a,b,c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * Note:
 *      Elements in a triplet(a,b,c) must be in non-descending order. (ie,a≤b≤c)
 *      The solution set must not contain duplicate triplets.
 *
 * For example, given array S={-1, 0, 1, 2, -1, -4}.
 * A solution set is:
 *      (-1, 0, 1)
 *      (-1, -1, 2)
 * */

class Solution {
    public:

        vector<vector<int> > threeSumFinal(vector<int> &nums) {
            vector<vector<int> > result;
            int size = nums.size();
            if(size < 3)
                return result;

            for(int first = 0; first < size - 2; first++) {
                int second = first + 1;
                int third = size - 1;

                while(second < third) {
                    int sum = nums[first] + nums[second] + nums[third];
                    if(sum == 0) {
                        result.push_back({nums[first], nums[second], nums[third]});
                    } else if(sum > 0) {
                        third--;
                    } else {
                        second++;
                    }
                }
            }

            return result;
        }

        vector<vector<int> > threeSum(vector<int> & num) {
            vector<vector<int> > result;
            if(num.size() < 3)
                return result;
            sort(num.begin(), num.end());
            const int target = 0;

            auto last = num.end();
            for(auto i = num.begin(); i < last - 2; i++) {
                auto j = i + 1;
                if(i > num.begin() && *i == *(i -1))
                    continue;
                auto k = last - 1;
                while(j < k) {
                    if(*i + *j + *k < target) {
                        ++j;
                        while(*j == *(j - 1) && j < k)
                            ++j;
                    } else if(*i + *j + *k > target) {
                        --k;
                        while(*k == *(k + 1) && j < k)
                            --k;
                    } else {
                        result.push_back({*i, *j, *k});
                        ++j;
                        --k;
                        while(*j == *(j -1) && *k == *(k + 1) && j < k)
                            ++j;
                    }
                }
            }
            return result;
        }


        vector<vector<int> > threeSum_1(vector<int>& num, int target) {
            vector<vector<int> > result;
            if(num.size() < 3)
                return result;
            sort(num.begin(), num.end());

            auto last = num.end();
            for(auto a = num.begin(); a != last - 2; a++) {
                auto b = a + 1;
                auto c = last - 1;

                while(b < c) {
                    const int sum = *a + *b + *c;
                    if(sum < target)
                        b++;
                    else if(sum > target)
                        c--;
                    else {
                        result.push_back({*a, *b, *c});
                        b++;
                        c--;
                    }
                }
            }

            sort(result.begin(), result.end());
            result.erase(unique(result.begin(), result.end(), result.end()));
            return result;
        }
};
