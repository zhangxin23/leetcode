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
        vector<vector<int> > permutationSequence(int n, int k) {
            vector<vector<int> > result;
            vector<int> src;
            for(int i = 0; i < n; i++)
                src.push_back(i + 1);
            for(int i = 0; i < k - 1; i++) {
                nextPermutation(src);
                result.push_back(src);
            }
            return result;
        }
    private:
        bool nextPermutation(vector<int> src) {
            auto rfirst = vec.rbegin();
            auto rend = vec.rend();
            auto pivot = rfirst + 1;
            while(pivot != rlast && *pivot >= *(pivot - 1))
                pivot++;

            if(pivot == rlast) {
                reverse(rfirst, rlast);
                return false;
            }

            auto change = rfirst + 1;
            while(change != pivot && *change <= *pivot) {
                change++;
            }

            swap(*change, *pivot);
            reverse(rfirst, pivot);
            return true;
        }
};
