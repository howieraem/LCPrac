/*
 * @lc app=leetcode id=224 lang=java
 *
 * [224] Basic Calculator
 */
import java.util.*;

// @lc code=start
class Solution {
    // Iterative solution with stack
    // T: O(n)
    // S: O(n)
    public int calculate(String s) {
        int sign = 1, num = 0;
        Stack<Integer> stk = new Stack<>();
        stk.push(sign);
        int ans = 0;

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                ans += sign * num;
                sign = stk.peek() * (c == '+' ? 1 : -1);
                num = 0;
            } else if (c == '(') {
                stk.push(sign);
            } else if (c == ')') {
                stk.pop();
            }
        }
        // don't forget the last one
        ans += sign * num;
        return ans;
    }
}
// @lc code=end

