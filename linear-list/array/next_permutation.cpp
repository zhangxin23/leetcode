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
                reverse(A, 0, n - 1);
                return false;
            }

            //find change number
            int change = -1;
            for(int i = n - 1; i >= pivot; i--) {
                if(A[i] > A[pivot]) {
                    change = i;
                    break;
                }
            }

            //swap pivot number and change number
            swap(A + pivot, A + change);

            //reverse pivot to last
            reverse(A, pivot + 1, n - 1);
            return true;
        }

    private:
        void swap(int* a, int* b) {
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
