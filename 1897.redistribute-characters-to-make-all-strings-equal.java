/*
 * @lc app=leetcode id=1897 lang=java
 *
 * [1897] Redistribute Characters to Make All Strings Equal
 */

// @lc code=start
class Solution {
    // Array + Hash Map + Math
    // T: O(n * l + alpha_size), l := avg word length
    // S: O(alpha_size), or O(alpha_size + l) due to `toCharArray()`
    public boolean makeEqual(String[] words) {
        if (words.length == 1) {
            return true;
        }

        int totalCharCnt = 0;
        for (String s : words) {
            totalCharCnt += s.length();
        }
        if (totalCharCnt % words.length != 0) {
            return false;
        }

        int[] charFreqs = new int[26];
        for (String s : words) {
            for (char c : s.toCharArray()) {
                ++charFreqs[c - 'a'];
            }
        }
        for (int freq : charFreqs) {
            if (freq % words.length != 0) {
                return false;
            }
        }

        return true;
    }
}
// @lc code=end

