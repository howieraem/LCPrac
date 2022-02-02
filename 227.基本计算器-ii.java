/*
 * @lc app=leetcode.cn id=227 lang=java
 *
 * [227] 基本计算器 II
 */
import java.util.Stack;

// @lc code=start
class Solution {
    public int calculate(String s) {
        final int n = s.length();
        char op = '+';
        int num = 0, inter;
        Stack<Integer> nums = new Stack<>();

        char[] str = s.toCharArray();
        for (int i = 0; i < n; ++i) {
            char c = str[i];
            boolean isDigit = Character.isDigit(c);
            if (isDigit) {
                num = 10 * num + (int) (c - '0');
            }

            if ((!isDigit && c != ' ') || i == n - 1) {
                // character denotes an operator, or has reached the end of expression
                switch (op) {
                    case '+':
                        nums.add(num);
                        break;
                    case '-':
                        nums.add(-num);
                        break;
                    case '*':
                        inter = nums.pop();
                        nums.add(inter * num);
                        break;
                    case '/':
                        inter = nums.pop();
                        nums.add(inter / num);
                        break;
                }
                num = 0;
                op = c;
            }
        }

        int ans = 0;
        for (int x : nums) {
            ans += x;
        }
        return ans;
    }
}
// @lc code=end

