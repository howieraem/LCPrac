/*
 * @lc app=leetcode.cn id=1048 lang=java
 *
 * [1048] 最长字符串链
 */
import java.util.Arrays;

// @lc code=start
class Solution {
    public int longestStrChain(String[] words) {
        // Sort words by length
        Arrays.sort(words, (w1, w2) -> w1.length() - w2.length());

        int n = words.length;
        int[] dp = new int[n];
        // Arrays.fill(dp, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (checkPre(words[i], words[j])) {
                    dp[j] = Math.max(dp[j], dp[i] + 1);
                }
            }
        }
        // return Arrays.stream(dp).max().getAsInt();
        return Arrays.stream(dp).max().getAsInt() + 1;
    }

    private boolean checkPre(String pre, String cur) {
        if (cur.length() - pre.length() != 1)  return false;
        int diffs = 0, i = 0, j = 0;
        while (i < pre.length() && j < cur.length()) {
            if (pre.charAt(i) == cur.charAt(j)) {
                ++i;
                ++j;
            } else {
                ++diffs;
                if (diffs > 1)  return false;
                ++j;
            }
        }
        return true;
    }
}
// @lc code=end

