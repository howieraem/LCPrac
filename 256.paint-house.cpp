/*
 * @lc app=leetcode id=256 lang=cpp
 *
 * [256] Paint House
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
    // T: O(n * c), n := len(costs), c := len(costs[0])
    // S: O(n * c) (or O(1) if inplace modification)
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> dp = costs;  // If inplace modification is not allowed
        for (int i = 1; i < costs.size(); ++i) {
            // Choose a different color with less cost
            dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
        }
        vector<int> &finalCosts = dp.back();
        return min(finalCosts[0], min(finalCosts[1], finalCosts[2]));
    }
    */
    
    // 1D DP
    // T: O(n * c), n := len(costs), c := len(costs[0])
    // S: O(c) after state compression
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) {
            return 0;
        }

        // dp[i] means the minimum cost if the i-th color is chosen for the final house
        int dp[costs[0].size()];
        copy(costs[0].begin(), costs[0].end(), dp);
        int pre[costs[0].size()];

        for (int i = 1; i < costs.size(); ++i) {
            // Choose a different color with less cost,
            // similar to Q198
            memcpy(pre, dp, sizeof(dp));
            dp[0] = min(pre[1], pre[2]) + costs[i][0],
            dp[1] = min(pre[0], pre[2]) + costs[i][1],
            dp[2] = min(pre[0], pre[1]) + costs[i][2];
        }
        return min(dp[0], min(dp[1], dp[2]));
    }
};
// @lc code=end

