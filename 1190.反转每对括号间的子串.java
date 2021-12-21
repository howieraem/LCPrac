import java.util.Stack;

/*
 * @lc app=leetcode.cn id=1190 lang=java
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
class Solution {
    // T: O(n ^ 2)
    // S: O(n)
    public String reverseParentheses(String s) {
        char[] arr = s.toCharArray();
        Stack<Integer> stack = new Stack<>();

        // Once a pair of parenthese is found, reverse the string in between
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] == '(') {
                stack.push(i);
            } else if (arr[i] == ')') {
                // When reversing don't include the parethese
                reverse(arr, stack.pop() + 1, i - 1);
            }
        }

        // Iteratate through the reverted string skipping the parenthese
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

