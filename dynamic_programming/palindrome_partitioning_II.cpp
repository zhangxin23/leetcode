#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 *
 * 状态方程: p[i][j]表示s[i...j]是回文,f[i]为区间[i, n-1]之间的最小切数.
 *      p[i][j] = s[i] == s[j] && p[i + 1][j - 1]
 *      f[i] = min{f[j + 1] + 1}, i <= j < n
 *
 * */

class Solution {
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool> > p(n, vector<bool>(n, false));
        vector<int> f(n + 1);

        for(int i = 0; i <= n; i++) {
            f[i] = n - 1 - i;
        }

        for(int i = n - 1; i != 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
                    p[i][j] = true;
                    f[i] = min(f[i], f[j + 1] + 1);
                }
            }
        }

        return f[0];
    }
};
