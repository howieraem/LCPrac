import java.util.*;
/*
 * @lc app=leetcode.cn id=17 lang=java
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
    private static final char[][] MAP = new char[][]{
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'},
    };

    public List<String> letterCombinations(String digits) {
        int n = digits.length();
        if (n == 0)  return new ArrayList<>();
        char[] ds = digits.toCharArray();
        char[] comb = new char[n];
        List<String> res = new ArrayList<>();
        dfs(ds, comb, 0, n, res);
        return res;
    }

    private static void dfs(char[] ds, char[] comb, int idx, int n, List<String> res) {
        if (idx == n) {
            res.add(String.valueOf(comb));
            return;
        }
        for (char c : MAP[ds[idx] - '0' - 2]) {
            comb[idx] = c;
            dfs(ds, comb, idx + 1, n, res);
        }
    }
}
// @lc code=end

