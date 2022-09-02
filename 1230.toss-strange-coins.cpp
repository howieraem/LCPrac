/*
 * @lc app=leetcode id=1230 lang=cpp
 *
 * [1230] Toss Strange Coins
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    /*
    // Original 2D DP
    // T: O(n * target)
    // S: O(n * target)
    double probabilityOfHeads(vector<double>& prob, int target) {
        const int n = prob.size();

        // dp[i][j] is the probability of j facing heads after tossing the first i coins. 
        vector<vector<double>> dp(n + 1, vector<double>(target + 1, 0.));

        // base case
        dp[0][0] = 1.;
        for (int i = 1; i <= n; ++i) {
            // prob of all facing tails
            dp[i][0] = dp[i - 1][0] * (1 - prob[i - 1]);
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                // term 1: the newly tossed coin faces heads
                // term 2: the newly tossed coin faces tails
                dp[i][j] = dp[i - 1][j - 1] * prob[i - 1] + dp[i - 1][j] * (1 - prob[i - 1]);
            }
        }
        return dp[n][target];
    }
    */

    // Space-optimized DP
    // T: O(n * target)
    // S: O(target)
    double probabilityOfHeads(vector<double>& prob, int target) {
        const int n = prob.size();
        vector<double> dp(target + 1, 0.);
        dp[0] = 1.;
        for (int i = 0; i < n; ++i) {
            // Need to iterate backwards to avoid incorrect overwriting
            for (int j = std::min(i + 1, target); j >= 0; --j) {
                dp[j] = (j > 0 ? dp[j - 1] : 0) * prob[i] + dp[j] * (1 - prob[i]);
            }
        }
        return dp[target];
    }
};
// @lc code=end

