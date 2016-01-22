#include <iostream>
#include <vector>

using namespace std;

/**
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * For example, given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
 * */

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lower = lower_bound(A, n, target);
        int upper = upper_bound(A, n, target);

        if(lower == n || A[lower] != target)
            return vector<int>{-1, -1};
        else
            return vector<int>{lower, upper - 1};
    }
private:
    int lower_bound(int A[], int n, int target) {
        int start = 0;
        int end = n;
        while(start != end) {
            int mid = start + (end - start) / 2;

            if(target > A[mid])
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }

    int upper_bound(int A[], int n, int target) {
        int start = 0;
        int end = n;
        while(start != end) {
            int mid = start + (end - start) / 2;

            if(target >= A[mid])
                start = mid + 1;
            else
                end = mid;
        }
        return start;
    }
};