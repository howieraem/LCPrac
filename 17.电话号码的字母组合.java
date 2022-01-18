import java.util.*;
/*
 * @lc app=leetcode.cn id=17 lang=java
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
    private static final char[][] MAP = new char[][]{
        {},     // digit 0
        {},     // digit 1
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'},
    };  // MAP contains placeholders for digits 0 and 1 so that in dfs there is no need to minus 2

    // T: O(4 ^ n) as there are at most 4 characters for one digit
    // S: O(n) recursion stack
    public List<String> letterCombinations(String digits) {
        final int n = digits.length();
        if (n == 0)  return new ArrayList<>();
        char[] ds = digits.toCharArray();
        char[] comb = new char[n];
        List<String> res = new ArrayList<>();
        dfs(ds, comb, 0, res);
        return res;
    }

    private static void dfs(char[] ds, char[] comb, int idx, List<String> res) {
        if (idx == ds.length) {
            res.add(String.valueOf(comb));
            return;
        }

        for (char c : MAP[ds[idx] - '0']) {
            comb[idx] = c;
            dfs(ds, comb, idx + 1, res);
        }
    }
}
// @lc code=end

