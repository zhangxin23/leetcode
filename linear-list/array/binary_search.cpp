/**
 *Binary Search
 * */

class Solution {
public:
    int binarySearch(int A[], int n, int target) {
        int first = 0, last = n;
        while(first != last) {
            int mid = first + (last - first) / 2; //prevente overflow

            if(A[mid] == target) {
                return mid;
            } else if(A[mid] < target) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        return -1;
    }
};
