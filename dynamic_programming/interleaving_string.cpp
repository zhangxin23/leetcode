#include <iostream>
#include <vector>

using namespace std;

/**
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 *
 * 状态方程：table[i][j]表示s3[0...i+j]是s1[0...i]和s2[0...j]的interleaving
 *
 * s1[i - 1] == s3[i + j - 1]       table[i][j] = table[i - 1][j]
 * s2[j - 1] == s3[i + j - 1]       table[i][j] = table[i][j - 1]
 *
 * */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<bool> > table(n + 1, vector<bool>(m + 1, false));

        for(int i = 1; i <= n ; i++) {
            table[i][0] = s1[i - 1] == s3[i - 1] || table[i - 1][0];
        }

        for(int j = 1; j <= m; j++) {
            table[0][j] = s2[j - 1] == s3[j - 1] || table[0][j - 1];
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i - 1] == s3[i + j - 1])
                    table[i][j] = table[i - 1][j];
                else if(s2[j - 1] == s3[i + j - 1])
                    table[i][j] = table[i][j - 1];
            }
        }

        return table[n][m];
    }
};