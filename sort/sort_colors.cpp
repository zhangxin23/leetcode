#include <iostream>

using namespace std;

/**
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent,
 * with the colors in the order red, white and blue.
 *
 * Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
 *
 * Note:
 * You are not suppose to use the library's sort function for this problem.
 * */

class Solution {
public:
    void sortColors_two_pass(int A[], int n) {
        int counts[3] = {0};

        for(int i = 0; i < n; i++) {
            counts[A[i]]++;
        }

        int index = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < counts[i]; j++) {
                A[index++] = i;
            }
        }
    }

    void sortColors_one_pass(int A[], int n) {
        int red = 0, blue = n - 1;

        for(int i = 0; i < n;) {
            if(A[i] == 0) {
                swap(A[i++], A[red++]);
            } else if(A[i] == 2) {
                swap(A[i], A[blue--]);
            } else {
                i++;
            }
        }
    }
};