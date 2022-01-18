/*
 * @lc app=leetcode.cn id=227 lang=java
 *
 * [227] 基本计算器 II
 */
import java.util.LinkedList;

// @lc code=start
class Solution {
    public int calculate(String s) {
        LinkedList<Character> str = new LinkedList<>();
        for (int i = 0; i < s.length(); ++i) {
            str.add(s.charAt(i));
        }

        char sign = '+';
        int num = 0;
        LinkedList<Integer> nums = new LinkedList<>();

        while (!str.isEmpty()) {
            char c = str.pollFirst();
            if (Character.isDigit(c)) {
                num = 10 * num + (int) (c - '0');
            }

            if ((!Character.isDigit(c) && c != ' ') || str.isEmpty()) {
                // character denotes an operator, or has reached the end of expression
                int inter;
                switch (sign) {
                    case '+':
                        nums.addLast(num);
                        break;
                    case '-':
                        nums.addLast(-num);
                        break;
                    case '*':
                        inter = nums.pollLast();
                        nums.addLast(inter * num);
                        break;
                    case '/':
                        inter = nums.pollLast();
                        nums.addLast(inter / num);
                        break;
                }
                num = 0;
                sign = c;
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

