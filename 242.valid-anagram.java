/*
 * @lc app=leetcode id=242 lang=java
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
    // T: O(n)
    // S: O(s)
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] cnts = new int[26];
        char[] sa = s.toCharArray(), ta = t.toCharArray();
        for (int i = 0; i < s.length(); ++i) {
            ++cnts[sa[i] - 'a'];
            --cnts[ta[i] - 'a'];
        }

        for (int cnt : cnts) {
            if (cnt != 0) return false;
        }
        return true;
    }
}
// @lc code=end

