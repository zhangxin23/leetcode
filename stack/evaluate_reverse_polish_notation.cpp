#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 * Some examples:
 *  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 * */

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<string> s;
        for(auto item: tokens) {
            if(!is_operator(item)) {
                s.push(item);
            } else {
                int left = stoi(s.top()); s.pop();
                int right = stoi(s.top()); s.pop();
                int ret = 0;
                if(item == "+")
                    ret = left + right;
                else if(item == "-")
                    ret = left + right;
                else if(item == "*")
                    ret = left * right;
                else if(item == "/")
                    ret = left / right;
                s.push(to_string(ret));
            }
        }
        return stoi(s.top());
    }

private:
    bool is_operator(const string &op) {
        if(op.size() == 1 && string("+-*/").find(op) != string::npos)
            return true;
        return false;
    }
};