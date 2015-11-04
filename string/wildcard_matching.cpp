#include <stddef.h>

/**
 *Implement wildcard pattern matching with support for '?' and '*'.
 *'?' Matches any single character. '*' Matches any sequence of
 *characters (including the empty sequence).
 *The matching should cover the entire input string (not partial).
 *The function prototype should be:
 *  bool isMatch(const char *s, const char *p)
 *Some examples:
 *  isMatch("aa","a") → false
 *  isMatch("aa","aa") → true
 *  isMatch("aaa","aa") → false
 *  isMatch("aa", "*") → true
 *  isMatch("aa", "a*") → true
 *  isMatch("ab", "?*") → true
 *  isMatch("aab", "c*a*b") → false
 * */

class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            if(s == NULL)
                return p == NULL;

            if(*p == '*') {
                while(*p == '*')
                    p++;
                if(*p == '\0')
                    return true;
                while(*s != '\0' && !isMatch(s, p))
                    s++;

                return *s != '\0';
            } else if(*p == '\0' || *s == '\0') {
                return *p == *s;
            } else if(*p == *s || *p == '?') {
                return isMatch(s++, p++);
            } else {
                return false;
            }
        }

        bool isMatch_iteration(const char *s, const char *p) {
            bool star = false;
            const char *str, *ptr;
            for(str = s, ptr = p; *str; str++, ptr++) {
                switch(*ptr) {
                    case '?':
                        break;
                    case '*':
                        star = true;
                        s = str, p = ptr;
                        while(*p == '*')
                            p++;
                        if(*p == '\0')
                            return true;
                        str = s - 1;
                        ptr = p - 1;
                        break;
                    default:
                        if(*str != *ptr) {
                            if(!star)
                                return false;
                            s++;
                            str = s - 1;
                            ptr = p - 1;
                        }
                }
            }
            while(*ptr == '*')
                ptr++;

            return  *ptr == '\0';
        }
};
