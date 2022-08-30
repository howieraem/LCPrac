/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
// Very similar to Q221
class Solution {
public:
    /*
    // Original DP
    // T: O(m * n)
    // S: O(m * n)
    int countSquares(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();

        // dp[i][j] means the number of squares with mat[i][j] as the bottom-right corner. It also
        // means the size of the biggest square with mat[i][j] as the bottom-right corner.
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else {
                        dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    }
                    ans += dp[i][j];  // In Q221, this would be ans = max(ans, dp[i][j])
                }
            }
        }
        return ans;
    }
    */

    // Space-optimized DP
    // T: O(m * n)
    // S: O(n)
    int countSquares(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();

        vector<int> dp(n, 0);
        int pre = INT_MAX;
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int tmp = dp[j];
                if (matrix[i][j]) {
                    if (i == 0 || j == 0) dp[j] = 1;
                    else {
                        dp[j] = std::min(pre, std::min(dp[j], dp[j - 1])) + 1;
                    }
                    ans += dp[j];
                } else {
                    // IMPORTANT
                    dp[j] = 0;
                }
                pre = tmp;   // pre becomes dp[i - 1][j] in the next iteration of i
            }
        }
        return ans;
    }
};
// @lc code=end

