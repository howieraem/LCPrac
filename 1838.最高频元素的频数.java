import java.util.*;
/*
 * @lc app=leetcode.cn id=1838 lang=java
 *
 * [1838] 最高频元素的频数
 */

// @lc code=start
class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 0, tmpSum = 0;
        for (int i = 0, j = 0; j < nums.length; ++j) {

            while (nums[j] * (j - i) - tmpSum > k) {
                // Maximum #increments is k, so if the sum of 
                // the current window elements is too large, 
                // shift the left boundary of the window
                tmpSum -= nums[i++];
            }

            // expand window to the right
            tmpSum += nums[j];

            // The answer is the maximum possible size of the window
            // where all elements within are equal
            ans = Math.max(ans, j - i + 1);
        }
        return ans;
    }
}
// @lc code=end

