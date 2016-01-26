#include <iostream>

using namespace std;

/**
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * For example,
 *  "A man, a plan, a canal: Panama" is a palindrome.
 *  "race a car" is not a palindrome.
 *
 * Note:
 *  Have you consider that the string might be empty?
 *  This is a good question to ask during an interview.
 *  For the purpose of this problem, we define empty string as valid palindrome.
 * */

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;

        int start = 0, end = s.length() - 1;
        while(start < end) {
            if(!isalnum(s[start]))
                start++;
            else if(!isalnum(s[end]))
                end--;
            else if(s[start] != s[end])
                return false;
            else if(s[start] == s[end]) {
                start++;
                end--;
            }
        }

        return true;
    }
};
