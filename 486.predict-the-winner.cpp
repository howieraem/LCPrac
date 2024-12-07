/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */
#include <bits/stdc++.h>

using std::max;
using std::vector;

// @lc code=start
class Solution {
public:
    // 2D DP
    // T: O(n ^ 2)
    // S: O(n) after state compression
    bool predictTheWinner(vector<int>& nums) {
        const int n = nums.size();
        if ((n & 1) == 0) {
            // even numbers, player 1 will always win given playing optimally
            return true;
        }

        // dp[i][j] means the max score difference between players 1 and 2 from nums[i...j]
        // Base case: dp[i][i] = nums[i] because player 1 chooses first and wins for length-1 arrays
        vector<int> dp(nums);

        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                // Choose either nums[i] on the left or nums[j] on the right
                // dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }

        return dp.back() >= 0;
    }
};
// @lc code=end

