#include <iostream>
#include <vector>

using namespace std;

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * */

class Solution {
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f(n, 0);
        vector<int> g(n, 0);

        for(int i = 1, least = prices[0]; i < n; i++) {
            least = min(prices[i], least);
            f[i] = max(f[i - 1], prices[i] - least);
        }

        for(int i = n - 2, peak = prices[n - 1]; i != 0; i--) {
            peak = max(prices[i], peak);
            g[i] = max(g[i + 1], peak - prices[i]);
        }

        int result = 0;
        for(int i = 0; i < n; i++) {
            result = max(result, f[i] + g[i]);
        }

        return result;
    }
};
