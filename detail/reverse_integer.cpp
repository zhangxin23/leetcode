#include <iostream>

using namespace std;

/**
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 * */

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)
            return INT_MAX;

        bool flag = true;
        if(x < 0) {
            x = -x;
            flag = false;
        }

        long ret = 0;
        while(x != 0) {
            ret = ret * 10 + x % 10;
            x /= 10;

            if(flag && ret > INT_MAX || !flag && -ret < INT_MIN)
                return flag ? INT_MAX : INT_MIN;
        }

        return flag ? (int)ret : (int)(-ret);
    }
};
