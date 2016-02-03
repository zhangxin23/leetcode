#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a number represented as an array of digits, plus one to the number.
 * */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> result;
        for(vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it++) {
            int value = (*it + carry) % 10;
            carry = (*it + carry) / 10;
            result.insert(result.begin(), value);
        }

        if(carry > 0)
            result.insert(result.begin(), 1);

        return result;
    }

    void plusOne_1(vector<int>& digits) {
        int c = 1;
        for(auto it = digits.rbegin(); it != digits.rend(); it++) {
            *it += c;
            c = *it / 10;
            *it %= 10;
        }

        if(c > 0)
            digits.insert(digits.begin(), 1);
    }
};
