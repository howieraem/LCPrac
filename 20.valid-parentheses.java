/*
 * @lc app=leetcode id=20 lang=java
 *
 * [20] Valid Parentheses
 */
import java.util.Stack;

// @lc code=start
class Solution {
    // T: O(n)
    // S: O(n)
    public boolean isValid(String s) {
        Stack<Character> stk = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if (stk.isEmpty()) return false;
                if (c == ')' && stk.peek() != '(') return false;
                if (c == ']' && stk.peek() != '[') return false;
                if (c == '}' && stk.peek() != '{') return false;
                stk.pop();
            }
        }
        return stk.isEmpty();
    }
}
// @lc code=end

