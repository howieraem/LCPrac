/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(log(n))
    // S: O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int m = l + ((r - l) >> 1);
            bool is_even = (m & 1) == 0; 
            if ((is_even && nums[m] == nums[m + 1]) || (!is_even && nums[m] == nums[m - 1])) {
                // the target must be on the right of m
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
};
// @lc code=end

