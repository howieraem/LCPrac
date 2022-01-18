/*
 * @lc app=leetcode.cn id=1799 lang=java
 *
 * [1799] N 次操作后的最大分数和
 */

// @lc code=start
class Solution {
    private int m;
    private int[] memo;
    private int[][] gcds;

    public int maxScore(int[] nums) {
        m = nums.length;
        gcds = new int[m][m];
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                gcds[i][j] = gcd(nums[i], nums[j]);
            }
        }

        // Use a mask to store visited indices. Since
        // the maximum n is 7, use 14 bits to store
        // a pair of indices. Masks are generally much
        // faster to compute than hash sets and
        // hash maps. If the range of n is not given,
        // however, might need to implement a `Pair`
        // class with proper `hashCode` and `equals`
        // methods implemented, and then use a hash
        // map for memo and a hash set for path.
        memo = new int[1 << 14];

        return dfs(0, 1);
    }

    private int dfs(int pathMask, int curIdx) {
        if (memo[pathMask] != 0)  return memo[pathMask];
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int mask = ((1 << i) | (1 << j));
                if ((pathMask & mask) == 0) {
                    // i and j not yet visited
                    ans = Math.max(ans, curIdx * gcds[i][j] + dfs(pathMask | mask, curIdx + 1));
                }
            }
        }
        memo[pathMask] = ans;
        return ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
// @lc code=end

