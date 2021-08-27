/*
 * @lc app=leetcode.cn id=977 lang=java
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length, l = 0, r = n - 1, p = n - 1;
        int[] res = new int[n];
        while (l < r) {
            if (Math.abs(nums[l]) > Math.abs(nums[r])) {
                res[p--] = nums[l] * nums[l];
                ++l;
            } else {
                res[p--] = nums[r] * nums[r];
                --r;
            }
        }
        // Don't forget the middle one if n is odd
        if (l == r) {
            res[p--] = nums[l] * nums[l];
        }
        return res;
    }
}
// @lc code=end

