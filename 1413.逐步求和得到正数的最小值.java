/*
 * @lc app=leetcode.cn id=1413 lang=java
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start
class Solution {
    public int minStartValue(int[] nums) {
        int min = 0, sum = 0;
        for (int num : nums) {
            sum += num;
            min = Math.min(min, sum);
        }
        return min > 0 ? 1 : 1 - min;
    }
}
// @lc code=end

