/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(1) states compressed
    int rob(vector<int>& nums) {
        int i2 = 0, i1 = 0;  // dp[i - 2], dp[i - 1]
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = i1;
            i1 = std::max(i1, i2 + nums[i]);
            i2 = tmp;
        }
        return i1;
    }
};
// @lc code=end

