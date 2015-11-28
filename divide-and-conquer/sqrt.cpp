#include <iostream>

using namespace std;

/**
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 * */

class Solution {
public:
    int sqrt(int x) {
        int left =  0;
        int right = x / 2;
        int last_mid = 0;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(x / mid > mid) {
                left = mid + 1;
                last_mid = mid;
            } else if(x / mid < mid) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return last_mid;
    }
};