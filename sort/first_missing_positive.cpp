#include <iostream>

using namespace std;

/**
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 *
 * 下面这道题可采用同样的解法:
 *      n个元素的数组，里面的数都是0~n-1范围内的，求数组中重复的某一个元素，没有返回-1, 要求时间性能O(n) 空间性能O(1)。
 * */

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(A == NULL || n < 1)
            return 1;

        for(int i = 0; i < n; i++) {
            while(A[i] != i + 1) {
                if(A[i] < 0 || A[i] > n - 1 || A[i] == A[A[i] - 1])
                    break;

                swap(A[i], A[A[i] - 1]);
            }
        }

        for(int i = 0; i < n; i++) {
            if(A[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};