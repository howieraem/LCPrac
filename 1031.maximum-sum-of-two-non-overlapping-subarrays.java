/*
 * @lc app=leetcode id=1031 lang=java
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start
class Solution {
    // Sliding window + 1D DP
    // T: O(n)
    // S: O(1)
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        return Math.max(
                maxSumHelper(nums, firstLen, secondLen), 
                maxSumHelper(nums, secondLen, firstLen));
    }

    private static int maxSumHelper(int[] nums, int leftLen, int rightLen) {
        int sumLeft = 0;
        int sumRight = 0;

        // compute the first windows
        for (int i = 0; i < leftLen + rightLen; ++i) {
            if (i < leftLen) {
                sumLeft += nums[i];
            } else {
                sumRight += nums[i];
            }
        }
        int ans = sumLeft + sumRight;

        int maxSumLeft = sumLeft;
        for (int i = leftLen + rightLen; i < nums.length; ++i) {
            sumLeft += nums[i - rightLen] - nums[i - leftLen - rightLen];
            sumRight += nums[i] - nums[i - rightLen];
            maxSumLeft = Math.max(maxSumLeft, sumLeft);
            // we do not have a `maxSumRight` to ensure the two subarrays don't overlap
            ans = Math.max(ans, maxSumLeft + sumRight);
        }
        return ans;
    }
}
// @lc code=end

