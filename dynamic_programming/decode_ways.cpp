#include <iostream>

using namespace std;

/**
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 *   'A' -> 1
 *   'B' -> 2
 *   ...
 *   'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 * */

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;

        int prev = 0;
        int cur = 1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 0)
                cur = 0;

            if(i < 1 || !(s[i] == '1' || (s[i - 1] == '2' && s[i] <= 6))) {
                prev = 0;
            }

            int tmp = cur;
            cur += prev;
            prev = tmp;
        }

        return cur;
    }
};