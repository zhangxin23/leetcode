#include <iostream>

using namespace std;

/**
 * Divide two integers without using multiplication, division and mod operator.
 *
 * If it is overflow, return MAX_INT.
 * */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0)
            return 0;

        long long a = dividend >= 0 ? dividend : -(long long)dividend;
        long long b = divisor >= 0 ? divisor : -(long long)divisor;

        long long result = 0;
        while(a >= b) {
            long long c = b;
            for(int i = 0; a >= c; ++i, c <<= 1) {
                a -= c;
                result += 1 << i;
            }
        }

        return ((dividend ^ divisor) >> 31) ? (-result) : (result);
    }
};
