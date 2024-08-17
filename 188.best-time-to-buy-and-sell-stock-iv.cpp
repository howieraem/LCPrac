/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * k)
    // S: O(k) after state compression
    int maxProfit(int k, vector<int>& prices) {
        const int n = prices.size();
        if (n == 0) {
            return 0;
        }

        // special cases: large k, can buy and sell every day, same as Q123
        if (k >= (n >> 1)) {
            int ans = 0;
            for (int i = 1; i < n; ++i) {
                int pre = prices[i - 1];
                int cur = prices[i];
                if (cur > pre) {
                    ans += (cur - pre);
                }
            }
            return ans;
        }

        // dp[i][k][0] means money left after selling on the ith day at most kth times
        // dp[i][k][1] means money left after buying on the ith day at most kth times
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));

        // for (int i = 0; i < n; ++i) {
        //     // dp[i][0][1] = INT_MIN;
        // }
        dp[0][1] = INT_MIN;

        for (int j = 1; j <= k; ++j) {
            // dp[0][j][1] = -prices[0];
            dp[j][1] = -prices[0];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                // get max from hold or trade
                // dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                // dp[i][j][1] = std::max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
                dp[j][0] = std::max(dp[j][0], dp[j][1] + prices[i]);
                dp[j][1] = std::max(dp[j][1], dp[j - 1][0] - prices[i]);
            }
        }

        // return dp.back()[k][0];
        return dp[k][0];
    }
};
// @lc code=end

