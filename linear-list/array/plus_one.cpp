/**
 *Given a number represented as an array of digits, plus one to the number.
 * */

class Solution {
    public:
        void plusOne(vector<int>& digits) {
            int c = 1;
            for(auto it = digits.rbegine(); it != digits.rend(); it++) {
                *it += c;
                c = *it / 10;
                *it %= 10;
            }

            if(c > 0)
                digits.insert(digits.begin(), 1);
        }
};
