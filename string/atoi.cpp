#include <stddef.h>
#include <limits.h>
#include <ctype.h>

/**
 * Implement  to convert a string to an integer.
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 *
 * Requirements for atoi:
 *
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
 * Then, starting from this character,takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid integral number,
 * or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is per-formed.
 *
 * If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values,
 * INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 * */

class Solution {
public:
    int atoi(const char* str) {
        if(str == NULL)
            return 0;

        while(isspace(*str))
            str++;

        int sign = 1;
        if(*str == '+') {
            str++;
        } else if(*str == '-') {
            sign = -1;
            str++;
        }

        long long result = 0;
        while(*str) {
            if(*str < '0' || *str > 9)
                return result;

            result = result * 10 + (*str - '0');
            if(sign == 1 && result > INT_MAX)
                return INT_MAX;
            else if(sign == -1 && -result < INT_MIN)
                return INT_MIN;

            str++;
        }

        if(sign == -1)
            return -result;
        else if(sign == 1)
            return result;
    }
};
