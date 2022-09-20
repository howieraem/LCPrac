/*
 * @lc app=leetcode id=84 lang=java
 *
 * [84] Largest Rectangle in Histogram
 */
import java.util.Stack;

// @lc code=start
class Solution {
    // Mono-stack
    // T: O(n)
    // S: O(n)
    public int largestRectangleArea(int[] heights) {
        final int n = heights.length;
        Stack<Integer> stack = new Stack<>();  // stores indices of ascending heights
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            // IMPORTANT: Add a dummy zero height to simplify the code to 
            // check the heights/indices remaining in stack at the end
            int h = i != n ? heights[i] : 0;
            while (!stack.empty() && heights[stack.peek()] > h) {
                int preH = heights[stack.pop()];
                int preIdx = stack.empty() ? -1 : stack.peek();  // IMPORTANT: handle edge cases
                
                // For any bar i, if it's in a rectangle of which the height is also the height of i, 
                // we know that every bar in the rectangle must be no shorter than bar i. Then the goal 
                // is to find the left and right boundary where the bars are shorter than bar i.
                // When a bar is popped out from the stack, we know it must be higher than the bar at position i, 
                // so bar[i] must be the right boundary (exclusive) of the rectangle, and the previous bar in the 
                // stack is the first one that is shorter than the popped one so it must be the left boundary 
                // (also exclusive). Then we find the rectangle's area and update the result.
                ans = Math.max(ans, preH * (i - preIdx - 1));
            }
            stack.push(i);
        }
        return ans;
    }
}
// @lc code=end

