/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */
#include <bits/stdc++.h>

using std::max;
using std::vector;

// @lc code=start
class Solution {
public:
    // 3D DP + prefix sum / suffix sum
    // T: O(n ^ 3)
    // S: O(n ^ 2)
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        // dp[i][m] is the maximum number of stones Alice can get  
        // when starting at index i with M = m
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        int suffix_sum[n + 1];
        memset(suffix_sum, 0, sizeof(suffix_sum));
        for (int i = n - 1; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        }

        // iterate from the back to the front
        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {
                if (i + (m << 1) < n) {
                    // Alice considers taking from 1 to 2*m piles,
                    // such that piles Bob gets will be minimized
                    for (int x = 1; x <= (m << 1); ++x) {
                        dp[i][m] = max(dp[i][m], suffix_sum[i] - dp[i + x][max(m, x)]);
                    }
                } else {
                    // Alice can take all remaining piles
                    dp[i][m] = suffix_sum[i];
                }
            }
        }
        return dp[0][1];
    }
};
// @lc code=end

