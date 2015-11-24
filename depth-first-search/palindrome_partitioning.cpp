#include <iostream>
#include <vector>

using namespace std;


/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return
 *
 * [
 *   ["aa","b"],
 *   ["a","a","b"]
 * ]
 * */

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > result;
        vector<string> path;
        dfs(s, path, result, 0, 1);
        return result;
    }

private:
    void dfs(string &s, vector<string> &path, vector<vector<string> > &result, int prev, int start) {
        if(start == s.size()) {
            if(isPalindrome(s, prev, start - 1)) {
                path.push_back(s.substr(prev, start - prev));
                result.push_back(path);
                path.pop_back();
            }
        }

        dfs(s, path, result, prev, start + 1);
        if(isPalindrome(s, prev, start - 1)) {
            path.push_back(s.substr(prev, start - prev));
            dfs(s, path, result, start, start + 1);
            path.pop_back();
        }
    }

    bool isPalindrome(const string &s, int start, int end) {
        while(start < end && s[start] == s[end]) {
            start++;
            end--;
        }
        return start >= end;
    }
};