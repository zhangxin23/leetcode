#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 *Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *The replacement must be in-place, do not allocate extra memory.
 *Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1, 2, 3 -> 1, 3, 2
 * 3, 2, 1 -> 1, 2, 3
 * 1, 1, 5 -> 1, 5, 1
 * */

class Solution {
    public:
        void next_permutation(vector<int> &nums) {
            int n = nums.size();
            if(n < 2)
                return;

            int pivot = -1;
            for(int i = n - 1; i >= 1; i--) {
                if(nums[i - 1] < nums[i]) {
                    pivot = i - 1;
                    break;
                }
            }

            if(pivot == -1) {
                reverse(nums.begin(), nums.end());
                return;
            }

            for(int i = n - 1; i > pivot; i--) {
                if(nums[i] > nums[pivot]) {
                    swap(nums[i], nums[pivot]);
                    break;
                }
            }

            reverse(next(nums.begin(), pivot + 1), nums.end());
        }

        bool nextPermutation(int A[], int n) {
            if(n == 0 || n == 1)
                return false;

            //find pivot number
            int pivot = -1;
            for(int i = n - 1; i > 0; i--) {
                if(A[i] > A[i - 1])
                    pivot = i - 1;
                    break;
            }

            if(pivot == -1) {
                reverse(A, n, 0, n - 1);
                return false;
            }

            //find change number
            for(int i = n - 1; i >= pivot; i--) {
                if(A[i] > A[pivot]) {
                    //swap pivot number and change number
                    swap_self(A + pivot, A + i);
                    break;
                }
            }

            //reverse pivot to last
            reverse(A, n, pivot + 1, n - 1);
            return true;
        }

    private:
        void swap_self(int* a, int* b) {
            *a ^= *b;
            *b = *a ^ *b;
            *a = *a ^ *b;
        }

        void reverse(int A[], int n, int start, int end) {
            if(start < 0)
                return;

            if(end > n)
                return;

            if(n == 0 || n == 1)
                return;

            while(start <= end) {
                swap(A + start, A + end);
                start++;
                end--;
            }
        }
};
