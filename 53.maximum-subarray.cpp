/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
#include <bits/stdc++.h>

using std::max;
using std::vector;

// @lc code=start
class Solution {
public:
    // DP, Kadane's algorithm
    // nums contain negative numbers, cannot use sliding window
    // T: O(n)
    // S: O(1) (no need to use an array for DP)
    int maxSubArray(vector<int>& nums) {
        int dp = 0;  // dp[i] means local maximum for all subarrs of nums[:i + 1]
        int ans = INT_MIN;  // global maximum

        // vector<int> subarr;

        for (const auto& x : nums) {
            // If the actual subarray should be returned
            // if (dp + x > x) {
            //     dp += x;
            //     subarr.push_back(x)
            // } else {
            //     dp = x;
            //     subarr.clear()
            // }

            // Either append the current number to the subarray by adding it to the subarray sum,
            // or start a new subarray by assigning the current number to the subarray sum. 
            dp = max(dp + x, x);

            ans = max(ans, dp);
        }
        return ans;
    }

    // Follow-up: array is circular, Q918
};
// @lc code=end

