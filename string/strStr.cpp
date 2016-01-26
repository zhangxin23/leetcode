#include <iostream>

using namespace std;

/**
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.empty() || needle.empty() || needle.length() > haystack.length())
            return -1;

        int needle_len = needle.length();
        int haystack_len = haystack.length();
        for(int i = 0; i <= haystack_len - needle_len; i++) {
            int j = 0;
            for(; j < needle_len; j++) {
                if(needle[j] != haystack[i + j])
                    break;
            }

            if(j == needle_len - 1)
                return i;
        }

        return -1;
    }
};
