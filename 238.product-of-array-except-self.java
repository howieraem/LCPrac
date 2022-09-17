/*
 * @lc app=leetcode id=238 lang=java
 *
 * [238] Product of Array Except Self
 */
import java.util.Arrays;

// @lc code=start
class Solution {
    // T: O(n)
    // S: O(1)
    public int[] productExceptSelf(int[] nums) {
        final int n = nums.length;
        int left_product = 1, right_product = 1;
        int[] res = new int[n];
        Arrays.fill(res, 1);

        for (int i = 0; i < n; ++i) {
            res[i] *= left_product;  // product of nums[0:i]
            left_product *= nums[i];
        }

        for (int i = n - 1; i >= 0; --i) {
            res[i] *= right_product;  // product of nums[i + 1:n]
            right_product *= nums[i];
        }
        return res;
    }
}
// @lc code=end

