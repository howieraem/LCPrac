/*
 * @lc app=leetcode.cn id=330 lang=java
 *
 * [330] 按要求补齐数组
 */

// @lc code=start
class Solution {
    public int minPatches(int[] nums, int n) {
        long curMax = 0;
        int cnt = 0, idx = 0;
        while (curMax < n) {
            long nextMax = curMax + 1;
            if (idx < nums.length && nums[idx] <= nextMax) {
                // 若数组能组成的数字范围是[1, curMax]，则加上nums[index]
                // 就变成了[1, curMax] U [nums[idx], curMax + nums[idx]]
                // 结果就是[1, curMax + nums[idx]]
                curMax += nums[idx++];
            } else {
                // 添加一个新数字
                curMax += nextMax;
                ++cnt;
            }
        }
        return cnt;
    }
}
// @lc code=end

