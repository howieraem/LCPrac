/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // 1D DP
    // T: O(n)
    // S: O(1) after state compression
    int numDecodings(string s) {
        const int n = s.size();

        // No way to decode string with leading zero(s)
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        
        if (n == 1) {
            return 1;
        }

        // dp[i] means the number of decoding ways for s[:i].
        // Base case: dp[0] = 1.
        // dp[i] only depends on dp[i - 1] and dp[i - 2], so we can compress the states.
        int dp_i_2 = 1, dp_i_1 = 1;
        for (int i = 2; i <= n; ++i) {  // IMPORTANT: i <= n
            int dp_i;
            if (s[i - 1] == '0') {
                // can't decode if substr starts with 0
                dp_i = 0;
            } else {
                dp_i = dp_i_1;
            }

            // "10" <= s[i-2, i-1] <= "26"
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')) {
                dp_i += dp_i_2;
            }

            // Discard older states
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }

        return dp_i_1;
    }
};
// @lc code=end

