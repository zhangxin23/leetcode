/**
 *Write a function to find the longest common prefix string amongst an array of strings.
 * */

class Solution {
    public:
        string longestCommonPrefix_vertical(vector<string> &strs) {
            if(strs.empty())
                return "";

            for(int i = 0; i < strs[0].size(); i++) {
                for(int j = 1; j < strs.size(); j++) {
                    if(strs[j][i] != strs[0][i])
                        return strs[0].substr(0, i);
                }
            }
            return strs[0];
        }

        string longestCommonPrefix_hotizon(vector<string> &strs) {
            if(strs.empty())
                return "";

            int len = strs[0].size();
            for(int i = 1; i < strs.size(); i++) {
                for(int j = 0; j < len; j++) {
                    if(strs[i][j] != strs[0][j])
                        len = j;
                }
            }
            return strs[0].substr(0, len);
        }
};
