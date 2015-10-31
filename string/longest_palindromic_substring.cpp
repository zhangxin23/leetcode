/**
 *Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000,
 *and there exists one unique longest palindromic substring.
 *
 *状态转移方程：
 *          |-- true                                i == j
 *          |
 * f(i, j) =|-- s[i] = s[j]                         j = i + 1
 *          |
 *          |-- s[i] = s[j] and f(i + 1, j - 1)     j > i + 1
 *
 * */

class Solution {
    public:
        string longestPalindrome(string s) {
            const int n = s.size();
            bool f[n][n];
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++)
                    f[i][j] = false;
            }

            int max_len = 1, start = 0;

            for(int i = 0; i < n; i++) {
                f[i][i] = true;
                for(int j = 0; j < i; j++) {
                    f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
                    if(f[j][i] && max_len < (i - j + 1)) {
                        max_len = i - j + 1;
                        start = j;
                    }
                }
            }
            return s.substr(start, max_len);
        }
};
