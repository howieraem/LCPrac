/*
 * @lc app=leetcode.cn id=214 lang=java
 *
 * [214] 最短回文串
 */

// @lc code=start
class Solution {
    public String shortestPalindrome(String s) {
        /* Find the longest palindrome substring, with Manacher Algorithm (linear time complexity) */
        String t = prepare(s);
        // For a sub-palindrome, c is its center and r the number of charaters from c to its right boundary
        int n = t.length(), c = 0, r = 0;

        // p[i] means the maximum length in string `t` from the sub-palindrome's right to center, centered at i
        int[] p = new int[n];
        for (int i = 1; i < n - 1; ++i) {
            if (r > i) {
                p[i] = Math.min(r - i, p[2 * c - i]);   // 2*c - i is the mirror index of i with center c
            } // else  p[i] = 0;  // i should always be <= r

            while (t.charAt(i + 1 + p[i]) == t.charAt(i - 1 - p[i]))  ++p[i];

            // update right
            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }
        }

        int maxLen = 0;
        for (int i = 1; i < n - 1; ++i) {
            int start = (i - p[i]) / 2;     // index of `t` convert to index of `s`
            if (start == 0)  maxLen = Math.max(p[i], maxLen);
        }
        return new StringBuilder(s.substring(maxLen)).reverse() + s;
    }

    private String prepare(String s) {
        int n = s.length();
        if (n == 0)  return "^$";
        StringBuilder sb = new StringBuilder("^");
        for (int i = 0; i < n; ++i) {
            sb.append("#");
            sb.append(s.charAt(i));
        }
        sb.append("#$");
        return sb.toString();
    }
}
// @lc code=end

