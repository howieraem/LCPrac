/*
 * @lc app=leetcode.cn id=303 lang=java
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
    private int[] psums;

    public NumArray(int[] nums) {
        final int n = nums.length;
        psums = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            psums[i + 1] = psums[i] + nums[i];
        }
    }
    
    public int sumRange(int left, int right) {
        return psums[right + 1] - psums[left];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
// @lc code=end

