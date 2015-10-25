/**
 *You are climbing a stair case. It takes n steps to reach to the top.
 *Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 * */

class Solution {
    public:
        int climbStairs(int n) {
            int prev = 0;
            int cur = 1;
            for(int i = 1; i < n; i++) {
                int tmp = prev;
                cur += prev;
                prev = tmp;
            }
            return cur;
        }
};
