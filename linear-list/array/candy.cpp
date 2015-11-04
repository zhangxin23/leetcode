#include <iostream>
#include <vector>

using namespace std;

/**
 *There are N children standing in a line. Each child is assigned a rating value.
 *You are giving candies to these children subjected to the following requirements:
 *  • Each child must have at least one candy.
 *  • Children with a higher rating get more candies than their neighbors.
 *What is the minimum candies you must give?
 * */

class Solution {
    public:
        int candy(vector<int>& ratings) {
            const int n = ratings.size();
            vector<int> increments(n);

            int inr = 1;
            for(int i = 0; i < n; i++) {
                if(ratings[i] > ratings[i - 1]) {
                    increments[i] = max(increments[i], inr++);
                } else {
                    inr = 1;
                }
            }

            inr = 1;
            for(int i = n - 2; i >= 0; i--) {
                if(ratings[i] > ratings[i + 1]) {
                    increments[i] = max(increments[i + 1], inr++);
                } else {
                    inr = 1;
                }
            }

            int sum = 0;
            for(int i = 0; i < n; i++) {
                sum += increments[i];
            }
            sum += n;

            return sum;
        }
};
