#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Return:
 *
 *   [
 *     ["ate", "eat","tea"],
 *     ["nat","tan"],
 *     ["bat"]
 *   ]
 * Note:
 *  For the return value, each inner list's elements must follow the lexicographic order.
 *  All inputs will be in lower-case.
 * */

class Solution {
    public:
        vector<vector<string> > groupAnagrams(vector<string>& strs) {
            vector<vector<string> > result;
            unordered_map<string, vector<string> > group;
            for(int i = 0; i < strs.size(); i++) {
                string key = strs[i];
                sort(key.begin(), key.end());
                group[key].push_back(strs[i]);
            }

            for(unordered_map<string, vector<string> >::iterator it = group.begin(); it != group.end(); it++) {
                result.push_back(vector<string>(it->second->begin(), it->second()->end()));
            }

            return result;
        }
};
