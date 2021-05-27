import java.util.Stack;

/*
 * @lc app=leetcode.cn id=1190 lang=java
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
class Solution {
    public String reverseParentheses(String s) {
        char[] arr = s.toCharArray();
        Stack<Integer> stack = new Stack<>();

        // 每匹配一对括号，就将括号内的字符串翻转
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] == '(') {
                stack.push(i);
            } else if (arr[i] == ')') {
                // 注意：翻转时不包括左右边界的括号符
                reverse(arr, stack.pop() + 1, i - 1);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] != '(' && arr[i] != ')') {
                sb.append(arr[i]);
            }
        }
        return sb.toString();
    }

    private void reverse(char[] arr, int l, int r) {
        char tmp;
        while (l < r) {
            tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            ++l;
            --r;
        }
    }
}
// @lc code=end

