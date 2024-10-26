/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include <bits/stdc++.h>

using std::vector;
using std::max;
using std::min;
using std::swap;

// @lc code=start
class Solution {
public:
    // T: O(log(min(n1, n2))))
    // S: O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            // make nums2 the longer array to reduce time complexity in binary search of nums1
            swap(nums1, nums2);
        }

        // By definition, the array median can split the array into two equal-length portions.
        // Say nums1 is split into left and right portions at i,
        // and nums2 is split into left and right portions at j.
        // After nums1 and nums2 are concatenated to one array A, if len(A) = n1 + n2 is even, 
        // we can set i + j = n1 - i + n2 - j, such that:
        //     median_A = (max(nums1[i - 1], nums2[j - 1]) + min(nums1[i], nums2[j])) / 2.0
        // If n1 + n2 is odd, i + j = n1 - i + n2 - j + 1, we have:
        //     median_A = max(nums1[i - 1], nums2[j - 1])
        // For either case, j can be inferred from i:
        //     j = (n1 + n2 + 1) / 2 - i
        // and i can be found via binary search as nums1 is already sorted.
        const int n1 = nums1.size(), n2 = nums2.size(), k = (n1 + n2 + 1) >> 1;
        int l = 0, r = n1;  // range of i
        while (l < r) {
            int m1 = l + ((r - l) >> 1); 
            int m2 = k - m1;
            if (nums1[m1] < nums2[m2 - 1]) { 
                l = m1 + 1;
            } else {
                r = m1;
            }
        }

        // Check if split indices are out of bound
        int i = l, j = k - l;
        int maxLeft = max(
            i > 0 ? nums1[i - 1] : INT_MIN,
            j > 0 ? nums2[j - 1] : INT_MIN);
        if ((n1 + n2) & 1)  return static_cast<double>(maxLeft);
        int minRight = min(
            i < n1 ? nums1[i] : INT_MAX,
            j < n2 ? nums2[j] : INT_MAX);
        return 0.5 * maxLeft + 0.5 * minRight;
    }

    // Follow-up: find the k-th largest element of two sorted arrays
    // T: O(log(min(k, n1, n2)))
    // S: O(1)
    int findKthLargestOfTwoSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.size() > nums2.size()) {
            // make nums2 the longer array to reduce time complexity in binary search of nums1 
            swap(nums1, nums2);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        k = std::max(0, n1 + n2 - k);   // convert to (n1 + n2 - k)-th smallest

        int l = std::max(0, k - n2);  // if k > n2, need to take at least k - n2 elements from nums1
        int r = std::min(k, n1);      // if k < n1, can take at most k elements from nums1

        // int l = 0;
        // int r = n1 - 1;

        while (l <= r) {
            int m1 = l + ((r - l) >> 1);
            int m2 = k - m1;
            int nums1_l = m1 > 0 ? nums1[m1 - 1] : INT_MIN;
            int nums1_r = m1 < n1 ? nums1[m1] : INT_MAX;
            int nums2_l = m2 > 0 ? nums2[m2 - 1] : INT_MIN;
            int nums2_r = m2 < n2 ? nums2[m2] : INT_MAX;
            if (nums1_l <= nums2_r && nums2_l <= nums1_r) {
                return std::max(nums1_l, nums2_l);
            } else if (nums1_l > nums2_r) {
                r = m1 - 1;
            } else {
                l = m1 + 1;
            }
        }
        return -1;  // this should never happen
    }
};
// @lc code=end

