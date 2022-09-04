/*
 * @lc app=leetcode id=772 lang=java
 *
 * [772] Basic Calculator III
 */
import java.util.*;

// @lc code=start
class Solution {
    // T: O(n)
    // S: O(n)
    public int calculate(String s) {
        Stack<Integer> nums = new Stack<>();
        Stack<Character> ops = new Stack<>();
        int num = 0;
        char[] arr = s.toCharArray();
        int i = 0;
        while (i < s.length()) {
            char c = arr[i];
            if (Character.isDigit(c)) {
                num = (c - '0');
                while (i + 1 < s.length() && Character.isDigit(arr[i + 1])) {
                    num = num * 10 + (arr[++i] - '0');
                }
                nums.push(num);
                num = 0;
            } else if (c == '(') {
                ops.push(c);
            } else if (c == ')') {
                // Do the math when encounter a ')', until '(' is reached in ops stack
                while (ops.peek() != '(') {
                    nums.push(applyOp(ops.pop(), nums.pop(), nums.pop()));
                }
                ops.pop();  // get rid of the corresponding '('
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                while (!ops.isEmpty() && ops.peek() != '(' && hasPrecedence(ops.peek(), c)) {
                    nums.push(applyOp(ops.pop(), nums.pop(), nums.pop()));
                }
                
                /*
                // Dealing with negative numbers: add a zero to nums stack as -x is the same as 0 - x
                if (c == '-') {
                    if (nums.isEmpty()) {
                        // case 1: 1st non-empty char belongs to a negative number 
                        nums.push(0);
                    } else {
                        // case 2: 1st nonempty char in parentheses belongs to a negative number 
                        int j = i - 1;
                        while (j >= 0 && arr[j] == ' ') {
                            --j;
                        }
                        if (arr[j] == '(') {
                            nums.push(0);
                        }
                    }
                }
                */

                ops.push(c);
            }
            ++i;
        }

        while (!ops.isEmpty()) {
            nums.push(applyOp(ops.pop(), nums.pop(), nums.pop()));
        }
        return nums.pop();
    }

    private static int applyOp(char op, int a, int b) {
        switch (op) {
            case '+': return b + a;
            case '-': return b - a;
            case '*': return b * a;
            case '/': return b / a; // assume b is not 0
            default: return 0;
        }
    }

    // Helper function to check precedence of the uppermost operator in the ops stack and current operator
    private static boolean hasPrecedence(char stack_top, char cur) {
        return !((stack_top == '+' || stack_top == '-') && (cur == '*' || cur == '/'));
    }
}
// @lc code=end

