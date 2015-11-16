#include <iostream>

using namespace std;


/**
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 * */

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        bucket_sort(A, n);

        for(int i = 0; i < n; i++) {
            if(A[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }

    void bucket_sort(int A[], int n) {
        for(int i = 0; i < n; i++) {
            while(A[i] != i + 1) {
                if(A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
                    break;
                swap(A[i], A[A[i] - 1]);
            }
        }
    }
};