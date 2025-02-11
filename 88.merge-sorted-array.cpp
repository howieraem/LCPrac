/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // two pointers
    // T: O(m + n)
    // S: O(1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m + n - 1;
        --m; --n;  // zero-indexed

        while (m >= 0 && n >= 0) {
            if (nums1[m] > nums2[n]) {
                nums1[last--] = nums1[m--];
            } else {
                nums1[last--] = nums2[n--];
            }
        }

        while (n >= 0) {
            nums1[last--] = nums2[n--];
        }

        // no need to consider extra m >= 0 case here
    }
};
// @lc code=end

