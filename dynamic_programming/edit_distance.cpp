#include <iostream>
#include <vector>

using namespace std;

/**
 * Given two words word1 and word2,
 * find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 *
 * You have the following 3 operations permitted on a word:
 *
 *   a) Insert a character
 *   b) Delete a character
 *   c) Replace a character
 *
 * 状态方程：f[i][j]表示word1[0...i]和word2[0...j]之间变换步数
 *
 * word1[i - 1] == word2[j - 1]     f[i][j] = f[i - 1][j - 1]
 * word1[i - 1] != word2[j - 1]
 *      delete                      f[i][j] = f[i - 1][j] + 1
 *      insert                      f[i][j] = f[i][j - 1] + 1
 *      replace                     f[i][j] = f[i - 1][j - 1] + 1
 *
 * */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int> > f(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i <= n; i++) {
            f[i][0] = i;
        }

        for(int j  = 0; j <= m; j++) {
            f[0][j] = j;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = min(min(f[i - 1][j - 1], f[i - 1][j]), f[i][j - 1]) + 1;
                }
            }
        }

        return f[n][m];
    }
};