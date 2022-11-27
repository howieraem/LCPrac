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
    // T: O(len(s) * len(p))
    // S: O(len(s) * len(p))
    bool isMatch(string s, string p) {
        const int m = s.size(), n = p.size();
        if (n != 0 && p[0] == '*')  return true;

        // dp[i][j] means whether s[:i] matches regex p[:j]. Add 1 to both dimensions to
        // consider the base cases like an empty string and/or an empty pattern.
        bool dp[m + 1][n + 1];
        memset(dp, false, sizeof(dp));

        // Base cases: dp[i][0] should be false (cannot match an empty pattern) unless s is empty.
        dp[0][0] = true;
        for (int j = 2; j <= n; ++j) { // j starts from 2 because we've checked if p[0] == '*'
            // Which p matches s = ""? The answer is either an empty pattern p = "" 
            // or a pattern that can represent an empty string such as p="a*", 
            // p="z*" or more interestingly a combination of them as in p="a*b*c*".
            dp[0][j] = (p[j - 1] == '*' && dp[0][j - 2]);
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // If encounter '*', try matching the pattern prior to '*'
                    dp[i][j] = dp[i][j - 2] ||   // '*' acts as an empty set
                            ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);  // current s[i - 1] equals the char preceding '*' in p
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
    // T: O(len(s) * len(p))
    // S: O(len(p))
    bool isMatch(string s, string p) {
        const int m = s.size(), n = p.size();
        if (n != 0 && p[0] == '*')  return true;

        bool dp[n + 1];
        memset(dp, false, sizeof(dp));

        dp[0] = true;
        for (int j = 2; j <= n; ++j) { // j starts from 2 because we've checked if p[0] == '*'
            dp[j] = (p[j - 1] == '*' && dp[j - 2]); // base cases
        }

        for (int i = 1; i <= m; ++i) {
            bool pre = dp[0]; // equivalent to dp[i - 1][j - 1]
            dp[0] = false; // base cases of dp[i][0]

            for (int j = 1; j <= n; ++j) {
                bool tmp = dp[j]; // equivalent to dp[i - 1][j]
                if (p[j - 1] == '*') {
                    dp[j] = dp[j - 2] || (tmp && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[j] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '.');   // pre is equivalent to dp[i - 1][j - 1]
                }
                pre = tmp;  // current dp[i - 1][j] becomes dp[i - 1][j - 1] in the next iter
            }
        }
        return dp[n];
    }
};
// @lc code=end

