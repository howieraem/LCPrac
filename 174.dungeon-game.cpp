/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */
#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(m * n)
    // S: O(m * n)
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const auto m = dungeon.size(), n = dungeon[0].size();

        // dp[i][j]: min. HP required to reach dungeon[i][j]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        // Base case: AFTER reaching the bottom right, the minimum HP is 1.
        // It is then clear why need to add 1 to both dimensions of dp, as
        // the bottom right cell can also cost/increase HP just like other
        // cells. 
        dp[m][n - 1] = dp[m - 1][n] = 1;

        // Iterate backwards and find the minimum HP required at the top left
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Forward: right and down only
                // Backward: left and up only
                // Value constraint: HP must be at least 1 on every cell
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

