/*
 * @lc app=leetcode.cn id=953 lang=java
 *
 * [953] 验证外星语词典
 */

// @lc code=start
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] idx = new int[26];
        for (int i = 0; i < order.length(); ++i) {
            idx[order.charAt(i) - 'a'] = i;
        }

        for (int i = 1; i < words.length; ++i) {
            String w1 = words[i - 1], w2 = words[i];
            boolean needComparing = true;
            for (int j = 0; j < Math.min(w1.length(), w2.length()) && needComparing; ++j) {
                char c1 = w1.charAt(j), c2 = w2.charAt(j);
                if (c1 != c2) {
                    if (idx[c1 - 'a'] > idx[c2 - 'a'])  return false;
                    else  needComparing = false;    // stop looping here as w1 < w2 already
                }
            }
            if (needComparing && w1.length() > w2.length()) {
                // If no difference between w1[:w2.length()] and w2,
                // check their lengths
                return false;
            }
        }
        return true;
    }
}
// @lc code=end

