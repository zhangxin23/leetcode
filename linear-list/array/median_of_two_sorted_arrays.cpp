/**
 *There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
 *The overall run time complexity should be O(log(m + n)).
 * */

class Solution {
    public:
        double findMedian(int A[], int m, int B[] int n) {
            int total = m + n;
            if(total % 2 != 0)
                return find_kth(A, m, B, n, total / 2 + 1);
            else
                return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2.0;
        }

    private:
        static int find_kth(int A[], int m, int B[], int n, int k) {
            if(m > n)
                return find_kth(B, n, A, m, k);
            if(m == 0)
                return B[k - 1];
            if(k == 1)
                return min(A[0], B[0]);

            int idx_a = min(k / 2, m), idx_b = k - ida_a;
            if(A[idx_a - 1] < B[idx_b - 1])
                return find_kth(A + idx_a, m - idx_a, B, n, k - idx_a);
            eles if(A[idx_a - 1] > B[idx_b -1])
                return find_kth(A, m, B + idx_b, n - idx_b, k - idx_b);
            else
                return A[idx_a - 1];
        }
};
