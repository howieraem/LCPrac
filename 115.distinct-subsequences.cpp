/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n), m := len(s), n := len(t)
    // S: O(m) after state compression
    int numDistinct(string s, string t) {
        const int m = s.size(), n = t.size();
        if (m < n) return 0;

        /*
        // Naive 2D DP: dp[i][j] means the number of distinct subsequences of s[:i] equal to t[:j]
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        // base cases: in any string, there can only be 1 empty string as a distinct subsequence
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    // subsequences with or without s[i - 1]
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    // subsequences without s[i - 1] 
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
        */

        // Space-optimized 1D DP
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= m; ++i) {
            int pre = 1;  // corresponds to the base cases dp[i][0] = 1
            for (int j = 1; j <= n; ++j) {
                int tmp = dp[j]; // dp[i - 1][j]
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += pre; // dp[i - 1][j - 1]
                }
                pre = tmp; // dp[i - 1][j] becomes dp[i - 1][j - 1] in the next iteration
            }
        }
        return dp[n];
    }
};
// @lc code=end

