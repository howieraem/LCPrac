/*
 * @lc app=leetcode.cn id=396 lang=java
 *
 * [396] 旋转函数
 */

// @lc code=start
class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length, cur = 0, sum = 0;

        for (int i = 0; i < n; ++i) {
            cur += nums[i] * i;
            sum += nums[i];
        }

        int ans = cur;
        // iterate reversely for "anticlockwise rotation"
        for (int i = n - 1; i > 0; --i) {
            cur += sum;
            cur -= nums[i] * n; // previous last term in F(x)
            ans = Math.max(ans, cur);
        }
        return ans;
    }
}
// @lc code=end

