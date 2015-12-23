#include <iostream>
#include <vector>

using namespace std;

/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 * */

class Solution {
public:
    vector<string> generateParentheses(int n) {
        vector<string> result;
        if(n > 0)
            dfs(n, 0, 0, "", result);
        return result;
    }

private:
    void dfs(int n, int left, int right, string s, vector<string> &result) {
        if(left == n) {
            s.append(n - right, ')');
            result.push_back(s);
        }

        dfs(n, left + 1, right, s + "(", result);
        if(left > right)
            dfs(n, left, right + 1, s + ")", result);
    }
};