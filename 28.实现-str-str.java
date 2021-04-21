/*
 * @lc app=leetcode.cn id=28 lang=java
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
    public int strStr(String haystack, String needle) {
        int m = needle.length();
        if (m == 0)  return 0;
        int n = haystack.length();

        // failure function
        int[] f = new int[m];
        int i = 1, j = 0;
        while (i < m) {
            if (needle.charAt(i) == needle.charAt(j)) {
                f[i++] = ++j;
            } else if (j > 0) {
                j = f[j - 1];
            } else {
                ++i;
            }
        }

        // KMP
        i = j = 0;
        while (i < n) {
            if (haystack.charAt(i) == needle.charAt(j)) {
                if (j == m - 1) {
                    return i - j;
                } else {
                    ++i; ++j;
                }
            } else {
                if (j > 0) {
                    j = f[j - 1];
                } else {
                    ++i;
                }
            }
        }
        
        return -1;
    }
}
// @lc code=end

