/*
 * @lc app=leetcode.cn id=131 lang=java
 *
 * [131] 分割回文串
 */
import java.util.ArrayList;
import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;

// @lc code=start
class Solution {
    private List<List<String>> res;
    private int n;
    private boolean[][] dp;
    private String string;

    public List<List<String>> partition(String s) {
        res = new ArrayList<>();
        string = s;
        n = s.length();
        if (n == 0)  return res;

        dp = new boolean[n][n];
        for (int r = 0; r < n; ++r) {
            for (int l = 0; l <= r; ++l) {
                if (
                    s.charAt(r) == s.charAt(l) && (r - l <= 2 || dp[l+1][r-1])
                ) {
                    dp[l][r] = true;
                }
            }
        }

        backtrack(new ArrayDeque<>(), 0);
        return res;
    }

    private void backtrack(Deque<String> collections, int l) {
        if (l == n) {
            res.add(new ArrayList<>(collections));
            return;
        }

        for (int r = l; r < n; ++r) {
            if (dp[l][r]) {
                collections.addLast(string.substring(l, r + 1));
                backtrack(collections, r + 1);
                collections.removeLast();
            }
        }
    }
}
// @lc code=end
