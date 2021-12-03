/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
#include <string>

using std::string;

// @lc code=start
class Solution {
public:
    /*
    // Solution with 2D array
    bool isMatch(string s, string p) {
        const int m = s.size(), n = p.size();

        // dp[i][j] means whether s[:i] matches regex p[:j]. Add 1 to both dimensions to
        // consider the base cases like an empty string and/or an empty pattern.
        bool dp[m + 1][n + 1];
        memset(dp, false, sizeof(dp));

        // Base case: dp[i][0] should be false (cannot match an empty pattern) unless s is empty.
        dp[0][0] = true;
        for (int j = 1; j <= n; ++j) {
            // Question constraint: p[0] is never '*'. If this constraint is not given,
            // just check if p[0] == '*' before and return true if so. 
            dp[0][j] = (p[j - 1] == '*' && dp[0][j - 2]);
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // If encounter '*', try matching the pattern prior to '*'
                    dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    // one-one match
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
    */

    // Solution with 1D array (states compressed)
    bool isMatch(string s, string p) {
        const int m = s.size(), n = p.size();
        bool dp[n + 1];
        memset(dp, false, sizeof(dp));

        dp[0] = true;
        for (int j = 1; j <= n; ++j) {
            dp[j] = (p[j - 1] == '*' && dp[j - 2]);
        }

        for (int i = 1; i <= m; ++i) {
            bool pre = dp[0];
            dp[0] = false;
            for (int j = 1; j <= n; ++j) {
                bool tmp = dp[j];
                if (p[j - 1] == '*') {
                    dp[j] = dp[j - 2] || (dp[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[j] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                pre = tmp;
            }
        }
        return dp[n];
    }
};
// @lc code=end

