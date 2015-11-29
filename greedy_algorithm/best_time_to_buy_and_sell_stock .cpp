#include <iostream>
#include <vector>

using namespace std;

/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
 * design an algorithm to find the maximum profit.
 * */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2)
            return 0;

        int profit = 0;
        int cur_min = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - cur_min);
            cur_min = min(cur_min, prices[i]);
        }

        return profit;
    }
};
