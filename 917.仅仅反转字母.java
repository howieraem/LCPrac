/*
 * @lc app=leetcode.cn id=917 lang=java
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
    public String reverseOnlyLetters(String s) {
        char[] a = s.toCharArray();
        int l = 0, r = s.length() - 1;
        while (l < r) {
            while (l < r && !Character.isLetter(a[l]))  ++l;
            while (l < r && !Character.isLetter(a[r]))  --r;
            if (l < r) {
                a[l] ^= a[r];
                a[r] ^= a[l];
                a[l] ^= a[r];
                ++l;
                --r;
            }
        }
        return String.valueOf(a);
    }
}
// @lc code=end

