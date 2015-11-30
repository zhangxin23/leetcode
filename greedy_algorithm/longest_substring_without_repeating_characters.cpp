#include <iostream>

using namespace std;

/**
 * Given a string, find the length of the longest substring without repeating characters.
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
 * For "bbbbb" the longest substring is "b", with the length of 1.
 * */

class Solution {
public:
    int longestLength(const string &s) {
        int table[26] = {-1};
        int start = 0;
        int max_len = 0;

        for(int i = 0; i < s.length(); i++) {
            if(table[s[i] - 'a'] >= start) {
                start = table[s[i] - 'a'] + 1;
                max_len = max(max_len, i - start);
            }

            table[s[i] - 'a'] = i;
        }

        return max(s.length() - start, max_len);
    }
};