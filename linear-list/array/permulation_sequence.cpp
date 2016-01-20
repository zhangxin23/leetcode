#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
 *By listing and labeling all of the permutations in order, We get the following sequence (ie, for n = 3):
 *  123
 *  132
 *  213
 *  231
 *  312
 *  321
 *Given n and k, return the kth permutation sequence.
 *Note: Given n will be between 1 and 9 inclusive.
 * */

class Solution {
    public:
        vector<int> kthPermutation(int n, int k) {
            vector<int> result;

            for(int i = 0; i < n; i++) {
                result.push_back(i + 1);
            }

            for(int i = 0; i < k - 1; i++) {
                nextPermutation(result);
            }

            return result;
        }

    private:
        void nextPermutation(vector<int> &vec) {
            int n = vec.size();
            if(n < 2)
                return;

            int pivot = -1;
            for(int i = n - 1; i >= 1; i--) {
                if(vec[i - 1] < vec[i]) {
                    pivot = i - 1;
                    break;
                }
            }

            if(pivot == -1) {
                reverse(vec.begin(), vec.end());
                return;
            }

            for(int i = n - 1; i > pivot; i--) {
                if(vec[i] > vec[pivot]) {
                    swap(vec[i], vec[pivot]);
                    break;
                }
            }

            reverse(next(vec.begin(), pivot + 1), vec.end());
        }
};
