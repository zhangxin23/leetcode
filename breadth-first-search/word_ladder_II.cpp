#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Given two words (beginWord and endWord), and a dictionary's word list,
 * find all shortest transformation sequence(s) from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the word list
 * For example,
 *
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * Return
 *  [
 *   ["hit","hot","dot","dog","cog"],
 *   ["hit","hot","lot","log","cog"]
 *  ]
 * Note:
 *  All words have the same length.
 *  All words contain only lowercase alphabetic characters.
 * */

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end,
                                        const unordered_set<string> &dict) {
        unordered_set<string> current, next;
        unordered_set<string> visited;
        unordered_map<string, vector<string> > father;
        bool found = false;

        auto state_is_target = [&](const string &s) {return s == end;};
        auto state_extend = [&](const string &s) {
            unordered_set<string> result;
            for (size_t i = 0; i < s.size(); ++i) {
                string new_word(s);
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == new_word[i])
                        continue;

                    swap(c, new_word[i]);
                    if ((dict.count(new_word) > 0  || new_word == end) &&
                        !visited.count(new_word)) {
                        result.insert(new_word);
                    }
                    swap(c, new_word[i]);
                }
            }
            return result;
        };

        current.insert(start);
        while (!current.empty() && !found) {
            for (const auto& word : current)
                visited.insert(word);

            for (const auto& word : current) {
                const auto new_states = state_extend(word);
                for (const auto &state : new_states) {
                    if (state_is_target(state))
                        found = true;

                    next.insert(state);
                    father[state].push_back(word);
                }
            }
            current.clear();
            swap(current, next);
        }

        vector<vector<string> > result;
        if (found) {
            vector<string> path;
            gen_path(father, path, start, end, result);
        }
        return result;
    }

private:
    void gen_path(unordered_map<string, vector<string> > &father,
                  vector<string> &path, const string &start, const string &word,
                  vector<vector<string> > &result) {
        path.push_back(word);
        if(word == start) {
            result.push_back(path);
            reverse(result.back().begin(), result.back().end());
        } else {
            for(const auto& item: father[word]) {
                gen_path(father, path, start, item, result);
            }
        }
    }
};
