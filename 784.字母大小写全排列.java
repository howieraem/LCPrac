import java.util.*;
/*
 * @lc app=leetcode.cn id=784 lang=java
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
    List<String> res;
    int n;

    public List<String> letterCasePermutation(String s) {
        res = new ArrayList<>();
        n = s.length();
        char[] a = s.toCharArray();
        dfs(a, 0);
        return res;
    }

    private void dfs(char[] a, int idx) {
        res.add(String.valueOf(a));
        for (int i = idx; i < n; ++i) {
            if (Character.isLetter(a[i])) {
                char c = a[i];
                // Change case
                a[i] = (char) (c - 'a' >= 0 ? a[i] - 32 : a[i] + 32);
                dfs(a, i + 1);
                a[i] = c;
            }
        }
    }
}
// @lc code=end

