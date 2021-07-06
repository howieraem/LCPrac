/*
 * @lc app=leetcode.cn id=726 lang=java
 *
 * [726] 原子的数量
 */
import java.util.Stack;
import java.util.Map;
import java.util.TreeMap;


// @lc code=start
class Solution {
    public String countOfAtoms(String formula) {
        Stack<Integer> stack = new Stack<>();
        stack.push(1);

        // Use tree map for lexicographical order
        Map<String, Integer> cnts = new TreeMap<>();

        // Iterate from back to front
        String lower = "", cnt = "";
        int i = formula.length() - 1;
        while (i >= 0) {
            char ch = formula.charAt(i);
            if (Character.isDigit(ch)) {
                cnt = ch + cnt;
            } else if (Character.isLowerCase(ch)) {
                lower = ch + lower;
            } else if (ch == ')') {
                stack.push(stack.peek() * (cnt.isBlank() ? 1 : Integer.valueOf(cnt)));
                cnt = "";
            } else if (ch == '(') {
                stack.pop();
            } else {    // if ch is upper case
                String elem = ch + lower;
                cnts.put(elem, 
                         cnts.getOrDefault(elem, 0) + stack.peek() * (cnt.isBlank() ? 1 : Integer.valueOf(cnt)));
                cnt = lower = "";
            }
            --i;
        }

        StringBuilder sb = new StringBuilder();
        for (String elem : cnts.keySet()) {
            sb.append(elem);
            int num = cnts.get(elem);
            if (num > 1)  sb.append(num);
        }
        return sb.toString();
    }
}
// @lc code=end

