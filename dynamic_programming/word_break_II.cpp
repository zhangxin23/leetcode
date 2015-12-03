#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Given a string s and a dictionary of words dict,
 * add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 * */

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
        vector<string> path;
        vector<string> result;
        dfs(s, wordDict, 0, path, result);
        return result;
    }

private:
    void dfs(string s, unordered_set<string> &wordDict, int start,
             vector<string> &path, vector<string> &result) {
        if(start == s.length()) {
            string tmp;
            for(string item: path)
                tmp.append(" ").append(item);
            result.push_back(tmp);
            return;
        }

        for(int i = start; i < s.length(); i++) {
            if(wordDict.find(s.substr(start, i - start + 1)) != wordDict.end()) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(s, wordDict, i, path, result);
                path.pop_back();
            }
        }
    }
};
