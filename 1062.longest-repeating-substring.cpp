/*
 * @lc app=leetcode id=1062 lang=cpp
 *
 * [1062] Longest Repeating Substring
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // DP solution
    // T: O(n ^ 2)
    // S: O(n) after state compression
    int longestRepeatingSubstring(string s) {
        const int n = s.size();
        int ans = 0;

        /*
        // dp[i][j] means the max. len. of common substring of the
        // substring ending at i and the substring ending at j.
        // Example: "abcbc" dp[2][4] = 2 because "bc" == "bc" but "abc" != "cbc"
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            // Can iterate j either from i + 1 to n, or from i - 1 to 1
            for (int j = i - 1; j >= 1; --j) {
                if (s[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = std::max(ans, dp[i][j]);
                }
            }
        }
        */

        // As dp[i][j] only depends on dp[i - 1][j - 1], 
        // space usage can be optimized.
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            // When states compressed, can only iterate j from i - 1 to 1
            for (int j = i - 1; j >= 1; --j) {
                if (s[i - 1] == s[j - 1]) {
                    dp[j] = dp[j - 1] + 1;
                    ans = std::max(ans, dp[j]);
                } else {
                    dp[j] = 0;
                }
            }
        }

        return ans;
    }

    // Similar solution based on Trie:
    // https://leetcode.com/problems/longest-repeating-substring/discuss/332052
};
// @lc code=end

