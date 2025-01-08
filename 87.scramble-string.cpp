/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // 3D DP
    // T: O(n ^ 4)
    // S: O(n ^ 3)
    bool isScramble(string s1, string s2) {
        const int n = s1.length();
        if (n != s2.length()) {
            return false;
        }

        // dp[i][j][k] means whether s1[i ... i + k - 1] is a scramble of s2[j ... j + k - 1]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n + 1)));

        // Base case: substr len = 1, matching chars are scramble of each other
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                for (int j = 0; j + len <= n; ++j) {
                    // IMPORTANT: update iff dp[i][j][len] has not been set to true
                    for (int cut_len = 1; cut_len < len && !dp[i][j][len]; ++cut_len) {
                        // After cut:
                        // Case 1: s = x + y
                        // Case 2: s = y + x
                        dp[i][j][len] = 
                                (dp[i][j][cut_len] && dp[i + cut_len][j + cut_len][len - cut_len]) ||
                                (dp[i][j + len - cut_len][cut_len] && dp[i + cut_len][j][len - cut_len]);
                    }
                }
            }
        }

        return dp[0][0][n];
    }
};
// @lc code=end

