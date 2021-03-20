/*
 * @lc app=leetcode.cn id=31 lang=java
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
    public void nextPermutation(int[] nums) {
        int i = nums.length - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])  --i;  // find the smaller digit
        if (i >= 0) {
            int j = nums.length - 1;
            while (j >= 0 && nums[i] >= nums[j])  --j;  // find the larger digit
            swap(nums, i, j);   // swap the digits
        }
        reverse(nums, i + 1);   // ensure nums[i+1:n] is ascending
    }

    private static void swap(int[] nums, int i, int j) {
        int tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
    }

    private static void reverse(int[] nums, int begin) {
        int l = begin, r = nums.length - 1;
        while (l < r) {
            swap(nums, l, r);
            ++l;
            --r;
        }
    }
}
// @lc code=end

