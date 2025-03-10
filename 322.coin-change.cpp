/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <bits/stdc++.h>

using std::vector;
using std::min;

// @lc code=start
class Solution {
public:
    // 0/1 knapsack problem + 1D DP
    // T: O(len(coins) * amount)
    // S: O(amount)
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (const auto& coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                } 
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end

