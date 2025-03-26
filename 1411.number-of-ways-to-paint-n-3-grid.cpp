/*
 * @lc app=leetcode id=1411 lang=cpp
 *
 * [1411] Number of Ways to Paint N × 3 Grid
 */

// @lc code=start
class Solution {
public:
    // 1D DP + Math
    // T: O(n)
    // S: O(1) state compression
    int numOfWays(int n) {
        int MOD = 1000000007;

        // 3-color combos: RYG, RGY, GYR, GRY, YGR, YRG; or C(3, 3) * 3! = 6
        // 2-color combos: RYR, RGR, GYG, GRG, YGY, YRY; or C(3, 2) * 2 = 6
        // dp_3color means the number of ways with the last row having 3 colors
        // dp_2color means the number of ways with the last row having 2 colors
        long dp_3color = 6;
        long dp_2color = 6;

        // Transition to ensure no same adjacent vertical colors:
        // 3-color: RYG -> GRY, YGR, YGY, YRY
        // 2-color: RYR -> YRG, GRY, YRY, GRG, YGY
        // Similar transitions apply to other initial color combos.
        for (int i = 2; i <= n; ++i) {
            long dp_3color_pre = dp_3color;
            dp_3color = ((dp_3color << 1) + (dp_2color << 1)) % MOD;
            dp_2color = ((dp_3color_pre << 1) + dp_2color * 3) % MOD;
        }

        return (int) (dp_3color + dp_2color) % MOD;
    }
};
// @lc code=end

