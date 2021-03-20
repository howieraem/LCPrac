/*
 * @lc app=leetcode.cn id=150 lang=java
 *
 * [150] 逆波兰表达式求值
 */
import java.util.Stack;

// @lc code=start
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> s = new Stack<>();
        int a, b;
        for (String str : tokens) {
            switch (str) {
                case "+":
                    a = s.pop(); 
                    b = s.pop();
                    s.push(b + a);
                    break;
                case "-":
                    a = s.pop(); 
                    b = s.pop();
                    s.push(b - a);
                    break;
                case "*":
                    a = s.pop(); 
                    b = s.pop();
                    s.push(b * a);
                    break;
                case "/":
                    a = s.pop(); 
                    b = s.pop();
                    s.push(b / a);
                    break;
                default:
                    s.push(Integer.valueOf(str));
                    break;
            }
        }
        return s.pop();
    }
}
// @lc code=end

