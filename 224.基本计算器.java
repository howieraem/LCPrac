/*
 * @lc app=leetcode.cn id=224 lang=java
 *
 * [224] 基本计算器
 */
import java.util.ArrayList;
import java.util.LinkedList;

// @lc code=start
class Solution {
    public int calculate(String s) {
        LinkedList<Character> sl = new LinkedList<>();
        for (int i = 0; i < s.length(); ++i) {
            sl.add(s.charAt(i));
        }
        return helper(sl);
    }

    private int helper(LinkedList<Character> s) {
        ArrayList<Integer> nums = new ArrayList<>();
        char sign = '+';
        int num = 0;

        while (!s.isEmpty()) {
            char c = s.pollFirst();
            if (Character.isDigit(c)) {
                num = 10 * num + (int) (c - '0');
            }

            if (c == '(') {
                num = helper(s);
            }

            if ((!Character.isDigit(c) && c != ' ') || s.size() == 0) {
                if (sign == '+') {
                    nums.add(num);
                } else {
                    nums.add(-num);
                }
                num = 0;
                sign = c;
            }

            if (c == ')')  break;
        }

        int sum = 0;
        for (int item : nums) {
            sum += item;
        }
        return sum;
    }
}
// @lc code=end

