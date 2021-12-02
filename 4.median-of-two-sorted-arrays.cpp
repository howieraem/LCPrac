/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include <bits/stdc++.h>

using std::vector;
using std::max;
using std::min;

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) { 
            return findMedianSortedArrays(nums2, nums1);
        }
        
        const int n1 = nums1.size(), n2 = nums2.size(), k = (n1 + n2 + 1) >> 1;
        int l = 0, r = n1;
        while (l < r) {
            int m1 = l + ((r - l) >> 1), m2 = k - m1;
            if (nums1[m1] < nums2[m2 - 1])  l = m1 + 1;
            else  r = m1;
        }

        // Check if indices of medians are out of range
        int m1 = l, m2 = k - l;
        int maxLeft = max(
            m1 > 0 ? nums1[m1 - 1] : INT_MIN,
            m2 > 0 ? nums2[m2 - 1] : INT_MIN);
        if ((n1 + n2) & 1)  return static_cast<double>(maxLeft);
        int minRight = min(
            m1 < n1 ? nums1[m1] : INT_MAX,
            m2 < n2 ? nums2[m2] : INT_MAX);
        return 0.5 * maxLeft + 0.5 * minRight;
    }
};
// @lc code=end

