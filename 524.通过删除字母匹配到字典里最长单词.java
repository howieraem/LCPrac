/*
 * @lc app=leetcode.cn id=524 lang=java
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */
import java.util.List;


// @lc code=start
class Solution {
    public String findLongestWord(String s, List<String> d) {
        String longest = "";
        for (String sub : d) {
            if (isSubseq(sub, s)) {
                if (sub.length() > longest.length() || 
                    (sub.length() == longest.length() && sub.compareTo(longest) < 0)) {
                    longest = sub;
                }
            }
        }
        return longest;
    }

    /** Returns true if string s is a subsequence of string t. */
    private boolean isSubseq(String s, String t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) { 
                ++i; 
            }
            ++j;
        }
        return i == s.length();
    }
}
// @lc code=end

