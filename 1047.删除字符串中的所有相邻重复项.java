/*
 * @lc app=leetcode.cn id=1047 lang=java
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
    // similar idea to parenthesis valication
    // public String removeDuplicates(String S) {
    //     StringBuffer stack = new StringBuffer();
    //     int top = -1;
    //     for (int i = 0; i < S.length(); ++i) {
    //         char c = S.charAt(i);
    //         if (top >= 0 && stack.charAt(top) == c) {
    //             stack.deleteCharAt(top);
    //             --top;
    //         } else {
    //             stack.append(c);
    //             ++top;
    //         }
    //     }
    //     return stack.toString();
    // }

    // a slightly optimzed version with inplace operations
    public String removeDuplicates(String S) {
        char[] s = S.toCharArray();
        int top = -1;
        for (int i = 0; i < S.length(); ++i) {
            if (top == -1 || s[top] != s[i]) {
                s[++top] = s[i];
            } else {
                --top;
            }
        }
        return String.valueOf(s, 0, top + 1);
    }
}
// @lc code=end

