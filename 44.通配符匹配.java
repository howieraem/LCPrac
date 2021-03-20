import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=44 lang=java
 *
 * [44] 通配符匹配
 */
import java.util.*;

// @lc code=start
class Solution {
    public boolean isMatch(String s, String p) {
        int ls = s.length(), lp = p.length();
        boolean[][] dp = new boolean[lp+1][ls+1];   // add one to consider the base case of empty string
        dp[0][0] = true;
        if (p.startsWith("*")) {
            Arrays.fill(dp[1], true);
        }

        for (int i = 1; i <= lp; ++i) {
            boolean path = false;
            for (int j = 1; j <= ls; ++j) {
                char pc = p.charAt(i-1);
                if (pc == '*') {
                    // any character
                    if (dp[i-1][0] == true)
                        Arrays.fill(dp[i], true);
                    if (dp[i-1][j] == true)
                        path = true;
                    if (path == true)
                        dp[i][j] = true;
                } else if (pc == '?' || pc == s.charAt(j-1)) {
                    // singleton character matching
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[lp][ls];
    }
}
// @lc code=end

