#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * Given an array of integers,
 * find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
 * */

//
// Created by zhangxin on 16-2-1.
//

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, int> table;
        for(int i = 0, j = 0; i < nums.size(); i++) {
            if(i - j > k  && table[nums[j]] == j)
                table.erase(nums[j++]);

            map<int, int>::iterator lower = table.lower_bound(nums[i] - t);
            if(lower != table.end() && abs(lower->first - nums[i]) <= t)
                return true;

            table[nums[i]] = i;
        }
        return false;
    }
};
