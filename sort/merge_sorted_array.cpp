#include <iostream>

using namespace std;

/**
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space to hold additional elements from B.
 * The number of elements initialized in A and B are m and n respectively.
 * */

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int idx_a = m - 1, idx_b = n - 1, idx_cur = m + n - 1;
        while(idx_a >= 0 && idx_b >= 0) {
            A[idx_cur--] = A[idx_a] > B[idx_b] ? A[idx_a--] : B[idx_b--];
        }
        while(idx_b >= 0) {
            A[idx_cur--] = B[idx_b--];
        }
    }
};