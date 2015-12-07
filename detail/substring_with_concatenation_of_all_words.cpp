#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * You are given a string, s, and a list of words, words, that are all of the same length.
 * Find all starting indices of substring(s) in s
 * that is a concatenation of each word in words exactly once and without any intervening characters.
 *
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter).
 * */

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words.front().length();
        int catLength = wordLength * words.size();
        vector<int> result;

        if(s.length() < catLength)
            return result;

        unordered_map<string, int> wordCount;
        for(string word: words) {
            wordCount[word]++;
        }

        for(string::iterator i = s.begin(); i <= prev(s.end(), catLength); i++) {
            unordered_map<string, int> unused(wordCount);

            for(string::iterator j = i; j != next(i, catLength); j += wordLength) {
                unordered_map<string, int>::iterator pos = unused.find(string(j, next(j, wordLength)));

                if(pos == unused.end() || pos->second == 0)
                    break;

                if(--pos->second == 0)
                    unused.erase(pos);
            }

            if(unused.size() == 0)
                result.push_back(distance(s.begin(), i));
        }

        return result;
    }
};
