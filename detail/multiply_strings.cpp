#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 *
 * */

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> num1_vec(num1.size());
        vector<int> num2_vec(num2.size());
        vector<int> ret_vec(num1.size() + num2.size());

        for(int i = 0; i < num1.length(); i++) {
            num1_vec[i] = num1[i] - '0';
        }

        for(int j = 0; j < num2.length(); j++) {
            num2_vec[j] = num2[j] - '0';
        }

        for(int i = 0; i < num1_vec.size(); i++) {
            for(int j = 0; j < num2_vec.size(); j++) {
                ret_vec[i + j] += num1_vec[i] * num2_vec[j];
                ret_vec[i + j + 1] = ret_vec[i + j] / 10;
                ret_vec[i + j] %= 10;
            }
        }

        string ret_str;
        for(int i = 0; i < ret_vec.size(); i++) {
            ret_str += (ret_vec[i] + '0');
        }

        int start = 0;
        for(int i = 0; i < ret_str.length(); i++) {
            if(ret_str[i] != '0') {
                start = i;
                break;
            }
        }

        return ret_str.substr(start, ret_str.length() - start);
    }
};
