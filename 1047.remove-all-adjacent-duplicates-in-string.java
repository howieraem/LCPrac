/*
 * @lc app=leetcode id=1047 lang=java
 *
 * [1047] Remove All Adjacent Duplicates In String
 */
import java.util.*;

// @lc code=start
class Solution {
    public String removeDuplicates(String s) {
        /* 
        // Original solution: use an auxillary stack
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() && stack.peek() == c)  stack.pop();
            else  stack.push(c);
        }
        StringBuilder sb = new StringBuilder();
        for (char c : stack)  sb.append(c);
        return sb.toString();
        */

        // Solution without a real stack
        StringBuilder sb = new StringBuilder(s.length());
        for (char c : s.toCharArray()) {
            int n = sb.length();
            // setLength() decrementally is equivalent to pop()
            if (n > 0 && sb.charAt(n - 1) == c)  sb.setLength(n - 1);
            else  sb.append(c);
        }
        return sb.toString();
    }
}
// @lc code=end

