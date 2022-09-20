/*
 * @lc app=leetcode id=739 lang=java
 *
 * [739] Daily Temperatures
 */
import java.util.Stack;

// @lc code=start
class Solution {
    // Mono-stack
    // T: O(n)
    // S: O(n)
    public int[] dailyTemperatures(int[] temperatures) {
        final int n = temperatures.length;

        Stack<Integer> stk = new Stack<>();
        int[] res = new int[n];

        // Iterate forward
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && temperatures[stk.peek()] < temperatures[i]) {
                // if temperatures[stk.peek()] == temperatures[i], we leave res[stk.pop()] = 0 (default initialization value for Java int)
                int prev_high_day = stk.pop();
                res[prev_high_day] = i - prev_high_day;
            }
            stk.push(i);
        }

        /*
        // Iterate backward
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && temperatures[stk.peek()] <= temperatures[i]) {  // temperature strictly higher, so `<=`
                stk.pop();
            }

            res[i] = stk.empty() ? 0 : stk.peek() - i;
            stk.push(i);
        }
        */

        return res;
    }
}
// @lc code=end

