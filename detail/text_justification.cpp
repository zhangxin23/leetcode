#include <iostream>
#include <vector>

using namespace std;

/**
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
 * Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 *
 * Extra spaces between words should be distributed as evenly as possible.
 * If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 *
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 *
 * Return the formatted lines as:
 *   [
 *      "This    is    an",
 *      "example  of text",
 *      "justification.  "
 *   ]
 * Note: Each word is guaranteed not to exceed L in length.
 *
 * Corner Cases:
 *  A line other than the last line might contain only one word. What should you do in this case?
 *  In this case, that line should be left-justified.
 * */

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int begin = 0, len = 0;
        for(int i = 0; i < n; i++) {
            if(len + words[i].size() + (i - begin) > maxWidth) {
                result.push_back(connect(words, begin, i, maxWidth, len, false));
                begin = i;
                len = 0;
            }
            len += words[i].length();
        }

        result.push_back(connect(words, begin, n - 1, maxWidth, len, true));
        return result;
    }

private:
    string connect(vector<string> &words, int begin, int end, int maxWidth, int len, bool is_last) {
        string s;
        int n = end - begin + 1;
        for(int i = 0; i < n; i++) {
            s += words[begin + i];
            addSpaces(s, i, n - 1, maxWidth - len, is_last);
        }

        if(s.size() < maxWidth)
            s.append(maxWidth - s.size(), ' ');
        return s;
    }

    void addSpaces(string &s, int slicIndex, int totalSlic, int totalSpaces, bool is_last) {
        if(totalSlic < 1 || slicIndex > totalSlic - 1)
            return;

        int spaces = is_last ? 1 : (totalSpaces / totalSlic + (slicIndex < (totalSpaces % totalSlic) ? 1 : 0));
        s.append(spaces, ' ');
    }
};
