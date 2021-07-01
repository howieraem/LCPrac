/*
 * @lc app=leetcode.cn id=1249 lang=java
 *
 * [1249] 移除无效的括号
 */
import java.util.Stack;

// @lc code=start
class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder sb = new StringBuilder();
        Stack<Integer> stk = new Stack<>();
        int n = s.length();
        boolean[] pendingMask = new boolean[n];

        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (c == '(') {
                stk.push(i);
                pendingMask[i] = true;
            } else if (c == ')') {
                if (stk.isEmpty())  pendingMask[i] = true;
                else  pendingMask[stk.pop()] = false;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!pendingMask[i])  sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}
// @lc code=end

