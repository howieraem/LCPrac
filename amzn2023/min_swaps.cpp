/**
 * Assume only adjacent elements in an array can be swapped. 
 * Find the minimum number of swaps such that the minimum 
 * element becomes the 1st element and the maximum element 
 * becomes the last element.
 */
#include <bits/stdc++.h>

// T: O(n)
// S: O(1)
int min_swaps(const std::vector<int>& arr) {
    int min = INT_MAX, max = INT_MIN;
    int min_i = 0, max_i = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > max) {
            max = arr[i];
            max_i = i;
        }
        if (arr[i] < min) {
            min = arr[i];
            min_i = i;
        }
    }
    return min_i > max_i ? min_i - max_i - 1 : max_i - min_i;
}
