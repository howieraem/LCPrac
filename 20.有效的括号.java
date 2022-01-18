/*
 * @lc app=leetcode.cn id=20 lang=java
 *
 * [20] 有效的括号
 */

// @lc code=start
import java.util.*;

class Solution {
    public boolean isValid(String s) {
        final String open = "([{";
        final String close = ")]}";
        Stack<Character> buff = new Stack<>();
        for (char ch : s.toCharArray()) {
            if (open.indexOf(ch) != -1) {
                buff.push(ch);
            } else if (close.indexOf(ch) != -1) {
                if (buff.isEmpty()) {
                    return false;
                }
                char ch2 = (char)buff.pop();
                if (close.indexOf(ch) != open.indexOf(ch2)) {
                    return false;
                }
            }
        }
        return buff.isEmpty();
    }
}

// @lc code=end
