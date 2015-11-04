#include <iostream>

/**
 *Validate if a given string is numeric.
 *Some examples:
 *  "0" => true
 *  " 0.1 " => true
 *  "abc" => false
 *  "1 a" => false
 *  "2e10" => true
 *Note: It is intended for the problem statement to be ambiguous.
 *      You should gather all requirements up front before implementing one.
 * */

class Solution {
    public:
        void scanDigits(char **str) {
            while(**str != '\0' && **str >= '0' && **str <= '9')
                ++(*str);
        }

        bool isExponential(char **str) {
            if(**str != 'e' && **str != 'E')
                return false;

            ++(*str);

            if(**str == '+' || **str == '-')
                ++(*str);

            if(**str == '\0')
                return false;

            scanDigits(str);

            return (**str == '\0') ? true : false;
        }

        bool isNumeric(char *str) {
            if(str == NULL)
                return false;

            while(*str == ' ')
                str++;

            char *pend = str + strlen(str) - 1;
            while(*pend == ' ')
                pend--;
            *(++pend) = '\0';

            if(*str == '+' || *str == '-')
                ++str;

            if(*str == '\0')
                return false;

            bool numeric = true;

            scanDigits(&str);
            if(*str != '\0') {
                if(*str == '.') {
                    ++str;
                    scanDigits(&str);
                    if(*str == 'e' || *str == 'E')
                        numeric = isExponential(&str);
                } else if(*str == 'e' || *str == 'E') {
                    numeric = isExponential(&str);
                } else {
                    numeric = false;
                }
            }

            return numeric && *str == '\0';
        }
};
