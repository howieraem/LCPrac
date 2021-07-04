/*
 * @lc app=leetcode.cn id=680 lang=java
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
    public boolean validPalindrome(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r && s.charAt(l) == s.charAt(r)) {
            // skip the same characters on either side
            ++l;
            --r;
        }
        // try skiping one character on either side and verify
        return isPalindrome(s, l, r - 1) || isPalindrome(s, l + 1, r);
    }

    private boolean isPalindrome(String s, int l, int r) {
        while (l < r && s.charAt(l) == s.charAt(r)) {
            ++l;
            --r;
        }
        return l >= r;
    }
}
// @lc code=end

