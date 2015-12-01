#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 *
 * Below is one possible representation of s1 = "great":
 *
 *       great
 *      /    \
 *     gr    eat
 *    / \    /  \
 *   g   r  e   at
 *              / \
 *             a   t
 * To scramble the string, we may choose any non-leaf node and swap its two children.
 *
 * For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
 *
 *       rgeat
 *      /    \
 *     rg    eat
 *    / \    /  \
 *   r   g  e   at
 *              / \
 *             a   t
 * We say that "rgeat" is a scrambled string of "great".
 *
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
 *
 *       rgtae
 *      /    \
 *     rg    tae
 *    / \    /  \
 *   r   g  ta  e
 *          / \
 *         t   a
 * We say that "rgtae" is a scrambled string of "great".
 *
 * Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
 * */

class Solution {
public:
    bool isScramble_dp(string s1, string s2) {
        int n = s1.length();
        if(s2.length() != n)
            return false;

        vector<vector<vector<bool> > > f(n + 1, vector<vector<bool> > (n, vector<boo>(n, false)));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                f[1][i][j] = s1[i] == s2[i];
            }
        }

        for(int m = 1; m < n; m++) {
            for(int i = 0; i + m < n; i++) {
                for(int j = 0; j + m < n; j++) {
                    for(int k = 0; k < n; k++) {
                        if((f[k][i][j] && f[m - k][i + k][j + k]) ||
                           (f[k][i][j + m - k] && f[m - k][i + k][j])) {
                            f[m][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }

        return f[n][0][0];
    }


    bool isScramble_recur(string s1, string s2) {
        return isScramble_core(s1.begin(), s1.end(), s2.begin());
    }

private:
    typedef string::iterator StrIte;
    bool isScramble_core(StrIte first1, StrIte last1, StrIte first2) {
        int length = distance(first1, last1);
        StrIte last2 = next(first2, length);

        if(length == 1)
            return *first1 == *first2;

        for(int i = 1; i < length; i++) {
            if((isScramble_core(first1, first1 + i, first2) && isScramble_core(first1 + i, last1, first2 + i)) ||
               (isScramble_core(first1, first1 + i, last2 - i) && isScramble_core(first1 + i, last1, first2)))
                return true;
        }
        return false;
    }
};