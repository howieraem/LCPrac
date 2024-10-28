/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */
#include <bits/stdc++.h>

using std::min;
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(min(m, n)) after state compression
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size()) {
            std::swap(word1, word2);  // make m >= n
        }
        const int m = word1.size();
        if (m == 0) {
            return 0;
        }
        const int n = word2.size();
        if (n == 0) {
            return m;
        }

        /*
        // Naive 2D DP: dp[i][j] means edit distance between word1[:i] and word2[:j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // base cases: edit distance between any string and an empty string is the length of the former
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    // skip both word1[i - 1] and word2[j - 1] 
                    // as they will not affect edit distance
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(
                        dp[i - 1][j],        // delete a char from word1
                        min(dp[i][j - 1],    // add a char to word2
                            dp[i - 1][j - 1] // replace a char
                        )  
                    ) + 1;
                }
            }
        }
        return dp[m][n];
        */

        // Space-optimized 1D DP
        vector<int> dp(n + 1, 0);
        for (int j = 0; j <= n; ++j) {
            dp[j] = j; // base cases
        }
        for (int i = 1; i <= m; ++i) {
            int pre = dp[0]; // dp[i - 1][j - 1]
            dp[0] = i; // base cases
            
            for (int j = 1; j <= n; ++j) {
                int tmp = dp[j]; // dp[i - 1][j]

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = pre;
                } else {
                    dp[j] = min(tmp, min(dp[j - 1], pre)) + 1;
                }

                pre = tmp; // current dp[i - 1][j] becomes dp[i - 1][j - 1] in the next iter
            }
        }
        return dp[n];
    }
};
// @lc code=end

