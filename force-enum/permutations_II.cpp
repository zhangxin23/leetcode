#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 * */

class Solution {
public:
    vector<vector<int> > permutations(vector<int> &num) {
        sort(num.begin(), num.end());

        unordered_map<int, int> count_map;
        for(int i = 0; i < num.size(); i++) {
            if(count_map.find(num[i]) != count_map.end())
                count_map[num[i]]++;
            else
                count_map[num[i]] = 1;
        }

        vector<pair<int, int> > input;
        unordered_map<int, int>::const_iterator cit;
        for(cit = count_map.cbegin(); cit != count_map.end(); cit++) {
            input.push_back(*cit);
        }

        vector<int> path;
        vector<vector<int> > result;
        dfs(input, path, result);
        return result;
    }

private:
    void dfs(vector<pair<int, int> > &input, vector<int> &path, vector<vector<int> > &result) {
        if(input.size() == path.size()) {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < input.size(); i++) {
            int count = 0;
            for(int j = 0; j < path.size(); j++) {
                if(path[i] == input[i].first)
                    count++;
            }

            if(count < input[i].second) {
                path.push_back(input[i]);
                dfs(input, path, result);
                path.pop_back();
            }
        }
    }
};