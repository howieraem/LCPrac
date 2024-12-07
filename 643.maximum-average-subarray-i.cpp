/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Sliding window
    // Fixed-size window, so negative numbers are okay
    // T: O(n)
    // S: O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        int max_window_sum = INT_MIN;
        int window_sum = 0;
        for (int r = 0; r < nums.size(); ++r) {
            window_sum += nums[r];
            if (r >= k - 1) {
                if (r >= k) {
                    window_sum -= nums[r - k];
                }
                max_window_sum = std::max(max_window_sum, window_sum);
            }
        }
        return (double)max_window_sum / k;
    }
};
// @lc code=end

