/*
 * @lc app=leetcode.cn id=1249 lang=java
 *
 * [1249] 移除无效的括号
 */
import java.util.Stack;

// @lc code=start
class Solution {
    // T: O(n)
    // S: O(n)
    public String minRemoveToMakeValid(String s) {
        StringBuilder sb = new StringBuilder();
        Stack<Integer> stk = new Stack<>();
        int n = s.length();
        boolean[] removeMask = new boolean[n];

        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (c == '(') {
                stk.push(i);
                removeMask[i] = true;
            } else if (c == ')') {
                if (stk.isEmpty())  removeMask[i] = true;
                else  removeMask[stk.pop()] = false;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!removeMask[i])  sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}
// @lc code=end

