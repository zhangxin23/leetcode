#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Given a string s and a dictionary of words dict,
 * determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
 * */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> f(s.length() + 1, false);
        f[0] = true;

        for(int i = 1; i <= s.length(); i++) {
            for(int j = i - 1; j != 0; j--) {
                if(f[j] && wordDict.find(s.substr(j, i - j + 1)) != wordDict.end()) {
                    f[i] = true;
                    break;
                }
            }
        }

        return f[s.length()];
    }
};