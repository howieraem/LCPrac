/*
 * @lc app=leetcode.cn id=456 lang=java
 *
 * [456] 132模式
 */
import java.util.Arrays;
import java.util.Stack;

// @lc code=start
class Solution {
    public boolean find132pattern(int[] nums) {
        // find i, j, k, such that i < j < k && nums[i] < nums[k] < nums[j]
        int n = nums.length;
        Stack<Integer> s = new Stack<>();
        int numK = Integer.MIN_VALUE;
        for (int i = n - 1; i >=0; --i) {
            if (nums[i] < numK)  return true;   // numK is the smallest in a non-empty mono stack
            while (!s.isEmpty() && s.peek() < nums[i]) {
                // mono stack
                numK = Math.max(numK, s.pop());
            }
            s.push(nums[i]);
        }
        return false;
    }
}
// @lc code=end

