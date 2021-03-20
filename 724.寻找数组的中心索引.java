/*
 * @lc app=leetcode.cn id=724 lang=java
 *
 * [724] 寻找数组的中心索引
 */

// @lc code=start
class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0, leftSum = 0;
        for (int num:nums) {
            sum += num;
        }
        int cur;
        for (int i = 0; i < nums.length; ++i) {
            cur = nums[i];
            if (leftSum == (sum - leftSum - cur)) {
                return i;
            }
            leftSum += cur;
        }
        return -1;
    }
}
// @lc code=end

