import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=213 lang=java
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
    public int rob(int[] nums) {
        int len = nums.length;
        if (len == 0)  return 0;
        if (len == 1)  return nums[0];
        
        // As we cannot rob both first and last, just pick
        // the larger result of robbing either.
        return Math.max(subRob(Arrays.copyOfRange(nums, 1, len)),       
                        subRob(Arrays.copyOfRange(nums, 0, len-1)));
    }

    /** Code used in question [198]. */
    private int subRob(int[] nums) {
        int i_2 = 0, i_1 = 0, tmp;
        for (int num : nums) {
            tmp = i_1;
            i_1 = Math.max(i_2 + num, i_1);
            i_2 = tmp;
        }
        return i_1;
    }
}
// @lc code=end

