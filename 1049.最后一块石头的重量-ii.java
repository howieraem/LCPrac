import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=1049 lang=java
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
    // 转换成01背包问题，求两堆石头的最小差值。由于石头总和为sum，则问题转换成了：
    //      背包最多装sum / 2的石头，stones数组里有一大堆石头，求如何装能装下最多重量石头？
    public int lastStoneWeightII(int[] stones) {
        int n = stones.length;
        int sum = Arrays.stream(stones).sum();
        int cap = sum / 2;

        // int[][] dp = new int[n + 1][cap + 1];
        // for (int i = 1; i <= n; ++i) {
        //     int stone = stones[i - 1];
        //     for (int j = 1; j <= cap; ++j) {
        //         if (stone <= j) {
        //             dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - stone] + stone);
        //         } else {
        //             dp[i][j] = dp[i - 1][j];
        //         }
        //     }
        // }
        // return Math.abs(sum - dp[n][cap] - dp[n][cap]);

        // Since dp[i][...] only depends on dp[i - 1][...] above, compress the states
        int[] dp = new int[cap + 1];
        for (int i = 1; i <= n; ++i) {
            int stone = stones[i - 1];
            for (int j = cap; j >= stone; --j) {
                dp[j] = Math.max(dp[j], dp[j - stone] + stone);
            }
        }
        return Math.abs(sum - dp[cap] * 2);
    }
}
// @lc code=end

