#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

/**
 * Given two words (beginWord and endWord), and a dictionary's word list,
 * find the length of shortest transformation sequence from beginWord to endWord, such that:
 *
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the word list
 * For example,
 *
 * Given:
 *  beginWord = "hit"
 *  endWord = "cog"
 *  wordList = ["hot","dot","dog","lot","log"]
 *  As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 *  return its length 5.
 *
 * Note:
 *  Return 0 if there is no such transformation sequence.
 *  All words have the same length.
 *  All words contain only lowercase alphabetic characters.
 * */

class Solution {
public:
    int wordLadder(const string &start, const string &end, const unordered_set<string> &dict) {
        queue<string> current, next;
        unordered_set<string> visited;

        int level = 0;
        bool found = false;

        auto state_is_target = [&](const string &s) {return s == end;};
        auto state_extend = [&](const string &s) {
            vector<string> result;
            string new_word(s);

            for(size_t i = 0; i < s.size(); i++) {
                for(char c = 'a'; c <= 'z'; c++) {
                    if(c == new_word[i])
                        continue;

                    swap(c, new_word[i]);
                    if((dict.count(new_word) || new_word == end) && (!visited.count(new_word))) {
                        result.push_back(new_word);
                        visited.insert(new_word);
                    }
                    swap(c, new_word[i]);
                }
            }
            return result;
        };

        current.push(start);
        while(!current.empty() && !found) {
            level++;
            while(!current.empty() && !found) {
                const string str = current.front();
                current.pop();

                const auto& new_states = state_extend(str);
                for(const auto& state: new_states) {
                    next.push(state);
                    if(state_is_target(state)) {
                        found = true;
                        break;
                    }
                }
            }
            swap(next, current);
        }

        if(found)
            return level + 1;
        else
            return 0;
    }
};