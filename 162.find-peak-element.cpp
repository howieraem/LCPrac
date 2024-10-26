/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // Binary search
    // T: O(log(n))
    // S: O(1)
    int findPeakElement(std::vector<int>& nums) {
        const int N = nums.size();

        // Handle edge cases
        if (N == 1) {
            return 0;
        }
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[N - 1] > nums[N - 2]) {
            return N - 1;
        }

        int l = 1; 
        int r = N - 2;

        // Why binary search works: nums[i] != nums[i - 1], and there are 
        // multiple target indices, so nums don't have to be sorted.
        // As we can return the index of any of the peaks, it is fine to 
        // discard half of the array in every iteration.
        while (l <= r) {
            int m = l + ((r - l) >> 1); 
            
            if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) {
                return m;
            } else if (nums[m] < nums[m + 1]) {
                l = m + 1;
            } else if (nums[m] < nums[m - 1]) {
                r = m - 1;
            }
        }
        return l;
    }
};
// @lc code=end

