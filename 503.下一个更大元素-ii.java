import java.util.Stack;

/*
 * @lc app=leetcode.cn id=503 lang=java
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        Stack<Integer> stack = new Stack<>();
        
        // Circular find is required, so "copy" the array and paste to the right
        // by doubling the max iterations and iterating backwards
        for (int i = 2 * n - 1; i >= 0; --i) {
            // Map index back to the range of original array.
            // Each idx will be visited twice.
            int idx = i % n;

            // Mono-stack: stack is ordered and stack top is minimum.
            // When i < n, larger numbers of the "circular" part are
            // already stored in the stack.
            while (!stack.empty() && stack.peek() <= nums[idx]) {
                stack.pop();
            }
            // If there is no next number greater than current number,
            // the stack will be empty.
            res[idx] = stack.empty() ? -1 : stack.peek();
            stack.push(nums[idx]);
        }
        return res;
    }
}
// @lc code=end

