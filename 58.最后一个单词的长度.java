/*
 * @lc app=leetcode.cn id=58 lang=java
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
    public int lengthOfLastWord(String s) {
        /* // API-based approach, not the fastest
        try {
            String[] words = s.split(" ");
            return words[words.length-1].length();
        } catch (Exception e) {
            return 0;
        }
        */
        if (s == null || s.length() == 0) return 0;
        int count = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s.charAt(i) == ' ') {
                if (count == 0)  continue;
                break;
            }
            ++count;
        }
        return count;
    }
}
// @lc code=end

