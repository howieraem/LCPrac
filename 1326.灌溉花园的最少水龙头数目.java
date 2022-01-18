/*
 * @lc app=leetcode.cn id=1326 lang=java
 *
 * [1326] 灌溉花园的最少水龙头数目
 */

// @lc code=start
class Solution {
    public int minTaps(int n, int[] ranges) {
        // Note: The garden and actual ranges are continuous, so for example all-zero `ranges` 
        // will not cover the garden.
        // Greedy strategy: always find the right furthest
        int[] land = new int[n];
        for (int i = 0; i < ranges.length; ++i) {
            int l = Math.max(i - ranges[i], 0);
            int r = Math.min(i + ranges[i], n);

            // At the j-th land within a tap's range, iteratively 
            // update the right boundary of the union range of all taps
            for (int j = l; j < r; ++j) {
                land[j] = Math.max(land[j], r);
            }
        }

        int ans = 0, i = 0;
        while (i < n) {
            if (land[i] == 0)  return -1;
            i = land[i];    // greedy: jump to the right boundary
            ++ans;
        }
        return ans;
    }
}
// @lc code=end

