#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Given an array of integers and an integer k,
 * find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 * */

//
// Created by zhangxin on 16-2-1.
//

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        for(int i = 0; i < nums.size(); i++) {
            if(table.find(nums[i]) != table.end()) {
                if(i - table[nums[i]] <= k)
                    return true;
            }
            table[nums[i]] = i;
        }
        return false;
    }
};
