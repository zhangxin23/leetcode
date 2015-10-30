/**
 *Given a string, determine if it is a palindrome,
 *considering only alphanumeric characters and ignoringcases.
 *For example,
 *”A man, a plan, a canal: Panama” is a palindrome.
 *”race a car” is not a palindrome.
 *Note: Have you consider that the string might be empty?
 *This is a good question to ask during an interview.
 *For the purpose of this problem, we define empty string as valid palindrome.
 * */

class Solution {
    public:
        bool isPalindrome(const char* s) {
            if(s == NULL)
                return false;

            size_t len = strlen(s);
            if(len == 0)
                return true;

            size_t left = 0, right = len - 1;
            while(left < right) {
                if(!isalnum(s[left]))
                    left++;
                else if(!isalnum(s[right]))
                    right--;
                else if(s[left] != s[right])
                    return false;
                else if(s[left] == s[right]) {
                    left++;
                    right--;
                }
            }
            return true;
        }
};
