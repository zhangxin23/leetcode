#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return the empty string "".
 *
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 * */

class Solution {
public:
    string minWindow(string s, string t) {
        int appeared[256] = {0};
        int expected[256] = {0};

        for(int i = 0; i < t.size(); i++) {
            expected[t[i]]++;
        }

        int start = 0;
        int appeare_count = 0;
        int minStart = 0;
        int minWidth = INT32_MAX;
        for(int end = 0; end < s.size(); end++) {
            if(expected[s[end]] > 0) {
                appeared[s[end]]++;
                if(appeared[s[end]] <= expected[s[end]]) {
                    appeare_count++;
                }
            }

            if(appeare_count >= t.size() && start < 256) {
                while((start < 256) && ((appeared[s[start]] > expected[s[start]]) || expected[s[start]] == 0)) {
                    appeared[s[start]]--;
                    start++;
                }

                if(minWidth > (end - start - 1)) {
                    minWidth = end - start - 1;
                    minStart = start;
                }
            }
        }

        if(minWidth == INT32_MAX || start >= 256)
            return "";
        else
            return s.substr(minStart, minWidth);
    }
};
