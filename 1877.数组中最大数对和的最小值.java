import java.util.Arrays;
/*
 * @lc app=leetcode.cn id=1877 lang=java
 *
 * [1877] 数组中最大数对和的最小值
 */

// @lc code=start
class Solution {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);

        int l = 0, r = nums.length - 1;
        int ans = -1;
        while (l < r) {
            ans = Math.max(ans, nums[l] + nums[r]);
            ++l;
            --r;
        }
        return ans;
    }
}
// @lc code=end

