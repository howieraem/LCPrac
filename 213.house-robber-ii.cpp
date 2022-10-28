/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1)
    int rob(vector<int>& nums) {
        const auto n = nums.size();
        if (n == 1) return nums[0];

        // Circular array, instead of doing index modulus, we know 
        // we can't rob both the first and the last houses, so just 
        // start from either and check which yields higher value.
        return std::max(rob(nums, 0, n - 1), rob(nums, 1, n));
    }

private:
    // Similar to Q198
    static int rob(const vector<int>& nums, size_t begin, size_t end) {
        int dp_i_2 = 0, dp_i_1 = 0, dp_i = 0;
        for (size_t i = begin; i < end; ++i) {
            dp_i = std::max(dp_i_1, dp_i_2 + nums[i]);

            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};
// @lc code=end

