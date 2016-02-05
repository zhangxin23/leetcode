#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 * */

//
// Created by zhangxin on 16-2-1.
//

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> table;
        for(int i = 0; i < nums.size(); i++) {
            if(table.find(nums[i]) != table.end()) {
                return true;
            } else {
                table[nums[i]] = i;
            }
        }
        return false;
    }
};