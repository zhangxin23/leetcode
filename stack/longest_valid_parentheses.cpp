#include <iostream>
#include <stack>

using namespace std;

/**
 *Given a string containing just the characters '(' and ')',
 *find the length of the longest valid (wellformed) parentheses substring.
 *For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 * */

class Solution {
    public:
        int longestValidParentheses(string s) {
            int max_len = 0, last = -1;
            stack<int> lefts;

            for(int i = 0; i< s.size(); i++) {
                if(s[i] == '(') {
                    lefts.push(i);
                } else {
                    if(lefts.empty()) {
                        last = i;
                    } else {
                        lefts.pop();
                        if(lefts.empty()) {
                            max_len = max(max_len, i - last);
                        } else {
                            max_len = max(max_len, i - lefts.top());
                        }
                    }
                }
            }
            return max_len;
        }
};
