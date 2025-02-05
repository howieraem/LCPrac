/*
 * @lc app=leetcode id=1984 lang=java
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 */
import java.util.Arrays;

// @lc code=start
class Solution {
    // Sorting + two pointers + sliding window
    // T: O(n * log(n))
    // S: O(sorting)
    public int minimumDifference(int[] nums, int k) {
        if (k <= 1) {
            return 0;
        }

        Arrays.sort(nums);

        int ans = Integer.MAX_VALUE;

        // After sorting, the minimum and the maximum are just the left 
        // and the right boundaries of a size-k sliding window.
        // Find the minimum difference of all size-k sliding windows.
        for (int i = k - 1; i < nums.length; ++i) {
            ans = Math.min(ans, nums[i] - nums[i - k + 1]);
        }

        return ans;
    }
}
// @lc code=end

