/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * sum(nums))
    // S: O(sum(nums)) after state compression
    bool canPartition(vector<int>& nums) {
        // Convert to 0/1 knapsack problem: Find whether there are several numbers 
        // in a set which are able to sum to a specific value, sum(nums) / 2.
        int sum = 0;
        for (const int& x : nums) {
            sum += x;
        }

        if (sum & 1) return false;  // sum(nums) not divisible by 2, can't partition

        int target = (sum >> 1);

        // Original 2D DP: dp[i][j] means whether we can achieve target j by using the first i numbers.
        // 1D DP: dp[j] means whether we can achieve target j by using any numbers (without replacement).
        vector<uint8_t> dp(target + 1, 0);
        dp[0] = 1;

        for (const int& x : nums) {
            for (int j = target; j > 0; --j) {
                // The reason for iterating backwards is that in 2D DP dp[i][j] relies on dp[i-1][j-nums[i-1]] rather than dp[i][j - nums[i-1]].
                // Details: https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation/431026
                if (j >= x) {
                    dp[j] |= dp[j - x];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end

