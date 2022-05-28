/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(log(n))
    // S: O(1)
    int findPeakElement(std::vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        // As we can return the index of any of the peaks, it is fine to 
        // discard half of the array in every iteration.
        while (l < r) {
            int m1 = l + ((r - l) >> 1), m2 = m1 + 1;
            if (nums[m1] < nums[m2]) {
                l = m2;
            } else {
                r = m1;
            }
        }
        return l;
    }
};
// @lc code=end

