/*
 * @lc app=leetcode.cn id=5 lang=java
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
    /** 动态规划法 */
    /*
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int begin = 0, maxLen = 1;

        for (int right = 0; right < n; ++right) {
            for (int left = 0; left <= right; ++left) {
                if ((s.charAt(right) == s.charAt(left)) && ((right - left <= 2) || dp[left+1][right-1])) {
                    dp[left][right] = true;
                    if (right - left + 1 > maxLen) {
                        begin = left;
                        maxLen = right - left + 1;
                    }
                }
            }
        }
        return s.substring(begin, begin + maxLen);
    }
    */

    /** 中心扩散法 */
    private int start, maxLen;

    public String longestPalindrome(String s) {
        start = 0;
        maxLen = 1;
        for (int i = 0; i < s.length(); ++i) {
            findPalindromeIndices(s, i, i);     // palindrome length is odd
            findPalindromeIndices(s, i, i+1);   // palindrome length is even
        }
        return s.substring(start, start + maxLen);
    }

    private void findPalindromeIndices(String s, int l, int r) {
        while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            --l; ++r;
        }
        if (r - 1 - l > maxLen) {
            // Note the while condition, start = l + 1 and end = r - 1
            start = l + 1;  
            maxLen = r - 1 - l;
        }
    }
}
// @lc code=end

