import java.util.Stack;

/*
 * @lc app=leetcode.cn id=503 lang=java
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        // use i % n to iterate circular array
        int n = nums.length;
        int[] res = new int[n];
        Stack<Integer> s = new Stack<>();
        for (int i = 2*n - 1; i >= 0; --i) {
            int idx = i % n;
            while (!s.empty() && s.peek() <= nums[idx]) {
                s.pop();
            }
            res[idx] = s.empty() ? -1 : s.peek();
            s.push(nums[idx]);
        }
        return res;
    }
}
// @lc code=end

