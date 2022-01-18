/*
 * @lc app=leetcode.cn id=1703 lang=java
 *
 * [1703] 得到连续 K 个 1 的最少相邻交换次数
 */

// @lc code=start
class Solution {
    // For more explanations, see
    // https://leetcode-cn.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/solution/de-dao-lian-xu-k-ge-1-de-zui-shao-xiang-lpa9i/
    public int minMoves(int[] nums, int k) {
        if (k == 1)  return 0;
        int ones = -1, m = nums.length, n = 0;
        int[] nZeros = new int[m], preSum = new int[m + 1];
        // preSum[0] = 0;
        for (int i = 0; i < m; ++i) {
            if (nums[i] == 1) {
                ++ones;
                nZeros[n] = i - ones;
                preSum[n + 1] = preSum[n] + nZeros[n];
                ++n;
            }
        }

        int ans = Integer.MAX_VALUE;
        for (int i = 0; i + k <= n; ++i) {
            int mid = (i + (i + k - 1)) >> 1;
            int q = nZeros[mid];
            ans = Math.min(ans, (2 * (mid - i) - k + 1) * q + 
                    (preSum[i + k] - preSum[mid + 1]) - (preSum[mid] - preSum[i]));
        }
        return ans;
    }
}
// @lc code=end

