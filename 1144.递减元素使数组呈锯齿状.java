/*
 * @lc app=leetcode.cn id=1144 lang=java
 *
 * [1144] 递减元素使数组呈锯齿状
 */

// @lc code=start
class Solution {
    public int movesToMakeZigzag(int[] nums) {
        int n = nums.length, ansOdd = 0, ansEven = 0;
        for (int i = 0; i < n; ++i) {
            // Subtract max(d1, d2) from nums[i] so that it is 
            // less than both nums[i - 1] and nums[i + 1]
            if ((i & 1) == 0) {
                int d1 = i > 0 && nums[i] >= nums[i - 1] ? nums[i] - nums[i - 1] + 1 : 0;
                int d2 = i < n - 1 && nums[i] >= nums[i + 1] ? nums[i] - nums[i + 1] + 1 : 0;
                ansOdd += Math.max(d1, d2); 
            } else {
                int d1 = nums[i] >= nums[i - 1] ? nums[i] - nums[i - 1] + 1 : 0;
                int d2 = i < n - 1 && nums[i] >= nums[i + 1] ? nums[i] - nums[i + 1] + 1 : 0;
                ansEven += Math.max(d1, d2);
            }
        }
        return Math.min(ansOdd, ansEven);
    }
}
// @lc code=end

