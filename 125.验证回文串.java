/*
 * @lc app=leetcode.cn id=125 lang=java
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(String s) {
        StringBuffer sn = new StringBuffer();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (Character.isLetterOrDigit(c)) {
                sn.append(Character.toLowerCase(c));
            }
        }
        int left = 0, right = sn.length() - 1;
        while (left < right) {
            if (sn.charAt(left) != sn.charAt(right))  return false;
            ++left;
            --right;
        }
        return true;
    }
}
// @lc code=end

