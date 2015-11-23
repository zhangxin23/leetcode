#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 * */

class Solution {
public:
    vector<string> letterCombine(const string &digits) {
        vector<string> result;
        dfs(digits, 0, "", result);
        return result;
    }
private:
    const vector<string> keyboard = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(const string &digits, int cur, string path, vector<string> &result) {
        if(path.length() == digits.length()) {
            result.push_back(path);
            return;
        }

        for(char item: keyboard[digits[cur] - '0']) {
            dfs(digits, cur + 1, path + item, result);
        }
    }
};