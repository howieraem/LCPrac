/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */
#include <algorithm>
#include <vector>

using std::max;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n^3)
    // S: O(n^2)
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        int dp[n + 1][n + 1];   // dp[i][j] is the maximum number of stones Alex can get when starting at index i with M = j
        memset(dp, 0, sizeof(dp));
        int sufSum[n + 1];  // suffix sum
        memset(sufSum, 0, sizeof(sufSum));
        for (int i = n - 1; i >= 0; --i) {
            sufSum[i] = sufSum[i + 1] + piles[i];
        }

        // base case
        for (int i = 0; i <= n; ++i) {
            dp[i][n] = sufSum[i];
        }

        // iterate from the back to the front
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 1; --j) {
                for (int x = 1; x <= 2 * j && i + x <= n; ++x) {
                    dp[i][j] = max(dp[i][j], sufSum[i] - dp[i + x][max(j, x)]);
                }
            }
        }
        return dp[0][1];
    }
};
// @lc code=end

