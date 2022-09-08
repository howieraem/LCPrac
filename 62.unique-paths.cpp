/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(n)
    int uniquePaths(int m, int n) {
        /*
        // Intuitive 2D DP
        vector<vector<int>> dp(m, vector<int>(n, 1));
        // IMPORTANT: cells on the top or the left boundary have only 1 unique path,
        // so start iterating from 1 rather than 0
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // Only right and down directions are allowed
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
        */

        // Space-optimized
        // vector<int> pre(n, 1), cur(n, 1);
        vector<int> cur(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                // cur[j] = pre[j] + cur[j - 1];
                cur[j] += cur[j - 1];
            }
            // pre = cur;
        }
        // return pre.back();
        return cur.back();
    }
};
// @lc code=end

