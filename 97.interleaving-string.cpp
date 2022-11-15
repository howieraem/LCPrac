/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(min(m, n))
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        if (s1.size() < s2.size()) std::swap(s1, s2);

        const int m = s1.size(), n = s2.size();

        /*
        // Naive 2D DP: dp[i][j] means isInterleave(s1[:i], s2[:j], s3)
        vector<vector<uint8_t>> dp(m + 1, vector<uint8_t>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                int k = i + j - 1;
                if (i > 0) {
                    dp[i][j] |= (dp[i-1][j] && s1[i-1] == s3[k]);
                }
                if (j > 0) {
                    dp[i][j] |= (dp[i][j-1] && s2[j-1] == s3[k]);
                }
            }
        }
        return dp[m][n];
        */

        // Space-optimized 1D DP
        vector<uint8_t> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                int k = i + j - 1;
                if (i > 0) {
                    dp[j] &= s1[i-1] == s3[k]; // IMPORTANT
                }
                if (j > 0) {
                    dp[j] |= (dp[j-1] && s2[j-1] == s3[k]);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

